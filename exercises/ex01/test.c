#include <stdio.h>
#include <stdlib.h>

int detVal(char card_name);

int main() {
  char card_name[3];
  int count = 0;

  while (card_name[0] != 'X') {
    puts("Enter the card_name: ");
    scanf("%2s", card_name);

    printf("MAIN: %s\n", card_name);

    int val = detVal(*card_name);
    printf("%i\n", val);
  }
}

int detVal(char *card_name){
  /* Determines the value of the char array card_name*/
  int val = 0;
  printf("detVal1: %i\n", val);
  printf("%s\n", *card_name);

  return val;
}
