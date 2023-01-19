#include "srms.h"




int main() {
    Database db;
    db.customer_count = db.reciept_count = 0;

    int a = add_customer("Alice",12345,&db);

    add_reciept(1000, a, Cash, &db);
    add_reciept(500, a, UPI, &db);

    int b = add_customer("Bob",5678,&db);

    add_reciept(700, b, Card, &db);
    add_reciept(500, b, UPI, &db);

    FILE* cus_file = fopen("customers.bin", "w");

    fwrite(&(db.customer_count), sizeof(int), 1, cus_file);
    fwrite(db.customers, sizeof(Customer), db.customer_count, cus_file);

    FILE* res_file = fopen("reciepts.bin", "w");

    fwrite(&(db.reciept_count), sizeof(int), 1, res_file);
    fwrite(db.reciepts, sizeof(Reciept), db.reciept_count, res_file);

    fclose(res_file);
    fclose(cus_file);



}