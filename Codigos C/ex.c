//EX: 1
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int soma = 0;

//Soma function -- Regiões críticas
void *SOMA(void *threadid, int *vetor, int tamVetor){
    pthread_mutex_lock(&m);
    int somaParcial,i;
    for(i = 0; i < tamVetor; i++){
        somaParcial += vetor[i];
    }
    soma += somaParcial;
    pthread_mutex_unlock(&m);
}

//MAIN
int main(){
    int tamVetor;
    int NUM_THREADS;

    scanf("%d", &tamVetor);
    scanf("%d", &NUM_THREADS);

    int *vetor = malloc(tamVetor * sizeof(int));
    pthread_t threads[NUM_THREADS];
    int j;

    for(j = 0; j < tamVetor; j++){
        *vetor = j;
        printf("-%d-", *vetor);
    }

    int rc;
    int t;
    int *vetorInt = malloc((tamVetor/NUM_THREADS)*sizeof(int));

    return(0);
}