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
    // passbook is an array of transactions
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

int compute_balance(char* name, BankDatabase *db) {

    // fll in the code to find the balance of the 
    // account of the person with name 'name' in 'db'
}

Transaction* add_transaction(TransactionType type, 
                             BankAccount *account, 
                             int amount, BankDatabase* db) {

    // Fill the logic

}


