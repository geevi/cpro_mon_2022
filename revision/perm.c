#include <stdio.h>
#include <stdlib.h>

typedef int** PerumationList;

int fact(int n) {
    return n==1? n : n*fact(n-1);
}

PerumationList create_perm_list(int n) {
    int fn = fact(n);
    int** pl = malloc(fn*sizeof(int *));
    for(int i =0; i < fn ;i++) {
        pl[i] = malloc(n*sizeof(int)); 
    }
    return pl;
}

void destroy_perm_list(PerumationList pl, int n) {
    int fn = fact(n);
    for(int i =0; i < fn ;i++) {
        free(pl[i]); 
    }
    free(pl);
}


void insert_and_copy(int* RA, int sA, int pos, int* RB) {
    int i = 0;
    while(i <= sA) {
        if (i < pos) {
            RB[i] = RA[i];
        } else if (i==pos) {
            RB[i] = sA+1;
        } else if (i > pos) {
            RB[i] = RA[i-1];
        }
        i++;
    }
}


PerumationList perm(int n) {
    PerumationList B = create_perm_list(n);
    if (n == 1) {
        B[0][0] = 1;
    } else {
        int** A = perm(n-1);
        int fnm1 = fact(n-1);
        int c = 0;
        for(int r = 0; r < fnm1; r++) {
            for(int p =0; p < n; p++) {
                insert_and_copy(A[r], n-1, p, B[c]);
                c++;
            }
        }
        destroy_perm_list(A, n-1); 
    }
    return B;
}

void print_perm_list(PerumationList pl, int n) {
    int fn = fact(n);
    for(int i = 0; i < fn;i++) {
        for (int j =0; j <n; j++) {
            printf("%d ", pl[i][j]);
        }
        printf("\n");
    }
}



int main() {
    int n = 10;
    print_perm_list(perm(n),n);
    return 0;


}