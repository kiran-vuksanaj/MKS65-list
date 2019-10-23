#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

void print_list( struct node *node ) {
  printf("[ ");
  while(node != 0) { // last element's next will be null
    printf("%d ",node -> val);
    node = node -> next;
  }
  printf("]\n");
}

struct node * insert_front(struct node * list, int val){
  struct node * out = malloc(sizeof (struct node) );
  out -> val = val;
  out -> next = list;
  return out;
  // puts this in front of the list
  // if null is passed in for the existing list, a new list is born!
}

struct node * free_list(struct node * list) {
  struct node * next;
  while(list != NULL) {
    next = list -> next;
    printf("\t[freeing node @%p: %d]\n",list,list -> val);
    free(list);
    list = next;
  }
  return NULL;
}
