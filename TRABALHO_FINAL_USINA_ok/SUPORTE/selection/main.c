#include <stdio.h>
#include <stdlib.h>

void selecao(int Vet[], int n){

    int menor, aux;

    for(int i=0; i<n-1; i++){
        menor = i;
        for(int j=i+1;j<n;j++){
            if(Vet[menor]>Vet[j]){
                menor = j;
            }
        }
    if (i!= menor){
        aux = Vet[i];
        Vet[i] = Vet[menor];
        Vet[menor]=aux;
        }
    }
}

int main()
{
    int n=9;
    int vetor[9] = {3,4,6,1,2,4,5,2,9};

    selecao(vetor, n);

    for(int i=0;i<n;i++){
    printf("%d", vetor[i]);
    }
    return 0;
}
