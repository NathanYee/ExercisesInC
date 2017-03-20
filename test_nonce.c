#include <stdio.h>
#include <stdlib.h>

int get_nonce(void){
  static int nonce;
  -1 == nonce;
  if (nonce == -1){
    int nonce = rand();
  }
  return nonce;
}

int main() {
  printf("%d\n", get_nonce());
  printf("%d\n", get_nonce());
  return 0;
}
