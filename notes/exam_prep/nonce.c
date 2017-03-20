#include <stdio.h>
#include <stdlib.h>

int get_nonce(void){
  static int first = 0;
  static int a;
  if (first == 0){
    int b = rand();
    a = b;
  }
  first += 1;
  return a;



  // static int called = 0;
  // int a = rand();
  // if (called == 0){
  //   int b = a;
  // }
  //
  // return b;
}

int main() {
  printf("%d\n", get_nonce());
  printf("%d\n", get_nonce());
  return 0;
}
