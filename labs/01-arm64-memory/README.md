# Lab 01 — ARM64, LLDB and memory safety

**Platform:** Apple Silicon macOS; Clang and LLDB via Xcode Command Line Tools.

## 1. Build safe examples

From repository root:

```sh
make lab01
```

## 2. Inspect with LLDB

```sh
lldb ./build/registers
(lldb) breakpoint set --name add_numbers
(lldb) run
(lldb) register read x0 x1 sp pc
(lldb) disassemble --frame
(lldb) next
(lldb) continue
(lldb) quit
```

`x0` and `x1` commonly hold integer arguments at function entry under the AArch64 calling convention; optimization, debug information, and compiler-generated prologues may affect what you observe. `sp` is the stack pointer and `pc` the program counter.

## 3. Compare safe and unsafe copies

The safe program checks bounds and is included in `make test`. The unsafe program deliberately writes beyond a stack buffer and is **not** run in CI or normal tests. Compile it with AddressSanitizer:

```sh
make asan
./build/unsafe_copy_asan
```

Expected: AddressSanitizer reports a stack-buffer-overflow and exits nonzero. Exact wording and exit status can vary. Do not run this sample on production systems.

## 4. Evidence to capture

- `uname -m`, `sw_vers`, `clang --version`, `lldb --version`
- LLDB registers and disassembly, with explanation
- ASan diagnostic from the unsafe sample
- `make test` output demonstrating safe behavior

## 5. Reflection

Explain why a fixed-size destination needs an explicit length check, and why compiler instrumentation catches errors that may otherwise produce undefined behavior.

**SEP relevance:** builds foundational knowledge of processor state and memory safety; it is not direct SEP firmware debugging.
