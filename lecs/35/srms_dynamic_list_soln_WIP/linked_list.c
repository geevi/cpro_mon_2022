#include "linked_list.h"

LinkedList create_empty_linked_list() {
    return NULL;
}

LinkedList add(void* e, LinkedList l, int list_size) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = e;
    n->next = NULL;

    struct Node* i = l;

    if (l == NULL) {
        return n;
    }
    // printf("l not null\n");
    while (i->next != NULL) {
        i = i->next;
    }
    i->next = n;
    return l; 
}


void* element_at(int i, LinkedList l) {
    struct Node* n = l;
    while (i > 0) {
        n = n->next;
        i--;
    }
    return n->data;
}


// LinkedList read_from_file(FILE* f, LinkedList l, int size) {
//     if (f != NULL) { 
//         int count = 0;
//         fread(&(count), sizeof(int), 1 , f);    
//         int i = count;
//         while (i >= 0) {
//             void* c = malloc(size);
//             fread(c, size, i--, f);
//             l = add(c, l);
//         }
//         fclose(f);
//     }
//     return l;
// }


// LinkedList write_to_file(FILE* f, LinkedList l, int type_size, int list_size) {
//     if (f != NULL) { 
//         fwrite(&(list_size), sizeof(int), 1 , f);    
//         int i = list_size;
//         while (i >= 0) {
//             void* c = malloc(type_size);
//             fwrite(c, type_size, i--, f);
//         }
//         fclose(f);
//     }
//     return l;
// }


