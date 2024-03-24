#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define tam_cpf 12

void validacao_cpf(const char *str)
{
int tamanho = strlen(str);
char cpf[tam_cpf];
int j = 0;
int icpf[tam_cpf];
int i, somador = 0, digito1, digito2, result1, result2, valor;

for (int i = 0; i < tamanho; i++)
{
    if (isdigit(str[i]))
    {
        cpf[j] = str[i];
        j++;
    }
}

cpf[j] = '\0';

for(i=0; i<11; i++)
{
    icpf[i]=cpf[i]-48;
}
for(i=0; i<9; i++)
{
    somador += icpf[i]*(10-i);
}
result1 = somador%11;

if ( (result1==0)||(result1==1))
{
    digito1 = 0;
}
else
{
    digito1 = 11-result1;
}

somador = 0;

for(i=0; i<10; i++)
{
    somador+=icpf[i]*(11-i);
}
valor = (somador/11)*11;
result2 = somador - valor;

if ((result2==0)||(result2==1))
{
    digito2=0;
}
else
{
    digito2 = 11-result2;
}

if((digito1 == icpf[9])||(digito2 == icpf[10]))
{
    printf ("cpf validado.");
}
else
{
    printf("cpf invalido");
}
}

int main() {
    char texto[100];

    printf("Digite um cpf: ");
    fgets(texto, sizeof(texto), stdin);

    validacao_cpf(texto);

    return 0;
}
