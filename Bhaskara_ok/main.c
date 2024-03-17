#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double A, B, C, Delta, Resultado1, Resultado2;

    //calculo de delta e bhaskara

    scanf("%lf %lf %lf", &A, &B, &C);
        Delta = ((B*B) - (4*A*C));
            if (Delta<0 || A<=0)
            {
                printf("Impossivel calcular\n");
            }
            else
            {
                Resultado1= ((-B) + sqrt(Delta))/(2*A);
                Resultado2= ((-B) - sqrt(Delta))/(2*A);
                printf("R1 = %.lf\nR2 = %.lf\n", Resultado1, Resultado2);
            }
    return 0;
}
