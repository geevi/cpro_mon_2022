#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* LinkedList;

int length(LinkedList l) {
/* Problem 1.1: write code here to 
find the length of the linked list l 
and return it.
Ex. Input l: 1->2->3->4->5
Returns    : 5   (2 marks) */
    int len = 0;
    if (l == NULL) return len;
    while (l->next != NULL)
    {
        l = l->next;
        len++;
    }
    return len + 1;
}

LinkedList reverse(LinkedList l) {
/* Problem 1.2: write code here to 
reverse the linked list l and
return the resultant linked list.
Ex. Input l: 1->2->3->4
Returns    : 4->3->2->1 (4 marks) */
    if (l == NULL || l->next == NULL) return l;
    struct Node* i = l;
    struct Node* i_next = l->next;
    struct Node* i_next_next = l->next->next;
    i->next = NULL;
    while (i_next_next != NULL) {
        i_next->next = i;
        i = i_next;
        i_next = i_next_next;
        i_next_next = i_next_next->next;
    } 
    i_next->next = i;
    return i_next;
}


void free_list(LinkedList l) {
/* Problem 1.3: write code here to free 
all the memory used by a linked list l. 
(4 marks) */
    if (l==NULL) return;
    struct Node* i = l;
    struct Node* i_next = l->next;
    while (i_next != NULL) {
        free(i);
        i = i_next;
        i_next = i_next->next;
    }
    free(i);
}

void print_list(LinkedList l) {
    if (l == NULL) return;
    do {
        printf("%d ",l->data);
        l = l->next;
    } while (l!=NULL);
    return;
}

LinkedList append(int d, LinkedList l) {
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    n->data = d;
    n->next = NULL;
    if (l==NULL) return n;
    struct Node* i = l;
    while (i->next != NULL) {
        i = i->next;
    }
    i->next = n;
    return l;
}


int main() {

    LinkedList l = NULL;
    for (int i = 1; i < 10; i++) {
        l = append(i, l);
    }
    print_list(l);
    printf("\n");
    l = reverse(l);
    print_list(l);
    printf("\n");




    return 0;
}