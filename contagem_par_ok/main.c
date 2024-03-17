#include <stdio.h>
#include <stdlib.h>
void impressao(int z)
{
    {
        {
            int i;
            for (i=0; i<=z; i+=1)
                if (i%2 == 0)   //void que conta ate o numero que o usuario definiu em pares
                    printf("%d\n", i);
        }
    }
}
int main()
{
    int z;
    scanf("%d", &z);
    impressao(z);
    return 0;
}
