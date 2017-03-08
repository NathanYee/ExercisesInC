#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island{
  char* name;
  char* opens;
  char* closes;
  struct island *next;
} island;

island* create(char *name)
{
  island *i = malloc(sizeof(island));
  i->name = strdup(name);
  i->opens = "09:00";
  i->closes = "17:00";
  i->next = NULL;
  return i;
}

int main(void){
  char name[80];
  fgets(name, 80, stdin);
  island *p_island0 = create(name);
  fgets(name, 80, stdin);
  island *p_island1 = create(name);

  printf("Name: %s open: %s-%s\n", p_island0->name, p_island0->opens, p_island0->closes);
  printf("Name: %s open: %s-%s\n", p_island1->name, p_island1->opens, p_island1->closes);
}
