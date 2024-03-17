#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Função para converter um número inteiro para binário e imprimir
void inttobin(int num)
{
    if (num == 0)
    {
        printf("0");
        return;
    }

    int result[32];
    int i = 0;

    for (; num > 0;)
    {
        result[i] = num % 2;
        i++;
        num /= 2;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", result[j]);
    }
}

int main()
{
    int N, num;
    char X[100];
    char Y[30];

    printf("selecione o numero de casos: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        printf("\nforneca o numero e indique a sua representacao\n|b| para binario\n|d| para decimal\n|h| para hexadecimal\n\nnumero e indicacao: ");
        scanf("%s %s", X, Y);
        printf("\n|Caso %d|\n", i + 1);

        if (Y[0] == 'b')
        {
            num = (int)strtol(X, NULL, 2);
            printf("binario: ");
            inttobin(num);
            printf("\n");
            printf("decimal: %d\n", num);
            printf("hexa: %x\n", num);
        }
        else if (Y[0] == 'd')
        {
            num = (int)strtol(X, NULL, 10);
            printf("decimal: %d\n", num);
            printf("hexa: %x\n", num);
            printf("binario: ");
            inttobin(num);
            printf("\n");
        }
        else if (Y[0] == 'h')
        {
            num = (int)strtol(X, NULL, 16);//conversao de string para numero
            printf("hexa: %x\n", num);
            printf("decimal: %d\n", num);
            printf("binario: ");
            inttobin(num);
            printf("\n");
        }
        else
        {
            printf("Invalido\n\n");
        }
    }

    return 0;
}
