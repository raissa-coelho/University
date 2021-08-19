#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void * criaVetor(int *vetor, int tamanho);
void troca(int *a, int *b);
void bubbleSort(int *vetor, int tamanho);
void imprimiBBS(int *vetor,int tamanho);

int main(){
    srand(time(NULL));
    int tamanho;

    printf("Tamanho a ser ordenado: ");
    fflush(stdin);
    scanf("%d", &tamanho);
    fflush(stdin);
    
    int *vetor = (int *)malloc(tamanho * sizeof(int));
     if(!vetor){
        printf("sem memoria.\n");
    }else{
        criaVetor(vetor, tamanho);
    }

    bubbleSort(vetor,tamanho-1);
    imprimiBBS(vetor,tamanho);

    return 0;
}

void * criaVetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 100;
     }
     return vetor;
}

void troca(int *a, int *b){
    int aux;
    
    aux = *a; 
    *a = *b; 
    *b = aux; 
}

void bubbleSort(int *vetor, int tamanho){
    int i;

    if(tamanho < 1) return;

    for(i = 0; i < tamanho; i++){
        if(vetor[i] > vetor[i+1]){
            troca(&vetor[i],&vetor[i+1]);
        }
    }
    bubbleSort(vetor, tamanho-1);
}

void imprimiBBS(int *vetor,int tamanho){
    int i;

    for(i = 0; i < tamanho; i++){
        printf(" QS: %d \n", vetor[i]);
    }

    free(vetor);
}