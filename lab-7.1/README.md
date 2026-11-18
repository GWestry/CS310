# Recursive Solutions for ADTs

This folder completes the 30 mini-problems from the practice lab. Every
`Problem01.cpp` through `Problem30.cpp` is a standalone executable with its
own `main()` and a small demonstration input. `RecursiveADT.h` contains only
the supplied-style node/ADT scaffolding and safe test helpers.

## Build and run

```powershell
cmake -S . -B build
cmake --build build
ctest --test-dir build
```

The CMake project creates one target per problem. Each source file contains a
commented time/space analysis and handles empty or one-element inputs where
the operation permits them.

## Submission checklist

- `Problem01.cpp` ... `Problem30.cpp`: individual source submissions
- `Traces/Problem01.svg` ... `Traces/Problem30.svg`: labeled stack/heap trace
  sheets suitable for printing or exporting to PDF
- `Reflections.md`: answers to all five challenge questions and a short
  reflection on each problem group
- `ComplexityTable.md`: consolidated complexity analysis

The SVG trace sheets are intentionally simple, editable diagrams rather than
pretending to be hand-drawn scans. They can be printed and annotated by hand
if the instructor requires handwritten traces.
