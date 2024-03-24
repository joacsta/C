#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_CNPJ 19

void validacao_cnpj(const char *str) {
    int tamanho = strlen(str);
    char cnpj[TAM_CNPJ];
    int j = 0;
    int icnpj[TAM_CNPJ];
    int i, digito1, digito2, result1, result2, valor, somador = 0;

    for (int i = 0; i < tamanho; i++) {
        if (isdigit(str[i])) {
            cnpj[j] = str[i];
            j++;
        }
    }

    cnpj[j] = '\0';
    printf("%s\n", cnpj);

    for (i = 0; i < 14; i++) {
        icnpj[i] = cnpj[i] - '0';
    }

    // Cálculo do primeiro dígito
    somador = icnpj[0]*5 + icnpj[1]*4 + icnpj[2]*3 + icnpj[3]*2 +
              icnpj[4]*9 + icnpj[5]*8 + icnpj[6]*7 + icnpj[7]*6 +
              icnpj[8]*5 + icnpj[9]*4 + icnpj[10]*3 + icnpj[11]*2;

    result1 = somador % 11;
    digito1 = (result1 < 2) ? 0 : 11 - result1;

    // Cálculo do segundo dígito
    somador = icnpj[0]*6 + icnpj[1]*5 + icnpj[2]*4 + icnpj[3]*3 +
              icnpj[4]*2 + icnpj[5]*9 + icnpj[6]*8 + icnpj[7]*7 +
              icnpj[8]*6 + icnpj[9]*5 + icnpj[10]*4 + icnpj[11]*3 + icnpj[12]*2;
    valor = (somador / 11) * 11;
    result2 = somador - valor;
    digito2 = (result2 < 2) ? 0 : 11 - result2;

    if (digito1 == icnpj[12] && digito2 == icnpj[13]) {
        printf("CNPJ válido.\n");
    } else {
        printf("CNPJ inválido.\n");
    }
}

int main() {
    char texto[100];

    printf("Digite um CNPJ: ");
    fgets(texto, sizeof(texto), stdin);

    validacao_cnpj(texto);

    return 0;
}
