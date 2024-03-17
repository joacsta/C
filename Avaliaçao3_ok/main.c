#include <stdio.h>

int main() {

    int x, y;

    scanf("%d %d", &x,&y);

        for(x = x; x<y; x++)
            {
            if(x%5 == 2 || x%5 == 3) //se o resto da divisão for igual a 2 ou 3 imprima x
                {
                    printf("%d\n", x);
                }
            }
    if (x>y) // caso x seja maior que y imprima a contagem de y com numeros cujo resto da divisao por 5 seja 2 ou 3
        {
        for(y = y; x>y; y++)
            {
            if(y%5 == 2 || y%5 == 3) printf("%d\n", y);
            }
        }
    return 0;}
