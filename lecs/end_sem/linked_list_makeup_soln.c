#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* LinkedList;

int sum(LinkedList l) {
/* Problem 1.1: write code here to 
find sum of elements in the linked list.
Ex. Input l: 1->2->3->4->5
Returns    : 1+2+3+4+5  (2 marks) */
    int sum = 0;
    while(l != NULL) {
        sum += l->data;
        l = l->next;
    }
    return sum;
}

LinkedList insert(int e, int pos, LinkedList l) {
/* Problem 1.2: write code here to 
insert the element `e` at the position `pos` in
in the linked list `l` and
return the resultant linked list.
Ex. insert(5, 0, 1->2->3->4) 
returns    :  5->1->2->3->4 (4 marks) */
    struct Node* n = (struct Node *) malloc(sizeof(struct Node));
    n->data = e;
    n->next = NULL;
    struct Node* prev = NULL;
    struct Node* iter = l;
    while(pos != 0) {
        // if pos >= length of the list l, then return NULL
        if (iter == NULL) return NULL;
        prev = iter;
        iter = iter->next;
        pos--;
    }
    n->next = iter;
    // If insertion is at the 0th position
    // no need to update the next pointer of
    // previous item in the list
    if (prev == NULL) return n;
    prev->next = n;
    return l;
}



LinkedList copy_list(LinkedList l) {
/* Problem 1.3: write code here to return
a copy of the linked list l. Modifying,
elements in the returned linked list, should
not affect the list l.
(4 marks) */

    LinkedList l_copy = NULL;
    struct Node* prev = NULL;
    bool first_iteration = true;

    while(l != NULL) {
        struct Node* n = (struct Node *) malloc(sizeof(struct Node));
        n->data = l->data;
        n->next = NULL;
        if (prev != NULL) {
            prev->next = n;
        }
        if (first_iteration) {
            l_copy = n;
            first_iteration = false;
        }
        prev = n;
        l = l->next;
    }
    return l_copy;
}



void print_list(LinkedList l) {
    if (l == NULL) return;
    do {
        printf("%d ",l->data);
        l = l->next;
    } while (l!=NULL);
    printf("\n");
    return;
}

int main() {
    LinkedList l = NULL;
    for (int i = 1; i < 5; i++) {
        l = insert(i, 0, l);
    }
    print_list(l); // prints 4 3 2 1 
    printf("%d\n", sum(l)); // prints 10
    LinkedList l2 = copy_list(l);
    l2 = insert(10,3,l2);
    print_list(l2); // prints 4 3 2 10 1
    print_list(l);  // prints 4 3 2 1
    return 0;
}
