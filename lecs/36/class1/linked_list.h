#ifndef LINKED_LIST
#define LINKED_LIST

#include "srms.h"
#include <stdlib.h>

struct Node {
    void* data;
    struct Node* next;
};


typedef struct Node* LinkedList;


LinkedList create_empty_linked_list();

LinkedList append(void* c, LinkedList l);

// void print_list(LinkedList l);

void* element_at(int i, LinkedList l);

#endif