#include <klee/klee.h>
#include <stdlib.h>
#include <assert.h>

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

int main() {
    int a[100];
    int val;

    klee_make_symbolic(&val, sizeof(val), "val");

    // Force val to always be less than 10
    klee_assume(val < 10);

    for (int i = 0; i < 100; i++) {
        a[i] = val;
    }

    test_loop(a);
    return 0;
}
