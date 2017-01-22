/*
* This program will serve as a basic card counting tool
* The method of indentation is: select all - auto indentation
*/

#include <stdio.h>
#include <stdlib.h>

int updateCount(int val, int count);
int getVal(char card_name[]);

int main() {
  char card_name[3]; //Need 3 chars in case of '10\0'
  int count = 0;

  while (card_name[0] != 'X') {
    // Keep the loop going until the user stops the program with 'X'

    // ask user for the card name
    puts("Enter the card_name: ");
    scanf("%2s", card_name);

    // use the card_name to get the value of the card
    // val = 0 means invalid card
    int val = getVal(card_name);
    if (val == 0) {
      continue;
    }

    // update count based on the last card, print value of count
    count = updateCount(val, count);
    printf("Current count: %i\n", count);
  }
  return 0;
}

int updateCount(int val, int count) {
  // updateCount updates the count based on the value of val and a list of Rules
  // Rules: 2-6 = +1, 7-9 = 0, 10-Ace = -1
  if ((val >= 2) && (val <= 6)) {
    count++;
  } else if ((val == 10) || (val == 11)) {
    count--;
  }
  return count;
}

int getVal(char card_name[]) {
  // Returns the val casted from card_name
  // Returns 0 if invalid card_name
  int val = 0;
  switch (card_name[0]) {
    case 'K': case 'Q': case 'J': val = 10; break;
    case 'A': val = 11; break;
    case 'X': val = 0; // val is already zero, but this is explicit
    default:
    val = atoi(card_name);
    if ((val < 2) || (val > 10)) {
      puts("I don't understand that value!");
      val = 0;
    }
  }
  return val;
}
