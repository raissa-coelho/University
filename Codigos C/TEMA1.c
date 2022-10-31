//TEMA 01 - Sistemas Operacionais
//Nome: Bianca Nunes Coelho
//Matricula: 15102880

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

//Variaveis do banco - globais
int especie = 500000;
int taxa = 30000;
int subsidio = 100000;
int *recursos;
//Fim Variaveis do banco

//Váriaveis processo
int **alocados;
int **requeridos;
int **necessarios;
int *sequenciaSegura;
int numProcess;
//Fim variáveis processo

int grupos = 2;
int numeroThreads = 3;
pthread_mutex_t lock;

//Estrutura do custo do imóvel
typedef struct custoImovel{
    int custoTotal; // Inclui todos os valores do imóvel
    int especieImovel;
    int subsidioImovel;
    int taxaImovel;
}custo_imovel;

//Estrutura do que a pessoa tem
typedef struct custoPessoa{
    int tid;
    custo_imovel custoImovel; //custo do imovel
    int entrada;
    int subsidio;
    int taxas;
}custo_pessoa;

//Calculo do subsidio do imóvel
int subsidioImovel(int valor){
    int subsidioI;
    srand(time(0));
    subsidioI = rand () % valor;
    while (subsidioI > ( (20*valor)/100 ) || subsidioI == 0){
        srand(time(0));
        subsidioI = rand () % valor;
    }
    return subsidioI;
}

//Calculo da taxa do imovel
int taxaImovel(int valor){
    int taxaI;
    taxaI = (5*valor)/100;
    return taxaI;
}

bool sequencia(){
    int res[3];
    for(int i =0; i < 3; i++){
        res[i] = recursos[i];
    }
    bool terminou[numeroThreads];
    for(int i=0; i<numeroThreads; i++){
        terminou[i] = false;
    }
    int numeroEND=0;
    while(numeroEND < numeroThreads) {
        bool seguro = false;

        for(int i=0; i<numeroThreads; i++) {
            if(!terminou[i]) {
                bool possivel = true;
                for(int j=0; j<3; j++)
                    if(necessarios[i][j] > res[j]) {
                        possivel = false;
                        break;
                }

                if(possivel) {
                    for(int j=0; j<3; j++){
                        res[j] += alocados[i][j];
                    }
                    sequenciaSegura[numeroEND] = i;
                    terminou[i] = true;
                    ++numeroEND;
                    seguro = true;
                }
            }
        }

        if(!seguro) {
            for(int k=0; k<numeroThreads; k++){ 
                sequenciaSegura[k] = -1;
            }
            return false; 
        }
    }
    return true;
}

