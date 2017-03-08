#include <stdio.h>
#include <string.h>

void change_case(char* str){
  for (size_t i = 0; i < strlen(str); i++) {
    int temp = (int) str[i] ^ 0b00100000;
    str[i] = (char) temp;
  }

}

int main() {
  char letter[] = "abcd";
  change_case(letter);

  printf("%s\n", letter);
  return 0;
}
