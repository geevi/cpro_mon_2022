
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

void setup_ABCDE_network(SocialNet *sn) {

    strcpy(sn->members[0].name, "Alice");
    sn->members[0].age = 24;
    strcpy(sn->members[1].name, "Bob");
    sn->members[1].age = 22;
    strcpy(sn->members[2].name, "Charlie");
    sn->members[2].age = 28;
    strcpy(sn->members[3].name, "Dale");
    sn->members[3].age = 26;
    strcpy(sn->members[4].name, "Earl");
    sn->members[4].age = 30;
    sn->size=5;
    
    sn->members[0].friends[0] = &(sn->members[3]);
    sn->members[0].friends[1] = &(sn->members[4]);
    sn->members[0].count_friends=2;

    sn->members[1].friends[0] = &(sn->members[0]);
    sn->members[1].count_friends=1;

    sn->members[2].friends[0] = &(sn->members[3]);
    sn->members[2].count_friends=1;
    sn->members[3].friends[0] = &(sn->members[0]);
    sn->members[3].friends[1] = &(sn->members[4]);
    sn->members[3].count_friends=2;
    sn->members[4].friends[0] = &(sn->members[0]);
    sn->members[4].friends[1] = &(sn->members[3]);
    sn->members[4].count_friends=2;

}

int main()
{
    SocialNet sn;   
    sn.size = 0;
    setup_ABCDE_network(&sn);
    
    print_network(&sn);

    
    return 0;
}
