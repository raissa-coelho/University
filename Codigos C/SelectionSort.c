#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void * criaVetor(int *vetor, int tamanhoB);
void * selectionSort(int *vetor, int tamanhoB);
void imprimiSelSo(int *vetor, int tamanhoB);

int main(){
    srand(time(NULL));
    int tamanhoB;

    printf("Tamanho a ser ordenado: ");
    fflush(stdin);
    scanf("%d", &tamanhoB);
    fflush(stdin);

   int *vetor = (int *)malloc(tamanhoB * sizeof(int));
     if(!vetor){
        printf("sem memoria.\n");
    }else{
        criaVetor(vetor,tamanhoB);
    }

    selectionSort(vetor, tamanhoB);
    imprimiSelSo(vetor,tamanhoB);

    return 0;
}

void * criaVetor(int *vetor, int tamanhoB){
    for(int i = 0; i < tamanhoB; i++){
        vetor[i] = rand() % 100;
     }
     return vetor;
}

void * selectionSort(int *vetor, int tamanhoB){
    int aux;
    int i, j, menor;

    for(i = 0; i < tamanhoB - 1; i++)
    {
        menor = i;
        for(j = i +  1; j < tamanhoB; j++)
        {
            if(vetor[j] < vetor[menor])
            {
                menor = j;
            }
        }
        if( i != menor)
        {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }

    return vetor;
}

void imprimiSelSo(int *vetor, int tamanhoB){
    int i;

    for(i = 0; i < tamanhoB; i++){
        printf(" Ss: %d \n", *(vetor + i));
    }

    free(vetor);
}