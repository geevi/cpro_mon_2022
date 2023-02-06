#include "srms.h"


// Find a customer with `phone` as the phone number in database `db`
// If no such customer exists, returns NULL
int find_customer_by_phone_no(int phone, Database *db) {

    LinkedList c = db->customers;
    int i = 0;
    while (c != NULL) {
        if(phone == ((Customer*) c->data)->phone_no) {
            c = i;
            break;
        }
        c = c->next;
        i++;
    }

}


int add_customer(char *name, int phone_no, Database *db) {
    Customer *c = malloc(sizeof(Customer));
    c->phone_no = phone_no;
    strcpy(c->name, name);
    db->customers = add(c, db->customers);
    return db->customer_count-1;
}

Reciept* add_reciept(int value, int c, PayMode mode, Database *db) {
    time_t now = time(NULL);
    Reciept* r = malloc(sizeof(Reciept));
    r->customer_index= c;
    r->value = value;
    r->time = now;
    r->mode = mode;
    db->reciepts = add(r, db->reciepts);
    return r;
}
