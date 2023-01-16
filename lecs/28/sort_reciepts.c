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


typedef struct Reciept {
    time_t time;
    float value;
    // Customer *customer;
    PayMode mode;
} Reciept;


void copy_array(Reciept *A, int start, int end, Reciept *B) {
    for(int i = start; i < end; i++) {
        B[i-start] = A[i];
    }
}
void reciept_merge(Reciept *L, int sL, Reciept* R, int sR, Reciept *A) {

    int l = 0, r = 0, c = 0;

    while(c <= sL + sR -1) {
        if (r == sR  ) {
            A[c++] = L[l++];
            continue;
        }

        if (l == sL ) {
            A[c++] = R[r++];
            continue;
        }

        if (L[l].time < R[r].time) {
            A[c++] = L[l++];
        } else if (L[l].time >= R[r].time) {
            A[c++] = R[r++];
        }
    }

}

void sort_reciepts(Reciept* A, int len) {
    if (len == 1) {
        return;
    } else {
        int mid = len/2;
        Reciept L [ mid], R [ len - mid ];
        copy_array(A, 0, mid, L);
        copy_array(A, mid, len, R);
        sort_reciepts(L, mid);
        sort_reciepts(R,len - mid);
        reciept_merge(L, mid, R, len-mid, A);
    }   
}

int main() {
    Reciept r[] = {
        {
            .time = 25000,
            .value = 100
        },
        {
            .time = 6000,
            .value = 50
        }
    };
    sort_reciepts(r, 2);
    for(int i =0; i<2; i++){
        printf("%d\t%d\n", r[i].time,r[i].value);
    }
}






