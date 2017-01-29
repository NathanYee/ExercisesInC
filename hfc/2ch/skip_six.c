#include <stdio.h>

void skip(char *msg);

int main(int argc, char const *argv[]) {
  char * msg_from_amy = "Don't call me";
  skip(msg_from_amy);
  return 0;
}

void skip(char *msg)
{
  puts(msg + 6);
}
