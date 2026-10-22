# Master Mathematical Guidance Computer (MMGC)

MMGC is a C++23 research-oriented spacecraft computer architecture combining numerical mathematics, symbolic mathematics, orbital mechanics, navigation, guidance, a custom assembly language, and an embeddable scripting layer.

## Current foundation

- C++23 core library and executable
- 3D vector mathematics
- two-body gravitational acceleration
- spacecraft state vector
- first guidance-command interface
- CMake build and CTest smoke test
- optional Luau integration through the upstream CMake project
- reserved adapter layer for 8086tiny

## Architecture

```text
Mission sentence / Luau script / MGASM
                |
          Lexer / Parser
                |
        Mathematical AST / IR
                |
      Symbolic + Numeric Solver
                |
       Physics / Navigation
                |
        Guidance / Control
                |
       MMGC Machine Runtime
                |
       CPU / Memory / Bus / I/O
```

## Build

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

For Luau:

```bash
cmake -S . -B build -DMMGC_ENABLE_LUAU=ON
cmake --build build
```

Luau is included as an optional upstream dependency and retains its MIT license. 8086tiny is also MIT licensed and is planned as the low-level PC/CPU emulation adapter rather than being silently copied into MMGC.

## Guidance loop

```text
MEASURE -> INTERPRET -> MODEL -> SOLVE -> PREDICT -> COMPARE
-> ERROR -> CORRECT -> COMMAND -> VERIFY -> REPEAT
```

## Status

This repository is being built incrementally. The current commit establishes the mathematical and guidance kernel; CPU, memory, MGASM, symbolic calculus, navigation filters, mission runtime, and hardware emulation layers follow as separate modules.
