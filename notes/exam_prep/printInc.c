#include <stdio.h>

void inc_print(int len, int int_list[]){
  int last;
  for (int i = 0; i < len; i++) {
    if (int_list[i] != last){
      printf("%d ", int_list[i]);
    }
    last = int_list[i];
  }
  puts("");
}

int main() {
  int int_list[6] = {1, 1, 3, 5, 5, 7};
  int len = sizeof(int_list) / sizeof(int_list[0]);
  inc_print(len, int_list);
  int int_list2[6] = {7, 8, 8, 9, 10};
  inc_print(len, int_list2);
  return 0;
}
