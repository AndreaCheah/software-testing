#include <klee/klee.h>
#include <stdlib.h>
#include <assert.h>

// Function provided in the assignment
int test_loop(int a[]) {
    int y = 0;
    int i = 0;
    while (i < 100) {
        if (a[i] < 10)
            y++;
        else
            y--;
        i++;
    }
    assert(y <= 100);
    return y;
}

// Test driver for KLEE
int main() {
    int a[100];
    klee_make_symbolic(&a, sizeof(a), "a");  // Make the array symbolic
    test_loop(a);  // Call the function
    return 0;
}
