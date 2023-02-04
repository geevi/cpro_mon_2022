#include "srms.h"
#include<stdlib.h>


struct Node
{
    Customer* data;
    struct Node* next;
};

typedef struct Node* LinkedList;


LinkedList create_empty_list() {
    return NULL;
}

LinkedList append(Customer* c, LinkedList l) {
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    n->data = c;
    n->next = NULL;
    if (l==NULL) {
        return n;
    } else {
        struct Node* i = l;
        while(i->next !=NULL) {
            i = i->next;
        }
        i->next = n;
        return l;
    }
}



void print_list(LinkedList l) {
    while (l!=NULL) {
        
        printf("%s\t%d\n",l->data->name, l->data->phone_no);
        l = l->next;
    }
}


Customer* element_at(int i, LinkedList l) {

    int count = 0;
    struct Node* n = l;
    while(count < i) {
        n = n->next;
        count++;
    }
    return n->data;
}