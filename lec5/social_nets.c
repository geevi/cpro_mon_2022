
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Person {
    char name[100];
    int age;
    float height;
    float weight;
} Person;


void print_person(Person p) {
    printf("Name: %s\tAge: %d\t\tHeight: %f\tWeight: %f\n", p.name, p.age, p.height, p.weight);
}


// Problem 1
// int find_index_of_person_with_name(char *name, Person *directory) {
//     // fill code here which find the index of the person
//     // with a specified name in the directory
// }


// Problem 2
// int* find_indices_with_weight_in_range(float min_wt, float max_wt, Person *directory) {
//     // fill code here which find the indices of the persons
//     // whose wt is between min_wt and max_wt in the directory
//     // you need to find a way to return all the indices from the function.
// }


// Problem 3
// void sort_directory_by_name(Person *directory) {
//     // fill code here to sort the directory, by name of the person
//     // sorting algorithm taught in class could be suitably modified for this purpose
// }   // you will also need to check if a string is lexicographically smaller/larger
       // see: https://codeforwin.org/2015/11/c-program-to-compare-two-strings.html

int main()
{
    Person directory[5] = {
        {"Ivan", 24,  5.4, 58.4},
        {"Kiri", 22,  4.8, 52.8},
        {"Jake", 28, 6.2, 64.3},
        {"Alice", 26, 5.8, 61.2},
        {"Bob", 30, 5.5, 68.6}
    };
    for (int i=0;i <5; i++) {
        print_person(directory[i]);
    }


    
    return 0;
}
