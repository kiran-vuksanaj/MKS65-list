#ifndef LINKEDLIST_H
#define LINKEDLIST_H
struct node {
  int val;
  struct node *next;
}
void print_list( struct node *list );
struct node * insert_front(struct node * list, int val);
struct node * free_list(struct node * list);
#endif
