
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    printf(
        "----------------------------------------------\n"
        "Name: %s\tAge: %d\nFriends: \t", p.name, p.age);
    for(int i = 0; i < p.count_friends; i++) {
        printf("%s ", (p.friends[i])->name);
    }
    printf("\n");
}

int main()
{
    SocialNet sn;   
    sn.size = 0;
    
    strcpy(sn.members[0].name, "Alice");
    sn.members[0].age = 24;
    strcpy(sn.members[0].name, "Bob");
    sn.members[1].age = 22;
    strcpy(sn.members[0].name, "Charlie");
    sn.members[2].age = 28;
    strcpy(sn.members[0].name, "Dale");
    sn.members[3].age = 26;
    strcpy(sn.members[0].name, "Earl");
    sn.members[4].age = 30;
    
    sn.members[0].friends[0] = &sn.members[3];
    sn.members[0].friends[1] = &sn.members[4];
    sn.members[0].count_friends=2;

    sn.members[1].friends[0] = &sn.members[0];
    sn.members[1].count_friends=1;

    sn.members[1].friends[0] = &sn.members[0];
    sn.members[1].count_friends=1;



    for (int i=0;i <5; i++) {
        print_person(directory[i]);
    }


    
    return 0;
}
