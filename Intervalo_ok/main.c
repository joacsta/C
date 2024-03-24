#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
Define em qual intervalo esta o valor
designado pelo usuario
*/

int main()
{
    double valor;
    scanf("%lf", &valor);

    if(0<= valor && valor <=25.0)
    {
        printf("Intervalo [0,25]\n");
    }
    else if(25.0< valor && valor <=50.0)
    {
        printf("Intervalo (25,50]\n");
    }
    else if (50.0< valor && valor <=75.0)
    {
        printf("Intervalo (50,75]\n");
    }
    else if (75.0< valor && valor <=100.0)
    {
        printf("Intervalo (75,100]\n");
    }
    else
    {
        printf("Fora de intervalo\n");
    }
    return 0;
}
