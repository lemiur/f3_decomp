#!/bin/sh
# Dump every reference build into $EVID/<id>/. Run after pdbdump/build.cmd and mapdump/build.cmd.
SYM=${SYM:-E:/f3-campaign/symbols}
EVID=${EVID:-E:/f3-campaign/evidence}
HERE=$(cd "$(dirname "$0")/.." && pwd)
PDBDUMP=$HERE/pdbdump/out/pdbdump.exe
MAPDUMP=$HERE/mapdump/out/mapdump.exe

run() { # id pdb exe
    mkdir -p "$EVID/$1"
    echo "== $1"
    "$PDBDUMP" "$2" "$EVID/$1" "$3" || echo "!! $1 failed ($?)"
}

run fnv360_0721_retail "$SYM/fnv_x360_20100721/Fallout.pdb"              "$SYM/fnv_x360_20100721/Fallout.exe"
run fnv360_0721_beta   "$SYM/fnv_x360_20100721/Fallout_Release_Beta.pdb" "$SYM/fnv_x360_20100721/Fallout_Release_Beta.exe"
run fnv360_0822_retail "$SYM/fnv_x360_20100822/Fallout.pdb"              "$SYM/fnv_x360_20100822/Fallout.exe"
run fnv360_0822_debug  "$SYM/fnv_x360_20100822/Fallout_Debug.pdb"        "$SYM/fnv_x360_20100822/Fallout_Debug.exe"
run fnv360_1110_retail "$SYM/fnv_x360_20101110/Fallout.pdb"              "$SYM/fnv_x360_20101110/Fallout.exe"
run fnv360_1110_debug  "$SYM/fnv_x360_20101110/Fallout_Debug.pdb"        "$SYM/fnv_x360_20101110/Fallout_Debug.exe"
run fo4_win            "$SYM/fo4_win_20191023/Fallout4.pdb"              "$SYM/fo4_win_20191023/Fallout4.exe"

mkdir -p "$EVID/tesv_win"
echo "== tesv_win"
"$MAPDUMP" "$SYM/skyrim_win_20130717/TESV.map" "$EVID/tesv_win" "$SYM/skyrim_win_20130717/TESV.exe"
