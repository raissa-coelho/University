#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void * criaVetor(int *vetor, int tamanho);
void * inserirSort(int *vetor, int tamanho);
void imprimiInSo(int *vetor, int tamanho);

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

    inserirSort(vetor, tamanho);
    imprimiInSo(vetor, tamanho);

    return 0;
}

void * criaVetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 100;
     }
     return vetor;
}

void * inserirSort(int *vetor, int tamanho){
    int i, aux, j;

    for(i = 1; i < tamanho; i++){
        aux = vetor[i];
        j = i - 1;
        while(j >= 0 && vetor[j] > aux){
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = aux;
    }

    return vetor;
}

void imprimiInSo(int *vetor, int tamanho){
    int i;

    for(i = 0; i < tamanho; i++){
        printf(" IS: %d \n", vetor[i]);
    }

    free(vetor);
}