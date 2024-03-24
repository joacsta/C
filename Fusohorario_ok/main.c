#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
Tem finalidade de calcular o horário em um determinado
fuso horário, levando em consideração a hora de saída
e o tempo de viagem.
*/

int main()
{
    int saida, tempo, fuso, resultado;

    // Leitura dos valores de entrada
    scanf("%d %d %d", &saida, &tempo, &fuso);

    // Verifica se a hora de saída é menor ou igual a 23
    if (saida <= 23)
    {
        // Calcula o horário de chegada somando a hora de saída, o tempo de viagem e o fuso horário
        resultado = saida + tempo + fuso;
    }
    else
    {
        // Caso a hora de saída seja maior que 23, calcula o horário de chegada levando em consideração o fuso horário
        resultado = (saida + tempo - fuso) % 24;
    }

    // Imprime o horário de chegada
    printf("%d\n", resultado);

    return 0;
}
