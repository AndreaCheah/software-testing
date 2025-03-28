### Part b

KLEE generated 672 test cases (from test000000.ktest to test000671.ktest).  

The test driver makes an array a[100] symbolic, meaning that each element can be of any integer. The test_loop runs a loop 100 times. KLEE tries to explore every possible path the code could take depending on the values of `a`. For each element out of the 100 elements of the array, KLEE would explore whether the element is smaller than 10. This means that there are 2^100 paths. KLEE doesn't have time to explore all of them, so it starts by exploring what it can, and after 15 seconds, it managed to try 672 different execution paths.

### Part c

I filled the array with a single symbolic value and used `klee_assume(val < 10)`. This ensures that the condition `a[i] < 10` is always true, leading to only a single path in symbolic execution. KLEE therefore generates exactly one test case.