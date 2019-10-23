#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

void print_list( struct node *node ) {
  printf("[ ")
  while(node != 0) { // last element's next will be null
    printf("%d ",node -> val);
    node = node -> next;
  }
  printf("]\n");
}

struct node * insert_front(struct node * list, int val);
struct node * free_list(struct node * list);
