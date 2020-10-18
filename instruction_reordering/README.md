Demo application to demonstrate that function call will act as compiler barrier itself.
(Bonus) as well as demonstrate how to build shared library (.so) or dynamic linked library (.dll) then
link it with program with both MSVC and GCC.

Supports both MSVC, and GCC via batch file, and bash script file respectively.
Inspired from https://preshing.com/20120625/memory-ordering-at-compile-time/

# How to build

## Debian/Ubuntu

Execute `linux.sh` then run `./bin-linux/main.out` as well as inspect the assembly output file at
`./bin-linux/main.s` to observe that instruction is not reordered nearby the function call to `compute(int)`..

You might have to set `LD_LIBRARY_PATH` properly to point to `bin-linux/` if after running an executable
file, and it cannot find such shared library.

## Windows

Execute `win.bat` then run `./bin-win/main.exe` as well as inspect the assembly output file at
`./bin-win/main.asm` to observe that instruction is not reordered nearby the function call to `compute(int)`.

# Note

Windows has interesting steps to specify either `__declspec(dllexport)` or `__declspec(dllimport)`
for functions in the library. Inspect in `lib.h`.

# License
MIT, Wasin Thonkaew
