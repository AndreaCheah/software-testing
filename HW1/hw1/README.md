# Homework 1 – Symbolic Execution with KLEE

Homework 1 explores symbolic execution using the [KLEE](https://klee.github.io/) framework. It includes:

- Assignment 1: Loop-based symbolic execution
- Assignment 2: Low-level memory bug detection and instrumentation

---

## How to Run the Code

### Using Docker + KLEE

#### Step 1: Set up Docker

```bash
cd path/to/hw1
```

```bash
docker run -it --rm -v "${PWD}:/home/klee/hw1" klee/klee
```

#### Step 2: Compile with Clang to LLVM Bitcode

```bash
clang -I /klee/include -emit-llvm -g -c your_file.c -o your_file.bc
```

#### Step 3: Run KLEE
```bash
klee --write-smt2s your_file.bc
```

#### View Results
```bash
ktest-tool klee-out-0/test000001.ktest
```