void *Pagar(void *arg){
    int p = *((int*)arg);

    //região critica
    pthread_mutex_lock(&lock);
    
    printf("PROCESSO %d\n", p);
    printf("Alocados: %d, %d, %d\n", alocados[p][0],alocados[p][1], alocados[p][2]);
    printf("Requeridos: %d, %d, %d\n", requeridos[p][0],requeridos[p][1], requeridos[p][2]);
    printf("Recursos Disponiveis: %d, %d, %d\n", recursos[0],recursos[1], recursos[2]);
    printf("\n");
    printf("Cliente pagando banco...\n");
    //sleep(3);
    printf("Fim do pagamento!\n");
    printf("\n");
    
    recursos[0] = recursos[0] + alocados[p][0];
    recursos[1] = recursos[1] + alocados[p][1];

    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main(){
    printf("---->COMECO DO PROGRAMA<----\n");
    srand(time(0));

    recursos = (int*)malloc(3*sizeof(*recursos));
    recursos[0] = 500000; //especie
    recursos[1] = 30000; //taxa
    recursos[2] = 100000; //subsidio

    int array[3] = {5,10,20}; // para escolher a porcentagem de subsidio do valor do imóvel
    
    pthread_t threads[numeroThreads];
    custo_pessoa data[numeroThreads];
    
    int i = 0;
    int rc;
    int grupo = 0;

    while (grupo != grupos){
        printf("!!!!GRUPO %d !!!!\n", grupo);
        printf("INFO BANCO ---> ESPECIE: %d ---> SUBSIDIO: %d ---> TAXAS: %d\n", recursos[0],recursos[2],recursos[1]);

        printf("\n");
        //Alocação de Processos
        alocados = (int **)malloc(numeroThreads * sizeof(*alocados));
        for(i =0; i< numeroThreads; i++){
            alocados[i] = (int*)malloc(3*sizeof(**alocados));
        }
        
        for (i = 0; i< numeroThreads; i++){
            data[i].tid = i;

            int temp = rand() % especie;
            while(temp > especie){
                temp = rand() % especie;
            }

            data[i].custoImovel.especieImovel = temp;
            data[i].custoImovel.subsidioImovel = subsidioImovel(temp);
            data[i].custoImovel.taxaImovel = taxaImovel(temp);
            data[i].custoImovel.custoTotal = data[i].custoImovel.especieImovel + data[i].custoImovel.subsidioImovel + data[i].custoImovel.taxaImovel;      

            int lower = (40*temp)/100;
            int upper = (70*temp)/100;

            data[i].entrada = (rand() %(upper - lower +1) ) + lower;
            data[i].taxas = rand() % data[i].custoImovel.taxaImovel;
            while (data[i].taxas < ((50*data[i].custoImovel.taxaImovel)/100)){
                data[i].taxas = rand() % data[i].custoImovel.taxaImovel;
            }
            int nArray = rand() % 3;
            data[i].subsidio = (array[nArray]*temp)/100;
            
            alocados[i][0] = data[i].entrada;
            alocados[i][1] = data[i].taxas;
            alocados[i][2] = data[i].subsidio;
        }

        printf("\n");
        //Máximo que um processo precisa
        requeridos = (int**)malloc(numeroThreads*sizeof(*requeridos));
        for(i = 0;i < numeroThreads;i++){
            requeridos[i] = (int*)malloc(3*sizeof(**requeridos));
        }

        for(i = 0; i< numeroThreads; i++){
            if(data[i].entrada == data[i].custoImovel.custoTotal){
                requeridos[i][0] = 0;
                requeridos[i][1] = 0;
                requeridos[i][2] = 0;
            }
            if(data[i].entrada < data[i].custoImovel.custoTotal){
                requeridos[i][2] = alocados[i][2];
                requeridos[i][0] = alocados[i][2] - data[i].custoImovel.custoTotal;
                if(data[i].taxas < data[i].custoImovel.taxaImovel){
                    requeridos[i][1] = alocados[i][1] - data[i].custoImovel.taxaImovel;
                }else{
                    requeridos[i][1] = 0;
                }
            }
        }
        
        printf("\n");
        //Criação da matrix de recursos necessários para os processos
        necessarios = (int**)malloc(numeroThreads*sizeof(*necessarios));
        for(i = 0; i<numeroThreads;i++){
            necessarios[i] = (int*)malloc(numeroThreads*sizeof(**necessarios));
        }
        for(i = 0; i < numeroThreads; i++){
            for(int j =0; j < 3; j++){
                necessarios[i][j] = requeridos[i][j] - alocados[i][j];
            }
        }

        printf("\n");
        //Algoritmo do banqueiro
        sequenciaSegura = (int *)malloc(numeroThreads * sizeof(*sequenciaSegura));
        for(int i=0; i<numeroThreads; i++){
            sequenciaSegura[i] = -1;
        }

        if(!sequencia()){
            printf("Sequencia Insegura!");
            exit(-1);
        }

        printf("Sequencia segura:");
        for(i = 0; i < numeroThreads; i++){
            printf("%d--", sequenciaSegura[i]+1);
        }

        printf("\n");
        //Criação das Threads para execução
        for(i = 0; i < numeroThreads;i++){
            printf("Criando uma thread: %d\n", i);
        
            rc = pthread_create(&threads[i], NULL, Pagar, &data[i].tid);
            if(rc){
                printf("ERRO; pthread_create() devolveu o erro %d\n", rc);
                exit(-1);
            }
        }
        printf("!!!FIM GRUPO %d!!!\n", grupo);
        recursos[2] = recursos[2] + ((recursos[2]*50)/100);

        grupo++;
    }

    for (i = 0; i < numeroThreads; i++){
        pthread_join(threads[i],NULL);
    }
    
    //liberando memória
    free(recursos);
    for(int i=0; i<numeroThreads; i++) {
        free(alocados[i]);
        free(requeridos[i]);
		free(necessarios[i]);
    }
    free(alocados);
    free(requeridos);
	free(necessarios);
    free(sequenciaSegura);

    printf("---->FIM DO PROGRAMA<----\n");
    return(0);
}