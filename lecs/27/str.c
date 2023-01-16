
#include <string.h>
#include <time.h>
#include <stdio.h>

char* fn_returning_string() {
   time_t rawtime;
   struct tm *info;
   time( &rawtime );
   info = localtime( &rawtime );
   return asctime(info);
}




int main() {

    char str[10][100];
    for(int i =0; i<10; i++) {
        strcpy(str[i], fn_returning_string());
    }


    for(int i =0; i<10; i++) {
        printf("%s\n", str[i]);
    }
}