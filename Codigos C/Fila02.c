#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pessoa{
    char nome[30];
    int idade;
    struct Pessoa *next;
    int tamanho;
}Pessoa;

void resetFila(Pessoa *f);
void insere(Pessoa *f);
void deleta(Pessoa *f);
void imprime(Pessoa *f);
void limpa(Pessoa *f);
void libera(Pessoa *f);

int main(){
    int escolha;
    Pessoa *fila = (Pessoa *) malloc(sizeof(Pessoa));
    if(!fila){
        printf("nao foi possivel alocar");
    }else{
        resetFila(fila);
    }

    do{
        printf("1 - Insere Pessoa\n"
               "2 - Deleta pessoa\n"
               "3 - Imprime fila\n"
               "4 - Limpa fila\n"
               "5 - Sair do programa\n");
        fflush(stdin);
        scanf("%d", &escolha);
        fflush(stdin);
        switch(escolha)
        {
            case 1:
                insere(fila);
                   break;
            case 2:
                deleta(fila);
                   break;
            case 3:
                imprime(fila);
                   break;
            case 4:
                limpa(fila);
                   break;
            case 5:
                libera(fila);
                exit(EXIT_SUCCESS);
                   break;
            default:
                printf("invalido\n");
                break;
        }

    }while(escolha);
    
    free(fila);

    return 0;
}

void resetFila(Pessoa *f){
    f->next = NULL;
    f->tamanho = 0;
}

void insere(Pessoa *f){
    Pessoa *nova = (Pessoa *)malloc(sizeof(Pessoa));

    printf("Nome: ");
    fflush(stdin);
    scanf("%s", &nova->nome);
    fflush(stdin);
    printf("Idade: ");
    fflush(stdin);
    scanf("%d", &nova->idade);
    fflush(stdin);
    nova->next = NULL;

    if(f->next == NULL){
        f->next = nova;
    }else{
        Pessoa *aux = f->next;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = nova;
    }
    f->tamanho++;
}

void deleta(Pessoa *f){
    if(f->next == NULL){
        printf("vazia.\n");
    }else{
        Pessoa *p;
        p = f->next;
        f->next = p->next;
        free(p);
        f->tamanho--;
    }
}

void imprime(Pessoa *f){
    if(f->next == NULL){
        printf("vazia.\n");
    }else{
        Pessoa *p;
        p = f->next;
        while(p != NULL){
            printf("Nome:%s - idade:%d \n", p->nome, p->idade);
            p = p->next;
        }
    }
}

void limpa(Pessoa *f){
    if(f->next == NULL){
        printf("vazio.\n");
    }else{
        while(f->tamanho != 0){
            Pessoa *p;
             p = f->next;
             f->next = p->next;
             free(p);
             f->tamanho--;
        }
    }
}

void libera(Pessoa *f){
        Pessoa *p;
        Pessoa *aux;
        p = f->next;
        while(p != NULL){
            aux = p->next;
            free(p);
            p = aux;
        }
}