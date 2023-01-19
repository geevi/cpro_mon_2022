#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct Customer {
    char name[100];
    int phone_no;
} Customer;

typedef enum PayMode {
    Cash = 0,
    Card = 1,
    UPI = 2
} PayMode;

typedef struct Reciept {
    time_t time;
    float value;
    Customer *customer;
    PayMode mode;
} Reciept;

typedef struct Database {
    Customer customers[100];
    Reciept reciepts[1000];
    int customer_count;
    int reciept_count;
} Database;



Customer* add_customer(char *name, int phone_no, Database *db) {
    Customer *c = &(db->customers[db->customer_count++]);
    c->phone_no = phone_no;
    strcpy(c->name, name);
    return c;
}

Reciept* add_reciept(int value, Customer* c, PayMode mode, Database *db) {
    time_t now = time(NULL);
    Reciept* r = &(db->reciepts[db->reciept_count++]);
    r->customer= c;
    r->value = value;
    r->time = now;
    r->mode = mode;
    return r;
}



int main() {
    Database db;
    FILE* fptr = fopen("customers.txt","r");



    Customer* a = add_customer("Alice",12345,&db);

    add_reciept(1000, a, Cash, &db);
    add_reciept(500, a, UPI, &db);

    Customer* b = add_customer("Bob",5678,&db);

    add_reciept(700, b, Card, &db);
    add_reciept(500, b, UPI, &db);

    FILE* fptr = fopen("customers.txt","w");
    fwrite(&(db.customer_count), sizeof(int), 1, fptr);

    fwrite(db.customers, sizeof(Customer), db.customer_count, fptr);

    fclose(fptr);

    return 0;

}