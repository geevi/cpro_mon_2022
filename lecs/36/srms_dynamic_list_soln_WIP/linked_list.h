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

LinkedList append(void* e, LinkedList l);


void* element_at(int i, LinkedList l) ;


LinkedList read_from_file(char* file_name, LinkedList l, int type_size, int list_size);

LinkedList write_to_file(char* file_name, LinkedList l, int type_size, int list_size);

#endif