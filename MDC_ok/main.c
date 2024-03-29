#include <stdio.h>
#include <math.h>

/**O c�digo implementa o algoritmo de Euclides para calcular
o m�ximo divisor comum (MDC) entre dois n�meros inteiros
positivos. O programa l� o n�mero de testes a serem executados,
seguido por pares de n�meros inteiros para os quais o MDC ser� calculado.**/

int euclides_mdc(int n1, int n2) {
    int res = n1 % n2;

   if (res == 0) {
       return abs(n2);
  }

  return euclides_mdc(n2, res);
}

void run_teste() {
 int a, b;
 printf("Informe os numeros a serem trabalhados: \n");
 scanf("%d %d", &a, &b);
 printf("Maximo Divisor Comum (MDC) entre os numeros: ");
 printf("\n%d\n", euclides_mdc(a, b));
}

int main(int argc, char const *argv[])
{
 int numero_testes;
 printf("Informe a qtd. de casos:\n");
 scanf("%d", &numero_testes);

 int i;
 for (i = 0; i < numero_testes; ++i)
 {
  run_teste();
 }

 return 0;


}
