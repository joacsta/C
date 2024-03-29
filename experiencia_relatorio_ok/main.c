#include <stdio.h>
#include <stdlib.h>

// Fun��o para imprimir o relat�rio com os totais e percentuais
void relatorio(int total_coelho, int total_rato, int total_sapo)
{
    // Imprime o total de cobaias
    printf("Total: %d cobaias\n", total_coelho + total_rato + total_sapo);
    // Imprime o total de cada tipo de cobaia
    printf("Total de coelhos: %d\n", total_coelho);
    printf("Total de ratos: %d\n", total_rato);
    printf("Total de sapos: %d\n", total_sapo);
    // Calcula e imprime o percentual de cada tipo de cobaia
    printf("Percentual de coelhos: %.2f\n", total_coelho * 100.0 / (total_coelho + total_rato + total_sapo));
    printf("Percentual de ratos: %.2f\n", total_rato * 100.0 / (total_coelho + total_rato + total_sapo));
    printf("Percentual de sapos: %.2f\n", total_sapo * 100.0 / (total_coelho + total_rato + total_sapo));
}

/*
Dentro da fun��o, s�o realizados c�lculos para determinar os percentuais de
cada tipo de cobaia em rela��o ao total de cobaias. Em seguida, esses valores s�o
formatados e impressos na sa�da padr�o de acordo com o formato especificado.
*/

int main()
{
    int n, quant_cobaias;
    char tipo_cobaia;
    int i, total_coelho = 0, total_rato = 0, total_sapo = 0;

    // Entrada de dados
    // 1) N�mero de testes
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        // 2) Quantidade e tipo de cobaias para cada teste
        scanf("%d", &quant_cobaias);
        scanf(" %c", &tipo_cobaia); // Espa�o antes do %c para ignorar espa�os em branco

        // Atualiza os totais com base no tipo de cobaia
        switch (tipo_cobaia)
        {
        case 'C':
        case 'c':
            total_coelho += quant_cobaias;
            break;
        case 'R':
        case 'r':
            total_rato += quant_cobaias;
            break;
        case 'S':
        case 's':
            total_sapo += quant_cobaias;
            break;
        }

        // Imprime o relat�rio atualizado
        relatorio(total_coelho, total_rato, total_sapo);
    }

    return 0;
}
