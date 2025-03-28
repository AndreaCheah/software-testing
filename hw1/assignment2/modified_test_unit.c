#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>   // for uintptr_t
#include <klee/klee.h>

typedef struct cell {
    long v;
    struct cell* next;
    struct cell* prev;
} cell;

void test_unit(cell* p, int x) {
    p = (cell *) malloc(sizeof(cell));
    p->v = 0;
    p->next = p->prev = NULL;

    if (x > 0) {
        // Calculate whether there is enough space remaining after the offset
        uintptr_t offset = (uintptr_t)p + sizeof(long);
        uintptr_t end_of_alloc = (uintptr_t)p + sizeof(cell);

        if (offset + sizeof(cell) > end_of_alloc) {
            printf("Error: unsafe memory access avoided. Exiting gracefully.\n");
            free(p);
            exit(1);
        }

        cell* cur = (cell *)((char *)p + sizeof(long));
        cur->next = cur->prev = p;

        if (p->prev != NULL)
            assert(0 && "You should get out of here!!!");
    }

    free(p);
}

int main() {
    int x;
    klee_make_symbolic(&x, sizeof(x), "x");
    test_unit(NULL, x);
    return 0;
}
