#include "linked_list.h"


LinkedList create_empty_linked_list() {
    return NULL;
}

LinkedList append(void* c, LinkedList l) {

    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    n->data = c;
    n->next = NULL;

    struct Node* i = l;

    if (i == NULL) {
        return n;
    } else {
        while(i->next != NULL) {
            i = i->next;
        }
        i->next = n;
        return l;
    }
    
}

void* element_at(int i, LinkedList l) {
    while(i >0) {
        l = l->next;
        i--;
    }
    return l->data;
}

// void print_list(LinkedList l) {
//     while(l != NULL) {
//         printf("%s\t%d\n", l->data->name, l->data->phone_no);
//         l = l->next;
//     }

// }