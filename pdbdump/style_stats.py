"""style_stats.py - naming-style statistics over pdbdump TSV output.

usage: python -I style_stats.py <dumpdir> [label]

Prints Markdown sections (parameter/field/local/static/global prefixes, function-name case,
enum conventions, object/source naming) split by code family. A family comes from the
function's source path (see PATH_RULES); UDTs and functions without lines inherit the majority
family of their class's functions, then fall back to NAME_RULES on the class name.
"""
import os
import re
import sys
from collections import Counter, defaultdict

PATH_RULES = [  # (family, regex on lower-cased source path); first match wins
    ("gamebryo", r"\\gamebryo[^\\]*\\"),
    ("bethesda_game", r"\\code\\fallout\\|\\fallout shared\\|\\gamesln\\(game|shared)\\"),
    ("bethesda_engine", r"\\code\\bs|\\gamesln\\bs"),
    ("havok", r"\\havok\\|\\build\\\d{8}_|\\clients\\bethesda\\|\\nightlyjobs\\"),
    ("scaleform", r"scaleform"),
    ("sdk_crt", r"xenon|xbox 360 sdk|microsoft visual studio|windows kits|\\vc\\|\\crt\\|\\gamesln\\include\\"),
]
NAME_RULES = [
    ("havok", r"^hk"),
    ("gamebryo", r"^Ni[A-Z]"),
    ("bethesda_engine", r"^(BS|bhk|NiBS)"),
    ("bethesda_game", r"^(TES|BGS|Actor|Script|Extra|Player|Character|Creature|Combat|Menu|.*Menu$|Interface|HUD|VATS)"),
    ("sdk_crt", r"^(_|std::|D3D|X[A-Z]|IDirect|__|[A-Z0-9_]+$)"),
]
CLASS_GROUPS = [  # by the first component of a member function's qualified name
    ("TES*", r"^TES"), ("BGS*", r"^BGS"), ("bhk*", r"^bhk"), ("BS*", r"^BS"), ("Actor*/Character/Player*", r"^(Actor|Character|Player|Creature)"),
    ("Script*", r"^Script"), ("*Menu", r"Menu$"), ("Extra*", r"^Extra"), ("Ni*", r"^Ni[A-Z]"), ("hk*", r"^hk"),
]
FAMILIES = ["bethesda_game", "bethesda_engine", "gamebryo", "havok", "scaleform", "sdk_crt", "other"]

TYPE_TOK = r"(?:ppk|pk|pp|psz|ps|rk|rp|sp|ui|us|uc|ul|ull|sz|pc|dw|p|r|k|f|i|b|c|e|s|h|l|d|w|v|u|n|q|t|x)"
RE_A = re.compile(r"^a(" + TYPE_TOK + r"?)(?=[A-Z0-9_])")
RE_T = re.compile(r"^(" + TYPE_TOK + r")(?=[A-Z0-9])")
RE_LOWRUN = re.compile(r"^([a-z]+)(?=[A-Z0-9_])")


def path_family(p):
    p = p.lower()
    for fam, rx in PATH_RULES:
        if re.search(rx, p):
            return fam
    return "other" if p else None


def name_family(n):
    for fam, rx in NAME_RULES:
        if re.search(rx, n):
            return fam
    return "other"


def tsv(path):
    with open(path, encoding="utf-8", errors="replace") as f:
        hdr = f.readline().rstrip("\n").split("\t")
        for line in f:
            row = line.rstrip("\n").split("\t")
            row += [""] * (len(hdr) - len(row))
            yield dict(zip(hdr, row))


