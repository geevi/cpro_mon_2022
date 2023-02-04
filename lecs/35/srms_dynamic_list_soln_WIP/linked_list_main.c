#include "linked_list.h"
#include "srms.h"


int main() {

    LinkedList l = create_empty_linked_list();

    Customer c = {
        .name = "Alice",
        .phone_no = 983223
    };


    l = add(&c, l, 0);
    l = add(&c, l, 0);
    

    printf("%s\t%d\n", ((Customer*)l->data)->name, ((Customer*)l->data)->phone_no);
    l = l->next;

    printf("%s\t%d\n", ((Customer*)l->data)->name, ((Customer*)l->data)->phone_no);

    return 0;
}