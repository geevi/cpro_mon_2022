#include"linked_list.h"
#include <string.h>

int main() {
    LinkedList l = create_empty_list();

    Customer* c = malloc(sizeof(Customer));
    c->phone_no = 23423;
    strcpy(c->name, "Alice");

    l = append(c, l);


    // printf("%s\t%d\n",l->data->name, l->data->phone_no);


    c = malloc(sizeof(Customer));
    c->phone_no = 12312;
    strcpy(c->name, "Bob");
    l = append(c, l);

    c = element_at(0, l);
    printf("%s\t%d\n",c->name, c->phone_no);
    // print_list(l);



    return 0;
}