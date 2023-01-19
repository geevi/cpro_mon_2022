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


    FILE* fptr = fopen("customers.bin","r");

    fread(&(db.customer_count), sizeof(int), 1, fptr);
    fread(db.customers, sizeof(Customer), db.customer_count, fptr);


    for (int i =0;i < db.customer_count; i++) {
        Customer* c = &(db.customers[i]);
        printf("%s\t%d\n", c->name, c->phone_no);
    }


    FILE* rec_fptr = fopen("reciepts.bin","r");

    fread(&(db.reciept_count), sizeof(int), 1, rec_fptr);
    fread(db.reciepts, sizeof(Reciept), db.reciept_count, rec_fptr);


    for (int i =0;i < db.reciept_count; i++) {
        Reciept* r = &(db.reciepts[i]);
        printf("%d\t%d\t%f\t%s\n", r->mode, r->time, r->value, r->customer->name);
    }

    fclose(rec_fptr);



    fclose(fptr);

    return 0;

}