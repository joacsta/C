#include <stdio.h>

/**
O programa l� um vetor de inteiros,
encontra o menor valor presente neste
vetor e imprime esse valor e sua posi��o.
*/

int main(void)
{

    int N;
    scanf("%d", &N);
    int v[N];
    int menor;
    int posicao;
    int i;

    scanf("%d", &v[0]); //n�mero de vetores
    posicao = 0;
    menor = v[0];

    for (i = 1; i < N; i++ )
    {
        scanf("%d", &v[i]);
        if (v[i] < menor)
        {
            menor = v[i];
            posicao = i;
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);


}
