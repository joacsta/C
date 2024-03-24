#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
O programa permite que o usuário escolha
um produto por meio de um código numérico,
insira a quantidade desejada e calcula
o valor total a ser pago com base nessa
escolha.
*/
int main()
{
    double QUANT, VALOR, R;

    scanf("%lf %lf", &VALOR, &QUANT);

    if (VALOR== 1)
    {
        R= (4) * QUANT;
        printf("Total: R$ %.2lf\n", R);
    }
    else

        if (VALOR== 2)
        {
            R= (4.50) * QUANT;
            printf("Total: R$ %.2lf\n", R);
        }
        else

            if (VALOR== 3)
            {
                R= (5)* QUANT;
                printf("Total: R$ %.2lf\n", R);
            }
            else

                if (VALOR== 4)
                {
                    R= (2) * QUANT;
                    printf("Total: R$ %.2lf\n", R);
                }
                else if (VALOR== 5)
                {
                    R= (1.5) * QUANT;
                    printf("Total: R$ %.2lf\n", R);

                }
                else

                    return 0;
}
