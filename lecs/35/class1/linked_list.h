#include "srms.h"
#include <stdlib.h>

struct Node {
    Customer* data;
    struct Node* next;
};


typedef struct Node* LinkedList;


LinkedList create_empty_linked_list();

LinkedList append(Customer* c, LinkedList l);

void print_list(LinkedList l);

Customer* element_at(int i, LinkedList l);