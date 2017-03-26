#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int compare_scores_desc(const void* score_a, const void* score_b)
{
  // Compares two integers - use qsort to sort integers largest first
  int a = *(int*)score_a;
  int b = *(int*)score_b;
  return b - a;
}

int compare_names(const void* a, const void* b)
{
  // Compare two strings - use qsort to sort strings sallest first alphabetical
  // case sensitive
  char** str_a = (char**) a;
  char** str_b = (char**) b;
  return strcmp(*str_a, *str_b);
}

int main() {
  int scores[] = {543, 323, 32, 554, 11, 3, 112};
  int i;
  int array_len = 7;
  qsort(scores, array_len, sizeof(int), compare_scores_desc);
  puts("These are the scores in order:");
  for (i = 0; i < array_len; i++) {
    printf("Score = %i\n", scores[i]);
  }

  puts("");
  char *names[] = {"andy", "Karen", "Mark", "Brett", "Molly"};
  qsort(names, 5, sizeof(char*), compare_names);
  puts("These are the names in order:");
  for (i = 0; i < 5; i++) {
    printf("%s\n", names[i]);
  }
  return 0;

}
