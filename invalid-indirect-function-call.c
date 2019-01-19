/*

  function foo does not match function pointer definition fpt.

  Detectable with clang's CFI:

  clang -fsanitize=cfi -fvisibility=hidden -fuse-ld=gold -flto \
  -fno-sanitize-trap=all invalid-indirect-function-call.c

*/

#include <stdio.h>

void foo(int i) {
  printf("%i\n", i);
}

typedef void (*fpt)(unsigned int i);

int main() {
  fpt fp;

  fp = foo;

  foo(10);
  fp(20);
}
