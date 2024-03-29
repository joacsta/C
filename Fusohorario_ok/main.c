#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
Tem finalidade de calcular o hor�rio em um determinado
fuso hor�rio, levando em considera��o a hora de sa�da
e o tempo de viagem.
*/

int main()
{
    int saida, tempo, fuso, resultado;

    // Leitura dos valores de entrada
    scanf("%d %d %d", &saida, &tempo, &fuso);

    // Verifica se a hora de sa�da � menor ou igual a 23
    if (saida <= 23)
    {
        // Calcula o hor�rio de chegada somando a hora de sa�da, o tempo de viagem e o fuso hor�rio
        resultado = saida + tempo + fuso;
    }
    else
    {
        // Caso a hora de sa�da seja maior que 23, calcula o hor�rio de chegada levando em considera��o o fuso hor�rio
        resultado = (saida + tempo - fuso) % 24;
    }

    // Imprime o hor�rio de chegada
    printf("%d\n", resultado);

    return 0;
}
