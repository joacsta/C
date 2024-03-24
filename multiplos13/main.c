#include <stdio.h>
#include <stdlib.h>

int main(){


    int x, y, i, soma;
    scanf("%d %d", &x, &y);

    soma=0;

    if(x<y){
        for(i=x; i<=y; i++){
            if(i%13!=0){
                soma+=i;
            }
    }

}else{
    for(i=y; i<=x; i++){
        if(i%13!=0){
            soma+=i;
        }
    }
}
    printf("%d\n", soma);


    return 0;
}
