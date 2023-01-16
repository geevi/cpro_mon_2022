
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Person {
    char name[100];
    int age;
    int count_friends;
    struct Person *friends[5];
};

typedef struct SocialNet {
    struct Person members[100];
    int size;
} SocialNet;


void print_person(struct Person p) {
    printf("%s\t\t%d \t", p.name, p.age);
    for(int i = 0; i < p.count_friends; i++) {
        printf("%s, ", (p.friends[i])->name);
    }
    printf("\n");
}

void print_network(SocialNet *sn) {
    printf(
        "----------------------------------------------\n"
        "Name\t\tAge \tFriends\n"
        "----------------------------------------------\n");
    for (int i=0;i <5; i++) {
        print_person(sn->members[i]);
        
    }
    printf("----------------------------------------------\n");

}

struct Person * find_person(char* name1, SocialNet *sn) {
    struct Person* p = NULL;
    for(int i = 0; i < sn->size; i++) {
        if (strcmp(sn->members[i].name, name1) == 0) {
            p = &(sn->members[i]);
        }
    }
    return p;
}

bool check_mutual_friends(char *name1, char *name2, SocialNet *sn) {
    struct Person *p1 = find_person(name1, sn);
    struct Person *p2 = find_person(name2, sn);


    // HW

}


int main()
{
    SocialNet sn;   
    sn.size = 0;
    
    
    
    
    // setup_ABCDE_network(&sn);
    
    print_network(&sn);

    
    return 0;
}
