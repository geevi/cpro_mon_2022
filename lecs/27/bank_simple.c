// Code for ATM Banking
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum AccountType {
    Savings,
    Current
} AccountType;

typedef enum TransactionType {
    Credit,
    Debit
} TransactionType;

typedef struct BankAccount {
    char name[100];
    int pin;
    AccountType type;
    Transaction* passbook[1000]; 
} BankAccount;

typedef struct Transaction {
    TransactionType type;
    BankAccount* account;
    int amount;
} Transaction;

typedef struct BankDatabase {
    BankAccount accounts[1000];
    Transaction transactions[10000];
    int accounts_count;
    int transactions_count;
} BankDatabase;


int main() {

    BankDatabase db;
    db.accounts_count = db.transactions_count = 0;
  
    while(true) {

        // system("@cls||clear"); // clears the screen

        printf("-------------------------------------------------------------------\n"
               "\tATM Banking\n"
               "-------------------------------------------------------------------\n"
               "\t\tOptions: 0 Create New account | 1 Login \n"
               "\t\tStats: %d Accounts | %d Transactions\n"
               "-------------------------------------------------------------------\n"
               "Enter Option: ", db.accounts_count, db.transactions_count);
        
        int option;
        scanf("%d", &option);
        switch (option) {
            case 0:
                char name[100];
                int pin;
                AccountType type;
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter pin: ");
                scanf("%d", &pin);
                printf("Enter account type (0 for Current | 1 for Savings): ");
                scanf("%d", &type);
                create_account(name, pin, type, &db);
                break;
            case 1:
                printf("Enter name: ");
                scanf("%s");
                printf("Enter pin: ");
                scanf("%d");
                logged_in
                
                




                break;
            
        }

    }


}


