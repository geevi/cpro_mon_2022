#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void copy_array(char** A, int start, int end, char** B) {
    for(int i = start; i < end; i++) {
        strcpy(B[i-start], A[i]);
    }
}
void merge(char** L, int sL, char** R, int sR, char** A) {

    int l = 0, r = 0, c = 0;

    while(c <= sL + sR -1) {
        if (r == sR  ) {
            strcpy(A[c++], L[l++]);
            continue;
        }

        if (l == sL ) {
            strcpy(A[c++], R[r++]);
            continue;
        }

        if (strcmp(L[l], R[r]) < 0) {
            strcpy(A[c++], L[l++]);
        } else {
            strcpy(A[c++], R[r++]);
        }
    }

}

void sort_strings(char** A, int len) {
    if (len == 1) {
        return;
    } else {
        int mid = len/2;
        char L [ mid][10], R [ len - mid ][10];
        copy_array(A, 0, mid, (char**)L);
        copy_array(A, mid, len, (char **)R);
        sort_strings((char**) L, mid);
        sort_strings((char**)R,len - mid);
        merge((char**)L, mid, (char**)R, len-mid, A);
    }   
}

int main() {
    char r[3][10] = {
        "Ivan",
        "Kiri",
        "Jake"
    };

    char** a;
    a = malloc(3*sizeof(char*));
    for (int i =0; i< 3;i++) {
        a[i] = malloc(10*sizeof(char));
        strcpy(a[i], r[i]);
    }
    
    sort_strings(a, 3);
    for(int i =0; i<3; i++){
        printf("%s\n", r[i]);
    }

}






