#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void * criaVetor(int *vetor, int tamanho);
void heapSort(int *vetor, int tamanho);
void imprimiHeapS(int *vetor,int tamanho);

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

    heapSort(vetor,tamanho);
    imprimiHeapS(vetor,tamanho);

    return 0;
}

void * criaVetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 100;
     }
     return vetor;
}

void heapSort(int *vetor, int tamanho){
    int i = tamanho/2;
    int pai, filho, t;

    while(true){
        if(i > 0){
            i--;
            t = vetor[i];
        }else{
            tamanho--;
            if(tamanho <= 0) return;
            t = vetor[tamanho];
            vetor[tamanho] = vetor[0]; 
        }
        pai = i;
        filho = i * 2 + 1;

        while(filho < tamanho){
            if((filho + 1 < tamanho) && (vetor[filho + 1] > vetor[filho]))
                filho++;
            
            if(vetor[filho] > t){
                vetor[pai] = vetor[filho];
                pai = filho;
                filho = pai * 2 + 1;
            }else{
                break;
            }
        }
        vetor[pai] = t;
    }
}

void imprimiHeapS(int *vetor,int tamanho){
    int i;

    for(i = 0; i < tamanho; i++){
        printf(" HS: %d \n", vetor[i]);
    }

    free(vetor);
}