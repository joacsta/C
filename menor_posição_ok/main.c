#include <stdio.h>

/**
O programa lê um vetor de inteiros,
encontra o menor valor presente neste
vetor e imprime esse valor e sua posição.
*/

int main(void)
{

    int N;
    scanf("%d", &N);
    int v[N];
    int menor;
    int posicao;
    int i;

    scanf("%d", &v[0]); //número de vetores
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
