#include<stdio.h>

int fat, n;

int main()
{
    scanf("%d", &n) ;

    for(int i=n; i>0; i--)
    {
        printf("%d ",i);
    }
    printf("\nFatorial de %d:", n);
    for(fat = 1; n > 1; n = n - 1)
    {
        fat *= n;
    }

    printf(" %d", fat);

    return 0;
}
