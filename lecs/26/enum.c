// Sample explaining enums
#include <stdio.h>

typedef enum Weekday {
    Sunday=5,
    Monday=10,
    Tuesday=11,
    Wednesday,
    Thursday=-5,
    Friday,
    Saturday
} Weekday;

int main() {

    Weekday today = Wednesday;
    printf("Day %d\n",today);
    printf("Size of enum variable = %d bytes\n",sizeof(today));
    scanf("%d", &today);
    printf("Day %d\n",today+1);
 
    return 1;
}