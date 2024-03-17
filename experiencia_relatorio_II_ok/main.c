#include <stdio.h>
#include <stdlib.h>

void relatorio (int tc, int tr, int ts)
{
    printf("Total: %d cobaias\n", tc+tr+ts);
    printf("Total de coelhos: %d\n", tc);
    printf("Total de ratos: %d\n", tr);
    printf("Total de sapos: %d\n", ts);
    printf("Percentual de coelhos: %.2f%% \n", tc * 100.0 / (tc + tr + ts));
    printf("Percentual de ratos: %.2f%% \n", tr * 100.0 / (tc + tr + ts));
    printf("Percentual de sapos: %.2f%% \n", ts * 100.0 / (tc + tr + ts));
}

int main()
{

    //Declaração de variáveis
    int n; // n indica a quantidade de valores de entrada
    int quantidade_cobaias;
    char tipo_cobaia;
    int i; //Controlar as repetições do for
    int total_coelhos=0;
    int total_ratos=0;
    int total_sapos=0;

    //Instruções
    //1) Entrada de dados
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    for (i=1; i<=n; i++)
    {
        printf("Digite a quantidade de cobaias: ");
        scanf("%d", &quantidade_cobaias);
        printf("Digite o tipo de cobaia: ");
        scanf(" %c ", &tipo_cobaia);

        switch (tipo_cobaia)
        {
        case 'C':
        case 'c':
            total_coelhos = total_coelhos + quantidade_cobaias;
            break;
        case 'R':
        case 'r':
            total_ratos = total_ratos + quantidade_cobaias;
            break;
        case 'S':
        case 's':
            total_sapos = total_sapos + quantidade_cobaias;
            break;
        }
    }

    relatorio(total_coelhos, total_ratos, total_sapos);

    return 0;
}
