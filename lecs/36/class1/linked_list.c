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

LinkedList remove(int i, LinkedList l) {

    struct Node* j = l;

    while(i >1) {
        j = j->next;
        i--;
    }

    struct Node* prev = j;
    struct Node* node_i = j->next;

    prev->next = node_i->next;
    free(node_i);
    return l;
    
}

void* element_at(int i, LinkedList l) {
    while(i >0) {
        l = l->next;
        i--;
    }
    return l->data;
}


LinkedList join(LinkedList l1, LinkedList l2){
    if (l1 == NULL) return l2;
    struct Node* i = l1;
    while (i->next != NULL) {
        i = i->next;
    }
    i->next = l2;
    return l1;
}

LinkedList shuffle_join(LinkedList l1, LinkedList l2) {
    // Assume l1 and l2 has the same length
    
    if (l1==NULL || l2 == NULL)
        return NULL;

    int length = 1;
    struct Node* i = l1;
    while (i->next != NULL) {
        i= i->next;
        length++;
    }
    struct Node* cur_pos_l1 =l1;
    struct Node*  next_pos_l1 = l1->next;
    struct Node* cur_pos_l2 = (struct Node*) l2;
    struct Node* next_pos_l2 = l2->next;
    while (next_pos_l1->next != NULL) {
            cur_pos_l1->next = cur_pos_l2;
            cur_pos_l2->next = next_pos_l1;
            cur_pos_l1 = next_pos_l1;
            cur_pos_l2 = next_pos_l2;
            next_pos_l1 = next_pos_l1->next;
            next_pos_l2 = next_pos_l2->next;
    }
    cur_pos_l1->next = cur_pos_l2;
    cur_pos_l2->next = next_pos_l1;
    next_pos_l1->next = next_pos_l2;
    // struct Node*
    //     cur_pos_l1 = l1,
    //     cur_pos_l2 = l2,
    //     next_pos_l1 = l1->next,
    //     next_pos_l2 = l2->next;


    // while (next_pos_l1 != NULL && cur_pos_l2 != NULL) {
    //     cur_pos_l1->next = cur_pos_l2;
    //     cur_pos_l2->next = next_pos_l1;
    //     next_pos_l1->next = next_pos_l2;
    //     next_pos_l2 = next_pos_l2->next;
    // }
    


}



// void print_list(LinkedList l) {
//     while(l != NULL) {
//         printf("%s\t%d\n", l->data->name, l->data->phone_no);
//         l = l->next;
//     }

// }