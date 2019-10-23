#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"linkedlist.h"

int main(){
  printf("Linked List! W03\nKiran Vuksanaj\n");
  time_t seed = time(NULL);
  printf("Seed: %lu\n",seed);
  srand(seed);

  printf("Print empty list: ");
  print_list(NULL);

  size_t listsize = rand() % 25;
  printf("Generating random list of size %lu\n",listsize);

  struct node * list = NULL;
  size_t i;
  for( i = 0; i < listsize; i++ ) {
    int val = rand() % 100 - 50;
    printf("\tInserting %d\n",val);
    list = insert_front(list,val);
  }

  printf("Print generated list: ");
  print_list(list);

  printf("Free list: \n");
  list = free_list(list);

  printf("Print emptied list: ");
  print_list(list);
  return 0;
}
