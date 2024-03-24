#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,resto;

    scanf("%d", &x);
    for(y=1; y < x+1; y++)
    {
        resto = x%y;
        if(resto == 0){
        printf("%d\n", y);
        }
    }
return 0;
}

