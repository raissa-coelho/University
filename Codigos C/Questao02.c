#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int dia;
    int mes;
    int ano;
    struct data *next;
    int tam;
}Data;

void criaLista(Data *dt);
void pushFim(Data *dt);
void popIni(Data *dt);
void clearLista(Data *dt);
void lista(Data *dt);

int main(){
    int escolhe;
    Data *dt = (Data *)malloc(sizeof(Data));
    if(!dt){
        printf("Nao eh possivel criar lista.\n");
    } else{
        criaLista(dt);
      }

     do{
        printf("1 - Push Fim\n"
               "2 - Pop Inicio\n"
               "3 - Clear\n"
               "4 - Listar\n"
               "5 - Sair\n");
        fflush(stdin);
        scanf("%d", &escolhe);
        fflush(stdin);
        switch(escolhe)
        {
            case 1:
                pushFim(dt);
                   break;
            case 2:
                popIni(dt);
                   break;
            case 3:
                clearLista(dt);
                   break;
            case 4:
                lista(dt);
                   break;
            case 5:
                exit(EXIT_SUCCESS);
                   break;
            default:
                printf("selecao invalida. Apenas numeros de 1 a 5\n");
                break;
        }

    }while(escolhe);

    free(dt);

    return 0;
}

void criaLista(Data *dt){
    dt->next = NULL;
    dt->tam = 0;
}

void pushFim(Data *dt){
    Data *novaL = (Data *)malloc(sizeof (Data));

    printf("Dia: ");
    fflush(stdin);
    scanf("%d", &novaL->dia);
    printf("Mes: ");
    fflush(stdin);
    scanf("%d", &novaL->mes);
    printf("Ano: ");
    fflush(stdin);
    scanf("%d", &novaL->ano);
    novaL->next = NULL;

    if(dt->next == NULL){
        dt->next = novaL;
    }else{
        Data *dtAtual = dt->next;

        while(dtAtual->next != NULL){
            dtAtual = dtAtual->next;
        }
        dtAtual->next = novaL;
    }
    dt->tam++;
}

void popIni(Data *dt)
{
    if(dt->next == NULL){
        printf("lista vazia.\n");
    } else{
        Data *dtAtual;
        dtAtual = dt->next;
        dt->next = dtAtual->next;
        free(dtAtual);
        dt->tam--;
      }
}

void clearLista(Data *dt)
{
    if(dt->next == NULL){
        printf("lista vazia.\n");
    } else{
        while(dt->tam != 0){
            Data *aux;
            aux = dt->next;
            dt->next = aux->next;
            free(aux);
            dt->tam--;
        }
      }
}

void lista(Data *dt)
{
    if(dt->next == NULL){
        printf("lista vazia.\n");
    } else{
        Data *dtAtual;
        dtAtual = dt->next;

        while(dtAtual != NULL){
            printf("%d-%d-%d\n", dtAtual->dia, dtAtual->mes, dtAtual->ano);
            dtAtual = dtAtual->next;
        }

      }
}
