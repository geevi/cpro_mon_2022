#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef struct Customer {
    char name[100];
    int phone_no;
} Customer;

typedef enum PayMode {
    Cash = 0,
    Card = 1,
    UPI = 2
} PayMode;

typedef struct  Product {
    char name[100];
    int price;
} Product;


typedef struct Reciept {
    time_t time;
    float value;
    Customer *customer;
    PayMode mode;
    Product items[20];
    int item_count;
} Reciept;


typedef struct Database {
    Customer customers[100];
    Reciept reciepts[1000];
    int customer_count;
    int reciept_count;
} Database;

// Find a customer with `phone` as the phone number in database `db`
// If no such customer exists, returns NULL
Customer* find_customer_by_phone_no(int phone, Database *db) {
    Customer *cust = NULL;
    for(int i =0; i< db->customer_count; i++) {
        if(phone == db->customers[i].phone_no) {
            cust = &(db->customers[i]);
            break;
        }
    }
    return cust;
}


Customer* add_customer(char *name, int phone_no, Database *db) {
    Customer *c = &(db->customers[db->customer_count++]);
    c->phone_no = phone_no;
    strcpy(c->name, name);
    return c;
}

Reciept* add_reciept(Customer* c, PayMode mode, Database *db) {
    time_t now = time(NULL);
    Reciept* r = &(db->reciepts[db->reciept_count++]);
    r->customer = c;
    r->value = 0;
    r->time = now;
    r->mode = mode;
    r->item_count = 0;
    return r;
}

void add_item_to_reciept(Product p, Reciept* r) {
    r->items[r->item_count].price = p.price;
    strcpy(r->items[r->item_count].name, p.name);
    r->item_count++;
    r->value += p.price;
}

void print_reciept(Reciept *r) {
    printf("-------------------------------\n");
    printf("Customer: %s\n--------------\n", r->customer->name);
   
    printf("Product\t\tPrice\n--------------\n");
    for(int i =0; i <r->item_count; i++) {
        printf("%s\t\t%d\n", r->items[i].name, r->items[i].price);
    }
    printf("-----------------\n");
    printf("Total Value: %f\n", r->value);
    printf("-----------------\n");
}

int main() {

    Database db;
    db.customer_count = db.reciept_count = 0;
    // int i = UPI;

    // printf("%d %d\n", sizeof(db), sizeof(&db));

    while(true) {

        // system("@cls||clear"); // clears the screen

        printf("-------------------------------------------------------------------\n"
               "Store Reciept Management System\n"
               "-------------------------------------------------------------------\n"
               "\tOptions: 0 New Receipt | 1 New Customer | 2 Reciepts by Customer \n"
               "\tStats: %d Customers | %d Reciepts\n"
               "-------------------------------------------------------------------\n"
               "Enter Option: ", db.customer_count, db.reciept_count);
        
        int option;
        scanf("%d", &option);

        int p, v, m;
        Customer* c = NULL;
        char name[100];
        switch (option)
        {
            case 0:
                printf("Enter Customer Phone: ");
                scanf("%d", &p);
                c = find_customer_by_phone_no(p, &db); 
                if (c == NULL) {
                    printf("(New Customer) Name: ");
                    scanf("%s", name);
                    c = add_customer(name, p, &db);
                }
                printf("Payment Mode (0 for Cash, 1 for Card, 2 for UPI): ");
                scanf("%d", &m);

                Reciept* r = add_reciept( c, m, &db);

                int num_items=0, item_price;
                char item_name[100];
                printf("Enter number of items in the reciept: ");
                scanf("%d", &num_items);
                for(int i=0; i < num_items; i++) {
                    Product cur_item;
                    printf("Enter item name: ");
                    scanf("%s", &(cur_item.name));
                    printf("Enter item price: ");
                    scanf("%d", &(cur_item.price));
                    add_item_to_reciept(cur_item, r);
                }
                print_reciept(r);
                break;

            case 1:
                printf("Enter Customer Phone: ");
                scanf("%d", &p);
                c = find_customer_by_phone_no(p, &db); 
                if (c == NULL) {
                    printf("(New Customer) Name: ");
                    scanf("%s", name);
                    c = add_customer(name, p, &db);
                }
                break;

            case 2:
                // input a phone nom
                printf("Enter Customer Phone: ");
                scanf("%d", &p);
                c = find_customer_by_phone_no(p, &db); 

        
                // print out all reicepts curresponding to that customer.
                    printf("No.\tValue\n"
                            "--------------------------\n");
                for(int i =0; i< db.reciept_count; i++) {

                    if (db.reciepts[i].customer == c) {
                        printf("%d\t%f\n", i, db.reciepts[i].value);
                    }
                }

                    printf("----------------------\n");
            
            default:
                break;
        }


    }

    return 0;
}