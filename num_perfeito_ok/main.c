#include <stdio.h>

/**Este código em C tem o objetivo de verificar se um
número é perfeito ou não. Um número perfeito é aquele
cuja soma de todos os seus divisores próprios é igual
ao próprio número.*/

int main ()
{

    int n, x, i, k, soma = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        for (k = 1; k < x; k++)
        {
            if (x % k == 0)
            {
                soma += k;
            }
        }
        if ( soma == x)
        {
            printf("%d eh perfeito\n", x);
        }
        else
        {
            printf("%d nao eh perfeito\n", x);
        }
        soma = 0;
    }
    return 0;
}
