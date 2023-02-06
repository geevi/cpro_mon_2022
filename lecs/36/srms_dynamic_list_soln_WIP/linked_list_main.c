#include "linked_list.h"
#include "srms.h"


int main() {

    LinkedList l = create_empty_linked_list();

    Customer c = {
        .name = "Alice",
        .phone_no = 983223
    };

    Reciept r = {
        .value = 100.0,
        .time = time(NULL),
        .mode = UPI,
        .customer_index = 2
    };



    l = append(&c, l);
    l = append(&r, l);
    

    Customer* cp = (Customer*) element_at(0, l);
    printf("%s\t%d\n", cp->name, cp->phone_no);
    
    Reciept* rp = (Reciept*) element_at(1, l);
    printf("%d\t%f\n", rp->customer_index, rp->value);

    return 0;
}