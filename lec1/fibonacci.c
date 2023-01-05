#include "stdio.h"

int fibonacci(int n) {
    int a = 0, b = 1;
    int f = 0;
    if(n==0) {
        f = a;
    } else if (n==1) {
        f = b;
    } else {
        
        for(int i = 2; i <= n; i++) {
            f = a + b;
            a = b;
            b = f;
        }
    }
    return f;
}


int rec_fib(int n) {
    if (n==0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return rec_fib(n-1) + rec_fib(n-2);
    }
    // return n <= 1? n: return rec_fib(n-1) + rec_fib(n-2);
}

int main() {
    int n = 50;
    for(int i = 0; i <= n; i++) {
        printf("%d\n", rec_fib(i));
    }
    return 0;
}