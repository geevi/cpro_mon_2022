/* Consider all arrangements of $k$ items
   from $n$ objects. For $n=3, k=2$, they
   are $12, 21,13,31,23,32$. The number
   of such arrangements is 
   $^nP_k = n(n-1)\cdots(n-k+2)(n-k+1).$ 
   Bellow is a program which when given $n,k$
   as input, prints all arragements of $k$
   items from $n$ objects.               */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int** PermList;

int count_arrangements(int n, int k) {
  // Problem 1 a.) write a recursive 
  // function logic here in one line to 
  // compute the number of all arragements 
  // of $k$ items from $n$ objects. (2 marks)
}

PermList create_perm_list(int n, 
                                 int k) {
  int fn = count_arrangements(n, k);
  PermList pl=malloc(fn*sizeof(int *));
  for(int i =0; i < fn ;i++) {
    pl[i] = malloc(n*sizeof(int)); 
  }
  return pl;
}
void destroy_perm_list(PermList pl, 
                       int n, int k) {
  int fn = count_arrangements(n, k);
  for (int i =0; i < fn ;i++) {
    free(pl[i]); 
  }
  free(pl);
}

// given a `small_row` of size `size`
// copies it to `big_row` which has size 
// `size+1`. Also sets the last position 
// in `big_row` to `e`
void insert_and_copy(int* small_row, int size, 
                     int e, int* big_row) {
  for (int i = 0; i < size; i++) {
    big_row[i] = small_row[i];
  }
  big_row[size] = e;
}

// checks if `e` is in the `row` of size `size`
bool find(int e, int* row, int size) {
  for(int i = 0; i < size; i++) {
    if (row[i] == e) {
      return true;
    }
  }
  return false;
}
// find the numbers from $\{1,\ldots, n\}$
// that are not in `row` which is of size `k`
// and puts them in `elements`
void find_elements_not_in_row(int* row, int n, 
                              int k, 
                              int* elements) {
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (find(i+1, row, k) == false) {
      elements[c++] = i+1;
    }
  }
}

PermList enumerate_arrangements(
                        int n, int k) {
  PermList B = create_perm_list(n,k);
  if (k == 1) {
    // Problem 1 b.) write code here for base 
    // case of recursively building list `B` 
    // of all arrangements of $k=1$ items 
    // from $\{1,..,n\}.$ (3 marks)
  } else { 
    // Problem 1 c.) write code here for 
    // recursively building list `B` of all
    //  arrangements of $k$ items from 
    // $\{1,..,n\}.$ (5 marks)
  }
  return B;
}
void print_perm_list(PermList pl, 
                     int n, int k) {
  int fn = count_arrangements(n, k);
  for(int i = 0; i < fn;i++) {
    for (int j =0; j <k; j++) {
      printf("%d ", pl[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int n = 10;
  int k = 5;
  print_perm_list(
        enumerate_arrangements(n, k),n,k);
  return 0;
}