#include <stdio.h>
#include <stdlib.h>

int main()
//NESTE CODIGO FAREMOS UM CONTADOR DE FIBBONACCI
{
    int x, y, a=0, b=1, c=0;
    scanf("%d", &x);
    for (y=1; y<x; y++)  //FOR (inicio; final; como vai chegar ao final)
        // Y é tipo o contador aqui
    {
        if(y%2==1)
        {
            printf ("%d ", c);
            c = a+b;
            a= c;
        }
        else if(y==2)
        {
            printf("%d ",c);
        }
        else if (y%2==0)
        {
            printf("%d ",c);
            c= a+b;
            b= c;
        }
    }
    printf ("%d\n",c);
    return 0;
}
