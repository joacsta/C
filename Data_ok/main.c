#include <stdio.h>
#include <stdlib.h>
#define tam_data 9

int main()
{
    char data[10];

    scanf(" %[^\n]s",data);
    printf("\n");

    printf("%c%c%c", data[3], data[4], data[5]);
    printf("%c%c%c", data[0], data[1], data[2]);
    printf("%c%c ", data[8], data[9]);
    printf("- M / D / A\n");

    printf("%c%c%c", data[8], data[9], data[5]);
    printf("%c%c%c", data[3], data[4], data[2]);
    printf("%c%c ", data[0], data[1]);
    printf("- A / M / D\n");

    printf("%c%c/", data[0], data[1]);
    printf("%c%c/", data[3], data[4]);
    printf("%c%c ", data[8], data[9]);
    printf("- D / M / A\n");

    return 0;
}
