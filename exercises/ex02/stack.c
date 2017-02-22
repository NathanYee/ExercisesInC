/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
  int i;
  int array[SIZE];

  printf("%p\n", array);

  for (i=0; i<SIZE; i++) {
    array[i] = 42;
  }
  return array; /*
                 *  This returns a pointer to an array local to this function.
                 *  As a result, the memory allocated for the array is closed
                 *  and we will not be able to access it in main.
                 */
}

void bar() {
  int i;
  /* Create a new local array in bar */
  int array[SIZE];

  printf("%p\n", array);

  /* Populate local array with numbers 0-4 */
  for (i=0; i<SIZE; i++) {
    array[i] = i;
  }

  /* Print the values of array to see that they exist */
  for (i=0; i<SIZE; i++) {
    printf("%d\n", array[i]);
  }
}

int main()
{
  int i;
  printf("Before foo()\n");
  int *array = foo();
  printf("After foo()\n");

  printf("%i\n", sizeof(array));

  printf("Before bar()\n");
  bar();
  printf("After bar()\n");


  for (i=0; i<SIZE; i++) {
    printf("%d\n", array[i]);
  }
  printf("After for loop main\n");


  return 0;
}
