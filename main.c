#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"linkedlist.h"

void testremove();

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
    // printf("\tInserting %d\n",val);
    list = insert_front(list,val);
  }

  printf("Print generated list: ");
  print_list(list);

  printf("Free list: \n");
  list = free_list(list);

  printf("Print emptied list: ");
  print_list(list);

  testremove();

  return 0;
}

void testremove() {
  int val_to_remove = rand() % 1000 - 500;
  size_t listsize2 = rand() % 25 + 3;
  printf("listsize 2: %lu\n",listsize2);
  size_t index_to_insert = rand() % listsize2;
  // size_t index_to_insert = listsize2 - 1;
  struct node * list2 = NULL;
  size_t i;
  for( i = 0; i < listsize2; i++ ) {
    // printf("adding value..\n");
    if( i == index_to_insert ) {
      list2 = insert_front(list2,val_to_remove);
    }else {
      int val = rand() % 1000 - 500;
      while(val == val_to_remove){
        val = rand() % 1000 - 500;
      }
      list2 = insert_front( list2, val );
    }
  }
  printf("New random list: ");
  print_list(list2);
  printf("Value to remove: %d\n",val_to_remove);
  printf("Removing...\n");
  list2 = remove_val(list2,val_to_remove);
  printf("list after removal: ");
  print_list(list2);

  list2 = free_list(list2);
  printf("freed list: ");
  print_list(list2);
}
