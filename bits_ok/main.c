#include <stdio.h>

int main() {
    int v, i = 1;

    while (1) {
        v=0;
        printf("insira o valor: ");
        scanf("%d", &v);

        if (v == 0) {
            break;
        }

        //o programa escaneia o valor que o usuario forneceu e divide em cédulas de 50, 10, 5 e 1

        int c50 = v / 50;
        v %= 50;
        int c10 = v / 10;
        v %= 10;
        int c5 = v / 5;
        int c1 = v % 5;

        printf("\nTeste %d\n", i);
        i++;
        printf("%d cedula(s) de 50\n%d cedula(s) de 10\n%d cedula(s) de 5\n%d cedula(s) de 1\n\n", c50, c10, c5, c1);

    }

    return 0;
}
