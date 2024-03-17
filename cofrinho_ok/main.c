#include <stdio.h>
int main()
{
    //o programa imprime depois da segunda entrada a exata quantidade de caracteres que o usuario definiu na primeira entrada
    int n;

    printf("numero de caracteres que serao considerados: ");
    scanf("%d ", &n);
    char palavra[n];
    for(int i=0; i<n; i++)
    {
        scanf("%c", &palavra[i]);
    }
    for(int j=0; j<n; j++)
    {
        printf("%c", palavra[j]);
    }
    return 0;
}
