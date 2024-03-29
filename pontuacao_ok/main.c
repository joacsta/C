#include <stdio.h>
#include <math.h>

// Fun��es para calcular a pontua��o de cada competidor
int pontuacaoRafael(int x, int y) {
    return pow(3 * x, 2) + pow(y, 2);
}

int pontuacaoBeto(int x, int y) {
    return 2 * pow(x, 2) + pow(5 * y, 2);
}

int pontuacaoCarlos(int x, int y) {
    return -100 * x + pow(y, 3);
}

int main() {
    int x, y; // Coordenadas
    int rafael, beto, carlos; // Pontua��es dos competidores
    unsigned casos; // N�mero de casos de teste

    // Leitura do n�mero de casos de teste
    scanf("%u", &casos);

    // Loop para processar cada caso de teste
    while (casos--) {
        // Leitura das coordenadas (x, y)
        scanf("%d %d", &x, &y);

        // C�lculo das pontua��es de cada competidor
        rafael = pontuacaoRafael(x, y);
        beto = pontuacaoBeto(x, y);
        carlos = pontuacaoCarlos(x, y);

        // Compara��o das pontua��es para determinar o vencedor
        if (rafael > beto && rafael > carlos)
            printf("Rafael ganhou\n");
        else if (beto > rafael && beto > carlos)
            printf("Beto ganhou\n");
        else
            printf("Carlos ganhou\n");
    }

    return 0;
}
