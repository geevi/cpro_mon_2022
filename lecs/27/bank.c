
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
    int aadhar_no;
    int initial_deposit; // the deposit at the starting of the account
    AccountType type;
    Transaction* passbook[1000]; // passbook is an array of transactions
} BankAccount;

typedef struct Transaction {
    TransactionType type;
    BankAccount* from;
    BankAccount* to;
    int amount;
} Transaction;

typedef struct BankDatabase {

};



