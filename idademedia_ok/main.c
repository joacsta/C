#include <stdio.h>
/**
calculo da média de uma sequência
de números fornecidos como entrada,
ignorando números negativos.
*/
int main()
{
    int i, c = 0;
    float media;

    while(scanf("%d", &i) == 1)
    {
        if(i < 0)
            break;
        media = media + i;
        c++;
    }
    if(c != 0)
        media = media/ c;
    else
        c = 1;
    printf("%.2f\n", media);

    return 0;
}
