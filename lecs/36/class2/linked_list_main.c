#include "linked_list.h"

#include <string.h>

int main() {

    Customer *c = malloc(sizeof(Customer));

    c->phone_no = 987382;
    strcpy(c->name, "Alice");
    LinkedList l = create_empty_linked_list();
    l = append((void*) c, l);


    Reciept* r = malloc(sizeof(Reciept));
    r->value = 100.5;
    r->customer_index =5;

    // printf("%s\t%d", l->data->name, l->data->phone_no);

    l = append(r, l);


    c = (Customer*) element_at(0, l);
    printf("%s\t%d\n", c->name, c->phone_no);


    r = (Reciept*) element_at(1, l);
    printf("%f\t%d\n", r->value, r->customer_index);

    return 0;
}