#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void * criaVetor(int *vetor, int tamanho);
void mergeSort(int *vetor, int inicio, int fim);
void merge(int *vetor, int inicio, int meio, int fim);
void imprimiMS(int *vetor, int tamanho);

int main(){
    srand(time(NULL));
    int tamanho;
    int escolha;

    do{
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

        mergeSort(vetor,0, tamanho - 1);
        imprimiMS(vetor, tamanho);

        printf("Digite 0 para sair: ");
        scanf("%d", &escolha);

    }while(escolha != 0);

    return 0;
}

void * criaVetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 100;
     }
     return vetor;
}

void mergeSort(int *vetor, int inicio, int fim){
    int metade;

    if(inicio < fim){
        metade = floor((inicio + fim)/2);
        mergeSort(vetor,inicio,metade);
        mergeSort(vetor,metade+1,fim);
        merge(vetor,inicio,metade,fim);
    }
}

void merge(int *vetor, int inicio, int meio, int fim){
    int *aux;
    int p1,p2,tamanho;
    int i,j,k;
    int fim1 = 0;
    int fim2 = 0;

    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    aux = (int *)malloc(tamanho * sizeof(int));
    if(aux != NULL){
        for(i = 0; i < tamanho; i++)
        {
            if(!fim1 && !fim2)
            {
                if(vetor[p1] < vetor[p2])
                {
                    aux[i] = vetor[p1++];
                }else
                {
                    aux[i] = vetor[p2++];
                }
                if(p1 > meio) fim1 = 1;
                if(p2 > fim) fim2 = 1;
            }else{
                if(!fim1){
                    aux[i] = vetor[p1++];
                }else{
                    aux[i] = vetor[p2++];
                }
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++,k++){
            vetor[k] = aux[j];
        }
    }

    free(aux);
}

void imprimiMS(int *vetor, int tamanho){
    int i;

    for(i = 0; i < tamanho; i++){
        printf(" MS: %d \n", vetor[i]);
    }

    free(vetor);
}