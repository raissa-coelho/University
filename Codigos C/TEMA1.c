//TEMA 01 - Sistemas Operacionais
//Nome: Bianca Nunes Coelho
//Matricula: 15102880

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

//Variaveis do banco
int especie;
int taxa;
int subsidio;
//Fim Variaveis do banco

char estado;

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

//Função pagamento das threads/pessoas para o banco
void *Pagar(void *arg){
    custo_pessoa *data = (custo_pessoa *)arg;
    
    //Print das informações do cliente e do imóvel a ser comprado/financiado pelo banco
    printf("THREAD/CLIENTE %d:\n", data->tid);
    printf("Custo Total do Imovel: %d\n", data->custoImovel.custoTotal);
    printf("SubsidioImovel: %d\n", data->custoImovel.subsidioImovel);
    printf("TaxaImovel: %d\n", data->custoImovel.taxaImovel);
    printf("EspecieImovel: %d\n", data->custoImovel.especieImovel);
    printf("Entrada: %d\n", data->entrada);
    printf("Subsidio: %d\n", data->subsidio);
    printf("Taxas: %d\n", data->taxas);


    pthread_exit(NULL);
}

int main(){
    printf("---->COMECO DO PROGRAMA<----\n");
    srand(time(0));
    
    especie = 500000;
    taxa = 30000;
    subsidio = 100000;
    
    int grupos = 2;
    int numeroThreads = 3;
    int array[3] = {5,10,20}; // para escolher a porcentagem de subsidio do valor do imóvel
    
    pthread_t threads[numeroThreads];
    custo_pessoa data[numeroThreads];
    
    int i = 0;
    int rc;
    int grupo = 0;

    while (grupo != grupos){
        printf("!!!!GRUPO %d !!!!\n", grupo);
        printf("INFO BANCO ---> ESPECIE: %d ---> SUBSIDIO: %d ---> TAXAS: %d\n", especie,subsidio,taxa);
        for(i = 0; i < numeroThreads;i++){
            printf("Criando uma thread: %d\n", i);
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
        
            rc = pthread_create(&threads[i], NULL, Pagar, &data[i]);
            printf("Thread %d criada!\n",data[i].tid);
        
            if(rc){
                printf("ERRO; pthread_create() devolveu o erro %d\n", rc);
                exit(-1);
            }
        }
        printf("!!!FIM GRUPO %d!!!\n", grupo);
        subsidio = subsidio + ((subsidio*50)/100);
        grupo++;
    }

    for (i = 0; i < numeroThreads; i++){
        pthread_join(threads[i],NULL);
    }

    printf("---->FIM DO PROGRAMA<----\n");
    return(0);
}