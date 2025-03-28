#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* cell structure, data type lengths are shown alongside */
typedef struct cell {
    long v; //8 bytes
    struct cell* next; //8 bytes
    struct cell* prev; //8 bytes
}cell;

void test_unit(cell* p, int x) {
    /* allocate one cell */
    p = (cell *) malloc (sizeof(cell));
    p->v = 0;
    p->next = p->prev = NULL;
    if (x > 0) {
        cell* cur = (cell *)((char *)p + sizeof(long));
        cur->next = cur->prev = p;
        if (p->prev != NULL)
            assert(0 && "You should get out of here!!!"); //buggy function
    }
}

int main() {
  int x = 1;  // Replaced klee_make_symbolic with positive value

  test_unit(NULL, x);

  return 0;
}
