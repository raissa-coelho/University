#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void * criaVetor(int *vetor, int tamanho);
void quickSort(int *vetor, int esquerda, int direita);
void imprimiQS(int *vetor,int tamanho);

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

    quickSort(vetor,0,tamanho-1);
    imprimiQS(vetor,tamanho);


    return 0;
}

void * criaVetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 100;
     }
     return vetor;
}

void quickSort(int *vetor, int esquerda, int direita){
    int meio;
    int aux;
    int i, j;

    i = esquerda;
    j = direita;
    meio = vetor[(esquerda + direita)/2];

    do{
        while(vetor[i] < meio){
            i++;
        }
        
        while(meio < vetor[j]) {
            j--;
        }

        if(i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }

    }while(i <= j);

    if(esquerda < j){
        quickSort(vetor,esquerda,j);
    }
    if(i < direita){
        quickSort(vetor,i,direita);
    }
}

void imprimiQS(int *vetor,int tamanho){
    int i;

    for(i = 0; i < tamanho; i++){
        printf(" QS: %d \n", vetor[i]);
    }

    free(vetor);
}