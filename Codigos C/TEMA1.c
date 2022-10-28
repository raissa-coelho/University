//TEMA 01 - Sistemas Operacionais
//Nome: Bianca Nunes Coelho
//Matricula: 15102880

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

//Variaveis do banco
int especie = 500000;
int taxa = 30000;
int subsidio = 100000;
//Variaveis do banco

char estado;

typedef struct custo{
    int tid;
    int custoImovel;
    int entrada;
    int subsidio;
    int taxas;
}custo_imovel;

void *Pagar(void *arg){
    custo_imovel *data = (custo_imovel *)arg;
    
    printf("THREAD %d:\n", data->tid);
    printf("Custo do imovel: %d\n", data->custoImovel);
    printf("Entrada: %d\n", data->entrada);
    printf("Subsidio: %d\n", data->subsidio);
    printf("Taxas: %d\n", data->taxas);

    pthread_exit(NULL);
}

int main(){
    int numeroThreads = 3;
    pthread_t threads[numeroThreads];
    custo_imovel data[numeroThreads];
    
    int i;
    int rc;

    for(i = 0; i < numeroThreads;i++){
        
        printf("Criando uma thread: %d\n", i);
        data[i].tid = i;
        srand(time(0));
        data[i].custoImovel = rand() % especie;
        data[i].entrada = rand() % especie;
        data[i].subsidio = rand() % subsidio;
        data[i].taxas = rand() % taxa;
        
        rc = pthread_create(&threads[i], NULL, Pagar, &data[i]);
        printf("Thread %d criada!\n",data[i].tid);
        
        if(rc){
            printf("ERRO; pthread_create() devolveu o erro %d\n", rc);
            exit(-1);
        }
    }
    
    for (i = 0; i < numeroThreads; i++){
        pthread_join(threads[i],NULL);
    }

    return(0);
}