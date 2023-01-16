

typedef int** ListOfStrings;

ListOfStrings create_list(int n, int k) {
    ListOfStrings pl = malloc(n*sizeof(int *));
    for(int i =0; i < n ;i++) {
        pl[i] = malloc(k*sizeof(int)); 
    }
    return pl;
}

void destroy_list(ListOfStrings pl, 
                       int n, int k) {
    for(int i =0; i < n ;i++) {
        free(pl[i]); 
    }
    free(pl);
}




ListOfStrings arrange_multiset(int n, int A[n]) {
    int k = sum(A);
    int m = compute_no_arrangements(n, A);
    ListOfStrings B = create_list(m, n);
    if (k == 1) {
        int element;
        for(int i=0; i< n;i++) {
            if(A[i] ==1) {
                element = i;
                break;
            }
        }


    } else {

        for(int i = 0; i<n; i++) {
            if(A[i] >0) {
                //Ap = A with ith count decrementedd by 1



                ListOfStrings C = arrange_multiset(n, Ap)

                /// logic


                destroy_list(C);
            }
        }

    }

    return B;

}