#include "linked_list.h"

#include <string.h>

int main() {

    Customer *c = malloc(sizeof(Customer));

    c->phone_no = 987382;
    strcpy(c->name, "Alice");
    LinkedList l = create_empty_linked_list();
    l = append((void*) c, l);


    Reciept r = {
        .value = 100.0,
        .time = time(NULL),
        .mode = UPI,
        .customer_index = 2
    };

    // printf("%s\t%d", l->data->name, l->data->phone_no);

    l = append( (void*) &r, l);


    c = (Customer*) element_at(0, l);
    printf("%s\t%d\n", c->name, c->phone_no);


    Reciept* rp = (Reciept*) element_at(1, l);
    printf("%f\t%d\n", rp->value, rp->customer_index);

    return 0;
}