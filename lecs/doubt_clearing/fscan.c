#include <stdlib.h>

#include <stdio.h>

int main()  {

    FILE* f = fopen("srms.c", "r");

    char word[100], next_word[100];
    while(fscanf(f, "%s %s", word, next_word)== 2) {
        printf("%s\n", word);
    }
    




    return 0;
}