def classify(name):
    """(category, prefix) for an identifier."""
    if not name:
        return "empty", ""
    if name == "__formal" or name.startswith("<"):
        return "unnamed", ""
    if name.startswith("m_"):
        rest = name[2:]
        m = RE_T.match(rest)
        if m:
            return "m_+type", "m_" + m.group(1)
        if rest[:1].isupper():
            return "m_Pascal", "m_"
        return "m_other", "m_" + (RE_LOWRUN.match(rest).group(1) if RE_LOWRUN.match(rest) else "")
    if name[0] == "_":
        return "_leading", "_"
    m = RE_A.match(name)
    if m:
        return "a+type", "a" + m.group(1)
    m = RE_T.match(name)
    if m:
        return "type", m.group(1)
    if re.match(r"^[A-Z0-9_]+$", name) and len(name) > 1:
        return "UPPER", ""
    if name[0].isupper():
        return "Pascal", ""
    if re.match(r"^[a-z0-9]+$", name):
        return "lower", ""
    if re.match(r"^[a-z0-9]+(_[a-z0-9]+)+$", name):
        return "snake", ""
    m = RE_LOWRUN.match(name)
    if m:
        return "camel", m.group(1)
    return "other", ""


def pct(a, b):
    return "%.1f%%" % (100.0 * a / b) if b else "-"


def last_component(q):
    depth, start = 0, 0
    for i, ch in enumerate(q):
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth -= 1
        elif ch == ":" and depth == 0 and i + 1 < len(q) and q[i + 1] == ":":
            start = i + 2
    s = q[start:]
    k = s.find("<")
    return s[:k] if k > 0 else s


def first_component(q):
    depth = 0
    for i, ch in enumerate(q):
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth -= 1
        elif ch == ":" and depth == 0:
            return q[:i]
    return q


def strip_tmpl(n):
    k = n.find("<")
    return n[:k] if k > 0 else n


