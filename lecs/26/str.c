#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("%d\n", strcmp("a","abc"));

    char s2[100] = "pqrst";

    printf("s2 is %s and its length is %d, and the size is %d\n",s2,strlen(s2), sizeof(s2));

    // Concatenate s2 with s and store in s2
    strcat(s2, s);
    printf("s2 is now %s and its len is %d\n",s2, strlen(s2));

    // compare strings s, p
    printf("strcmp(p,s) %d \tstrcmp(s,p) %d\tstrcmp(p,p) %d\n", strcmp(p,s), strcmp(s,p), strcmp(p,p) );

    // // copy s into s2
    strcpy(s2, s);
    printf("s2 is now %s and its len is %d\n",s2, strlen(s2));


    return 0;
}
