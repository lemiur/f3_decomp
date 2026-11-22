# f3_decomp campaign tools

Tools for the Fallout 3 decompilation's rules and naming campaign. Written in C (C++ only where a COM API needs it),
built with the VS2022 compiler (`build.cmd` in each folder). Nothing here contains or emits game bytes; outputs under
`E:/f3-campaign/evidence/` are generated, ignored, and never committed.

| tool | what it does |
|---|---|
| `pdbdump/` | dump functions, parameters, locals, object files, UDT layouts and globals from a PDB (DIA) to TSV |
| `mapdump/` | parse an MSVC linker .map to TSV |
| `binscan/` | per-function features from an x86 or PPC image: string refs, calls, RTTI/vtables, imports |
| `f3rules/` | the [match]/advisory rule checker over f3_decomp source, per recipe function |
| `f3link/` | link Fallout 3 PC functions to named functions in the reference builds, with tiers |
| `f3rename/` | apply linked names across src/, include/ and build/units.json |
| `f3ledger/` | write MATCH_PENDING.md (both progress numbers, every pending function and its rules) from f3rules output |
| `f3prune/` | remove unchecked definitions (and then the declarations only they used) that nothing checked depends on |
