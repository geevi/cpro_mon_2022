#include "linked_list.h"

#include <string.h>

int main() {

    Customer *c = malloc(sizeof(Customer));

    c->phone_no = 987382;
    strcpy(c->name, "Alice");
    LinkedList l = create_empty_linked_list();
    l = append(c, l);


    c = malloc(sizeof(Customer));

    c->phone_no = 343433;
    strcpy(c->name, "Bob");

    // printf("%s\t%d", l->data->name, l->data->phone_no);

    l = append(c, l);

    print_list(l);


    c = element_at(1, l);
    printf("%s\t%d", c->name, c->phone_no);

    return 0;
}