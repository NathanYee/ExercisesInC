#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
  void* payload;
  struct treenode* left;
  struct treenode* right;
} Treenode;

Treenode* create(void* payload, Treenode* left, Treenode* right)
{
  Treenode* T = malloc(sizeof(Treenode));
  T->payload = payload;
  T->left = left;
  T->right = right;
  // return T;
}

Treenode* create_empty(void* payload)
{
  Treenode* T = malloc(sizeof(Treenode));
  T->payload = payload;
  T->left = NULL;
  T->right = NULL;
  // return T;
}

int main() {
  int *n = malloc(sizeof(int));
  *n = 0;
  int *m = malloc(sizeof(int));
  *m = 1;
  printf("%d\n", *n);
  Treenode* tree1 = create_empty(n);
  Treenode* tree2 = create_empty(n);
  Treenode* my_tree = create(m, tree1, tree2);
  int*j = my_tree->payload;
  printf("%d\n", *j);
  return 0;
}
