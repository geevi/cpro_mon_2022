#include "stdio.h"


int factorial(int x) {
    int f = 1;
    for(int i =x; x>=1; x--) {
        f = f*x;
    }
    return f;
}

int recursive_factorial(int x) {

    // if(x==1) {
    //     return 1;
    // } else {
    //     return x*recursive_factorial(x-1);
    // }

    return x==1? 1 : x*recursive_factorial(x-1);
}

int main() {

    int n = 5;

    printf("%d\n",recursive_factorial(n));
    return 0;
}