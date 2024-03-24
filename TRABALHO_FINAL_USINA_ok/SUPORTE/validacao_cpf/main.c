#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#define TAM_CPF 11

void validacao_cpf(const char* str)
{
    char cpf[TAM_CPF];
    int tamanho = strlen(str);
    int j = 0;
    int icpf[TAM_CPF];
    int i, digito1, digito2,somador = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (isdigit(str[i]))
        {
            cpf[j] = str[i];
            j++;
        }
    }
    cpf[j] = '\0';

    for (i = 0; i < TAM_CPF; i++)
    {
        icpf[i] = cpf[i] - '0';
    }

    // Cálculo do primeiro dígito
    somador = icpf[0] * 10 + icpf[1] * 9 + icpf[2] * 8 + icpf[3] * 7 +
              icpf[4] * 6 + icpf[5] * 5 + icpf[6] * 4 + icpf[7] * 3 +
              icpf[8] * 2;

    digito1 = (somador % 11) < 2 ? 0 : 11 - (somador % 11);

    // Cálculo do segundo dígito
    somador = icpf[0] * 11 + icpf[1] * 10 + icpf[2] * 9 + icpf[3] * 8 +
              icpf[4] * 7 + icpf[5] * 6 + icpf[6] * 5 + icpf[7] * 4 +
              icpf[8] * 3 + digito1 * 2;

    digito2 = (somador % 11) < 2 ? 0 : 11 - (somador % 11);

    if (digito1 == icpf[9] && digito2 == icpf[10])
    {
        printf("CPF válido.\n");
    }
    else
    {
        printf("CPF inválido.\n");
    }
}

int main()
{
    setlocale(LC_CTYPE, "Portuguese");

    char cpf[15];

    printf("Digite o CPF: ");
    scanf(" %[^\n]", cpf);

    validacao_cpf(cpf);

    return 0;
}
