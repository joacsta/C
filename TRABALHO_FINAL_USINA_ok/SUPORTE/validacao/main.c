#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main() {
  int sm, i, r, num, mult;
  char dig13, dig14, cnpj[14];
  printf("Informe o valor do CNPJ:\n");
  gets(cnpj);

char* cnpj(const char *str) {
    int tamanho = strlen(str);
    char numeros[tamanho];
    int j = 0;

    for (int i = 0; i < tamanho; i++) {
        if (isdigit(str[i])) {
            numeros[j] = str[i];
            j++;
        }
    }

    numeros[j] = '\0';
    return strdup(numeros);
}

int main() {
    char texto[100];

    printf("Digite uma string: ");
    fgets(texto, sizeof(texto), stdin);

    char* numeros = cnpj_consultado(texto);
    free(numeros);

// calcula o 1o. digito verificador do CNPJ
  sm = 0; mult = 2;
  for (i=11; i>=0; i--) {
    num = cnpj[i] - 48;	// transforma o caracter '0' no inteiro 0
			// (48 eh a posição de '0' na tabela ASCII)
    sm = sm + (num * mult);
    mult = mult + 1;
    if (mult == 10)
       mult = 2;
  }
  r = sm % 11;
  if ((r == 0) || (r == 1))
     dig13 = '0';
  else
     dig13 = (11 - r) + 48;

// calcula o 2o. digito verificador do CNPJ
  sm = 0; mult = 2;
  for (i=12; i>=0; i--) {
    num = cnpj[i] - 48;
    sm = sm + (num * mult);
    mult = mult + 1;
    if (mult == 10)
       mult = 2;
  }
  r = sm % 11;
  if ((r == 0) || (r == 1))
     dig14 = '0';
  else
     dig14 = (11 - r) + 48;

// compara os dígitos calculados com os dígitos informados
  if ((dig13 == cnpj[12]) && (dig14 == cnpj[13]))
     printf("\nO CNPJ informado eh valido.");
  else
     printf("\nO CNPJ informado eh invalido.");
}
