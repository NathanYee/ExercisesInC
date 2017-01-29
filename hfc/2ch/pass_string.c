#include <stdio.h>

void fortune_cookie(char msg[]);

int main(int argc, char const *argv[]) {
  char quote[] = "Please print this string!";
  fortune_cookie(quote);
  return 0;
}

void fortune_cookie(char msg[]) {
  printf("Message reads: %s\n", msg);
}