def main():
    d = sys.argv[1]
    label = sys.argv[2] if len(sys.argv) > 2 else os.path.basename(d)
    out = []
    P = out.append

    # ---- functions: family per function and per class
    fam_of_func = {}          # (rva, name) -> family
    class_votes = defaultdict(Counter)
    funcs = []
    nfunc = nsrc = 0
    src_examples = []
    obj_sources = defaultdict(Counter)
    obj_paths = set()
    for r in tsv(os.path.join(d, "functions.tsv")):
        nfunc += 1
        fam = path_family(r["source_file"]) if r["source_file"] else None
        if r["source_file"]:
            nsrc += 1
            if len(src_examples) < 400 and nfunc % 97 == 0:
                src_examples.append(r["source_file"])
            if re.search(r"\.(cpp|c|cc|cxx)$", r["source_file"], re.I):
                obj_sources[r["object_path"]][r["source_file"]] += 1
        obj_paths.add(r["object_path"])
        cls = r["class"] or (first_component(r["name"]) if "::" in r["name"] else "")
        if fam and cls:
            class_votes[strip_tmpl(cls)][fam] += 1
        funcs.append((r["rva"], r["name"], fam, cls))
    class_fam = {c: v.most_common(1)[0][0] for c, v in class_votes.items()}

    def fam_for_class(c):
        c0 = strip_tmpl(c)
        if c0 in class_fam:
            return class_fam[c0]
        outer = first_component(c0)
        if outer in class_fam:
            return class_fam[outer]
        return name_family(c0)

    for rva, name, fam, cls in funcs:
        if fam is None:
            fam = fam_for_class(cls) if cls else name_family(name)
        fam_of_func[(rva, name)] = fam

    fcount = Counter(fam_of_func.values())
    P("### %s: families" % label)
    P("")
    P("functions %d, with line info %d (%s). Functions per family: %s." % (
        nfunc, nsrc, pct(nsrc, nfunc), ", ".join("%s %d" % (f, fcount[f]) for f in FAMILIES if fcount[f])))
    P("")

    # ---- parameters
    def ident_table(title, rows_by_fam, cats, ntop=8):
        P("#### %s" % title)
        P("")
        P("| family | n | " + " | ".join(cats) + " | top prefixes (count) |")
        P("|---|---|" + "---|" * len(cats) + "---|")
        for fam in FAMILIES:
            c = rows_by_fam.get(fam)
            if not c:
                continue
            n = sum(c["_n"].values())
            cells = [pct(c["cat"][k], n) for k in cats]
            top = ", ".join("`%s` %d" % (p, k) for p, k in c["pre"].most_common(ntop))
            P("| %s | %d | %s | %s |" % (fam, n, " | ".join(cells), top))
        P("")

    def acc(store, fam, name, examples=None):
        st = store.setdefault(fam, {"cat": Counter(), "pre": Counter(), "_n": Counter(), "ex": Counter()})
        cat, pre = classify(name)
        st["cat"][cat] += 1
        st["_n"]["n"] += 1
        if pre and cat in ("a+type", "type", "m_+type", "m_other", "camel"):
            st["pre"][pre if cat != "camel" else pre + "…"] += 1
        elif cat in ("Pascal", "UPPER", "lower", "snake", "_leading", "m_Pascal"):
            st["pre"]["<" + cat + ">"] += 1
        st["ex"][name] += 1

    params = {}
    by_cls = {}
    for r in tsv(os.path.join(d, "params.tsv")):
        fam = fam_of_func.get((r["function_rva"], r["function"]), "other")
        acc(params, fam, r["name"])
        if "::" in r["function"]:
            c0 = first_component(r["function"])
            for grp, rx in CLASS_GROUPS:
                if re.search(rx, c0):
                    acc(by_cls, grp, r["name"])
                    break
    cats = ["a+type", "type", "camel", "lower", "Pascal", "_leading", "unnamed"]
    ident_table("Parameters (excluding `this`)", params, cats)
    P("By owning class name (member functions only):")
    P("")
    P("| class group | n | a+type | type | camel | lower | top prefixes |")
    P("|---|---|---|---|---|---|---|")
    for grp, _ in CLASS_GROUPS:
        c = by_cls.get(grp)
        if c:
            n = c["_n"]["n"]
            P("| %s | %d | %s | %s | %s | %s | %s |" % (grp, n, pct(c["cat"]["a+type"], n), pct(c["cat"]["type"], n),
                                                    pct(c["cat"]["camel"], n), pct(c["cat"]["lower"], n),
                                                    ", ".join("`%s` %d" % kv for kv in c["pre"].most_common(5))))
    P("")
    P("Examples (most frequent names): " + "; ".join(
        "%s: %s" % (f, ", ".join("`%s`" % n for n, _ in params[f]["ex"].most_common(6)))
        for f in FAMILIES if f in params))
    P("")

    locs = {}
    for r in tsv(os.path.join(d, "locals.tsv")):
        fam = fam_of_func.get((r["function_rva"], r["function"]), "other")
        acc(locs, fam, r["name"])
    ident_table("Locals (all blocks)", locs, ["a+type", "type", "camel", "lower", "Pascal", "snake"])
    # Hungarian prefix followed by a capital ("pActor") vs glued to a lower-case word ("pactor").
    # Ambiguous for words that merely start with a prefix letter ("pos", "index"), so only names of
    # 5+ characters with prefix p/sp/pk/i/ui/f/b/e/k are counted.
    rx_cap = re.compile(r"^(sp|pk|ui|p|i|f|b|e|k)[A-Z]")
    rx_glue = re.compile(r"^(sp|pk|ui|p|i|f|b|e|k)[a-z]{3,}")
    P("Locals, Hungarian capitalisation (names >= 5 chars, prefix p/sp/pk/i/ui/f/b/e/k): " + "; ".join(
        "%s cap %d / glued %d" % (f, sum(k for n, k in locs[f]["ex"].items() if len(n) >= 5 and rx_cap.match(n)),
                                  sum(k for n, k in locs[f]["ex"].items() if len(n) >= 5 and rx_glue.match(n)))
        for f in FAMILIES if f in locs))
    P("")
    P("Examples: " + "; ".join(
        "%s: %s" % (f, ", ".join("`%s`" % n for n, _ in locs[f]["ex"].most_common(6)))
        for f in FAMILIES if f in locs))
    P("")

    # ---- fields
    fields, statics = {}, {}
    for r in tsv(os.path.join(d, "fields.tsv")):
        udt = r["udt"]
        if udt.startswith("$") or "<unnamed" in udt or "::<" in udt:
            fam = fam_for_class(first_component(udt)) if not udt.startswith("$") else "sdk_crt"
        else:
            fam = fam_for_class(udt)
        if r["name"] in ("__vfptr", "__vbptr") or r["name"].startswith("<"):
            continue
        acc(statics if r["is_static"] == "1" else fields, fam, r["name"])
    ident_table("Data members (non-static)", fields, ["m_+type", "m_Pascal", "m_other", "type", "Pascal", "camel", "lower", "UPPER"])
    P("Examples: " + "; ".join(
        "%s: %s" % (f, ", ".join("`%s`" % n for n, _ in fields[f]["ex"].most_common(6)))
        for f in FAMILIES if f in fields))
    P("")
    stp = {}
    for fam, st in statics.items():
        c = Counter()
        for n, k in st["ex"].items():
            m = re.match(r"^([a-z]+_)", n)
            if m:
                c[m.group(1)] += k
            else:
                cat, pre = classify(n)
                c[pre if cat in ("type", "a+type") else "<" + cat + ">"] += k
        stp[fam] = c
    P("#### Static data members")
    P("")
    for fam in FAMILIES:
        if fam in stp:
            n = sum(stp[fam].values())
            P("- %s (%d): %s; e.g. %s" % (fam, n, ", ".join("`%s` %s" % (p, pct(k, n)) for p, k in stp[fam].most_common(6)),
                                          ", ".join("`%s`" % x for x, _ in statics[fam]["ex"].most_common(5))))
    P("")

    # ---- globals
    gl = defaultdict(Counter)
    gex = defaultdict(list)
    ng = 0
    for r in tsv(os.path.join(d, "globals.tsv")):
        n = r["name"]
        if any(ch in n for ch in "$`?@<") or n.endswith("ms_RTTI") or n.startswith("__") or "::" in n:
            continue
        ng += 1
        m = re.match(r"^([a-z]+_)", n)
        if m:
            p = m.group(1)
        else:
            cat, pre = classify(n)
            p = pre if cat in ("type", "a+type") else "<" + cat + ">"
        gl[r["kind"]][p] += 1
        if len(gex[(r["kind"], p)]) < 3 and int(r["rva"], 16) % 7 == 0:
            gex[(r["kind"], p)].append(n)
    P("#### Namespace-scope globals (unqualified, compiler-generated names removed; %d)" % ng)
    P("")
    for kind, c in gl.items():
        n = sum(c.values())
        P("- %s (%d): %s" % (kind, n, ", ".join("`%s` %s (%s)" % (p, pct(k, n), ", ".join(gex[(kind, p)][:2]))
                                                for p, k in c.most_common(9))))
    P("")

    # ---- function name case
    fc = defaultdict(Counter)
    fex = defaultdict(Counter)
    for rva, name, fam0, cls in funcs:
        fam = fam_of_func[(rva, name)]
        m = last_component(name)
        if not m or "`" in name or m[0] == "~" or m.startswith("operator") or (cls and m == last_component(cls)):
            continue
        if re.match(r"^[A-Z][A-Z0-9_]*$", m) and len(m) > 1:
            k = "UPPER"
        elif m[0].isupper():
            k = "Pascal"
        elif m[0] == "_":
            k = "_leading"
        elif re.match(r"^[a-z0-9]+$", m):
            k = "lower"
        elif "_" in m and not re.search(r"[A-Z]", m):
            k = "snake"
        else:
            k = "camel"
        fc[(fam, "member" if cls else "free")][k] += 1
        fex[(fam, k)][m] += 1
    P("#### Function names (last component; ctors/dtors/operators removed)")
    P("")
    P("| family | scope | n | Pascal | camel | lower | snake | UPPER | _x |")
    P("|---|---|---|---|---|---|---|---|---|")
    for fam in FAMILIES:
        for scope in ("member", "free"):
            c = fc.get((fam, scope))
            if not c:
                continue
            n = sum(c.values())
            P("| %s | %s | %d | %s |" % (fam, scope, n, " | ".join(pct(c[k], n) for k in ("Pascal", "camel", "lower", "snake", "UPPER", "_leading"))))
    P("")
    P("Examples: " + "; ".join("%s %s: %s" % (f, k, ", ".join("`%s`" % x for x, _ in fex[(f, k)].most_common(4)))
                               for f in FAMILIES for k in ("Pascal", "camel", "_leading") if fex.get((f, k))))
    P("")

    # ---- enums
    ec = defaultdict(Counter)
    etn = defaultdict(Counter)
    eex = defaultdict(list)
    seen_enum = set()
    for r in tsv(os.path.join(d, "enums.tsv")):
        en = r["enum"]
        fam = fam_for_class(first_component(en)) if "::" in en else name_family(en)
        if fam == "other" and "::" not in en and en.upper() == en:
            fam = "sdk_crt"
        v = r["name"]
        if re.match(r"^k[A-Z]", v):
            k = "kPascal"
        elif re.match(r"^e[A-Z]", v):
            k = "ePascal"
        elif re.match(r"^[A-Z][A-Z0-9]*(_[A-Z0-9]+)+$", v):
            k = "UPPER_SNAKE"
        elif re.match(r"^[A-Z0-9]+$", v):
            k = "UPPER"
        elif re.match(r"^[A-Z][A-Za-z0-9]*_[A-Za-z0-9_]+$", v):
            k = "Prefix_Mixed"
        elif v[:1].isupper():
            k = "Pascal"
        else:
            k = "lower/camel"
        ec[fam][k] += 1
        if len(eex[(fam, k)]) < 3 and hash(v) % 13 == 0:
            eex[(fam, k)].append("%s::%s" % (last_component(en), v))
        if en not in seen_enum:
            seen_enum.add(en)
            t = last_component(en)
            if t.startswith("<") or t.startswith("__"):
                tk = "unnamed"
            elif re.match(r"^e[A-Z]", t):
                tk = "eName"
            elif t.endswith("_TYPE") or t.endswith("_ID") or t.upper() == t:
                tk = "UPPER"
            elif t.lower().endswith("type") or t.lower().endswith("types"):
                tk = "...Type"
            elif t[:1].isupper():
                tk = "Pascal"
            else:
                tk = "lower/camel"
            etn[fam][tk] += 1
    P("#### Enumerators (by family of the enclosing class or enum name)")
    P("")
    for fam in FAMILIES:
        if fam in ec:
            n = sum(ec[fam].values())
            m = sum(etn[fam].values())
            P("- %s: %d values: %s. Enum type names (%d): %s." % (
                fam, n, ", ".join("%s %s (%s)" % (k, pct(c, n), ", ".join("`%s`" % x for x in eex[(fam, k)][:2]))
                                  for k, c in ec[fam].most_common(5)),
                m, ", ".join("%s %s" % (k, pct(c, m)) for k, c in etn[fam].most_common(4))))
    P("")

    # ---- objects vs sources
    match = total = case_same = 0
    mism = []
    for op, srcs in obj_sources.items():
        stem_o = os.path.splitext(op.replace("/", "\\").split("\\")[-1])[0]
        main_src = srcs.most_common(1)[0][0]
        stem_s = os.path.splitext(main_src.replace("/", "\\").split("\\")[-1])[0]
        total += 1
        if stem_o.lower() == stem_s.lower():
            match += 1
            case_same += stem_o == stem_s
        elif len(mism) < 5:
            mism.append("%s <- %s" % (stem_o, main_src))
    lower_src = sum(1 for s in src_examples if s == s.lower())
    P("#### Object files and source files")
    P("")
    P("- compilands (object paths): %d; with a .c/.cpp line source: %d; object stem == main .cpp stem (case-insensitive): %d (%s), "
      "same case: %d (%s)." % (len(obj_paths), total, match, pct(match, total), case_same, pct(case_same, total)))
    P("- sampled source paths all-lowercase: %d / %d." % (lower_src, len(src_examples)))
    P("- object path examples: " + "; ".join("`%s`" % p for p in sorted(obj_paths)[:: max(1, len(obj_paths) // 5)][:5]))
    P("- source path examples: " + "; ".join("`%s`" % p for p in src_examples[::80][:5]))
    if mism:
        P("- stem mismatches (examples): " + "; ".join("`%s`" % x for x in mism))
    P("")
    sys.stdout.reconfigure(encoding="utf-8")
    print("\n".join(out))


if __name__ == "__main__":
    main()
