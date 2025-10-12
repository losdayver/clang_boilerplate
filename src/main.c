#include "module.h"
#include <stdio.h>

void cycle(int max) {
  for (int i = 0; i < max; i++) {
    printf("%i\n", i);
  }
}

int main(void) {
  struct foo x = {'s', 10};
  printf("Hello, World!\n");
  sayHello();
  cycle(10);
}