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

struct node * remove_val(struct node * list, int val) {
  struct node * current = list;
  struct node * prev = NULL;
  while( current ) { // while list is not at its end
    printf("@%p: %d\n",current,current -> val);
    if(val == current -> val) {
      // value found: remove node
      if( prev ) {
        // case: not the first element
        // change previous node's next value
        prev -> next = current -> next;
        free(current);
        return list;
      }else {
        // case: is the first element
        // change return value of list
        list = current -> next;
        // printf("new list starting: %p\n",list);
        free(current);
        return list;
      }
    }
    prev = current;
    current = current -> next;
  }
}
