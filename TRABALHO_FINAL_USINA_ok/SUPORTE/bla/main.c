#include "stdio.h"
#include "stdlib.h"
#include <locale.h>

int main(void) {
  setlocale(LC_ALL, "Portuguese");
  int sm, i, r, num, mult;
  char dig13, dig14, cnpj[14];
  printf("Informe o valor do CNPJ:\n");
  gets(cnpj);

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
     printf("\nO CNPJ informado eh válido.");
  else
     printf("\nO CNPJ informado eh inválido.");
}
