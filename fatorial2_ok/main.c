#include <stdio.h>

// Função para calcular o fatorial de um número
unsigned int fatorial(unsigned int numero) {
    unsigned int fat = 1;
    for (unsigned int i = numero; i >= 1; i--) {
        fat *= i;
    }
    return fat;
}
/* faz sentido usar unsigned int para garantir que
os resultados dos fatoriais permaneçam positivos e
para aproveitar o intervalo maior fornecido por
unsigned int*/
int main() {
    unsigned int x, y;
    double s;

    // Leitura das variáveis
    scanf("%u %u", &x, &y);

    // Cálculo da expressão S = X! + Y! / (X + Y)!
    s = (double)(fatorial(x) + fatorial(y)) / fatorial(x + y);

    // Impressão do resultado
    printf("%lf\n", s);

    return 0;
}
