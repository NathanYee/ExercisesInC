/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

Allen's Solution:
https://gist.github.com/AllenDowney/943a602153507d673dca30e76348efd1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
 *
 * val: value to store in the node.
 * next: pointer to the next node
 *
 * returns: pointer to a new node
 */
Node *make_node(int val, Node *next) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
 *
 * list: pointer to pointer to Node
 */
void print_list(Node **list) {
    Node* current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
 *
 * list: pointer to pointer to Node
 *
 * returns: int or -1 if the list is empty
 */
int pop(Node **list) {
    Node* head = *list;
    if (head == NULL){
      return -1; //hope val isn't -1
    }
    *list = head->next; //don't bother freeing head
    return head->val;
}


/* Adds a new element to the beginning of the list.
 *
 * list: pointer to pointer to Node
 * val: value to add
 */
void push(Node **list, int val) {
    Node* head = *list; // could just use *list throguhout
    printf("val to insert: %d\n", val);
    Node* newHead = make_node(val, head); // head = *list
    printf("new head val: %d\n", newHead->val);
    *list = newHead; // can't use head here
}


/* Removes the first element with the given value
 *
 * Frees the removed node.
 *
 * list: pointer to pointer to Node
 * val: value to remove
 *
 * returns: number of nodes removed
 */
int remove_by_value(Node **list, int val) {
    Node* current = *list;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->val == val){
          printf("%d ", current->val);
          if (previous == NULL){
            puts("remove head");
            printf("%d\n", pop(&current));
          } else {
            printf("remove it!!!\n");
            previous->next  = current->next;
            free(current);
          }
        }
        previous = current;
        current = current->next;
    }
    return 0;
}


/* Reverses the elements of the list.
 *
 * Does not allocate or free nodes.
 *
 * list: pointer to pointer to Node
 */
void reverse(Node **list) {
  Node* previous = NULL;
  Node* current = *list;
  Node* next;
  while (current != NULL) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  *list = previous;
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
