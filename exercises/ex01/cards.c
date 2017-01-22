/*
* This program will serve as a basic card counting tool
* The method of indentation is: select all - auto indentation
*/

#include <stdio.h>
#include <stdlib.h>

int updateCount(int val, int count);

int main() {
  char card_name[3];
  int count = 0;

  while (card_name[0] != 'X') {
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
    int val = 0;
    switch (card_name[0]) {
      case 'K': case 'Q': case 'J': val = 10; break;
      case 'A': val = 11; break;
      case 'X': val = -1;
      default:
      val = atoi(card_name);
      if ((val < 2) || (val > 10)) {
        puts("I don't understand that value!");
        val = -1;
      }
    }
    if (val == -1) {
      continue;
    }
    count = updateCount(val, count);
    printf("Current count: %i\n", count);
  }
  return 0;
}

int updateCount(int val, int count) {
  // updateCount updates the count based on the value of val and a list of Rules
  // Rules: 2-6 = +1, 7-9 = 0, 10-Ace = -1
  if ((val >= 2) && (val < 7)) {
    count++;
  } else if ((val == 10) || (val == 11)) {
    count--;
  }
  return count;
}
