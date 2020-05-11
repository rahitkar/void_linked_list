#ifndef __LIST_H
#define __LIST_H

typedef enum
{
  Failure,
  Success
} Status;

typedef struct node
{
  void* value;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct
{
  Node_ptr head;
  Node_ptr last;
  int count;
} List;

typedef List *List_ptr;
typedef char * Char_ptr;

List_ptr create_list(void);
Node_ptr create_node(void*);
int search(List_ptr, void* value);

Status add_to_end(List_ptr, void* value);
Status add_to_start(List_ptr, void* value);
Status insert_at(List_ptr, void* value, int position);
Status add_unique(List_ptr, void* value);

void display(List_ptr);

Status remove_from_start(List_ptr);
Status remove_from_end(List_ptr);
Status remove_at(List_ptr, int position);

Status remove_first_occurrence(List_ptr, void* value); 
Status remove_all_occurrences(List_ptr, void* value); 

Status clear_list(List_ptr); // Removes all elements in the list

void destroy_list(List_ptr); // Frees the elements and the list structure from memory

#endif