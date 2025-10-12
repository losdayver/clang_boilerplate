#include "module.h"
#include <stdio.h>
#include <stdlib.h>

void cycle(int max) {
  for (int i = 0; i < max; i++) {
    printf("%i\n", i);
  }
}

struct foo *getStructPtr1() {
  struct foo *x = (struct foo *)(malloc(sizeof(struct foo)));
  x->a = 'b';
  x->b = 32463;
  return x;
}

struct foo *getStructPtr2() {
  struct foo *x = (struct foo *)(malloc(sizeof(*x)));
  *x = (struct foo){'a', 123};
  return x;
}

int main(void) {
  struct foo *(*operation)() = getStructPtr2;
  struct foo *x = operation();
  printf("Hello, World!\n");
  sayHello();
  printf("%c %d", x->a, x->b);
  free(x);
  cycle(10);
}