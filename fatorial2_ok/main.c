#include <stdio.h>

// Fun��o para calcular o fatorial de um n�mero
unsigned int fatorial(unsigned int numero) {
    unsigned int fat = 1;
    for (unsigned int i = numero; i >= 1; i--) {
        fat *= i;
    }
    return fat;
}
/* faz sentido usar unsigned int para garantir que
os resultados dos fatoriais permane�am positivos e
para aproveitar o intervalo maior fornecido por
unsigned int*/
int main() {
    unsigned int x, y;
    double s;

    // Leitura das vari�veis
    scanf("%u %u", &x, &y);

    // C�lculo da express�o S = X! + Y! / (X + Y)!
    s = (double)(fatorial(x) + fatorial(y)) / fatorial(x + y);

    // Impress�o do resultado
    printf("%lf\n", s);

    return 0;
}
