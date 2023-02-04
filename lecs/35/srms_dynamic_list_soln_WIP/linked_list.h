#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

struct Node {
    void* data;
    struct Node* next;
};


typedef struct Node* LinkedList;


LinkedList create_empty_linked_list();

LinkedList add(void* e, LinkedList l, int list_size);


void* element_at(int i, LinkedList l) ;


LinkedList read_from_file(FILE* f, LinkedList l, int size);

LinkedList write_to_file(FILE* f, LinkedList l, int type_size, int list_size);

#endif