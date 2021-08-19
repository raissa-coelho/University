#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{
    int idade;
    char nome[20];
    struct Pessoa *next;
}Pessoa;

typedef struct Pilha{
    Pessoa *topo;
    int limite;
}Pilha; 

void reset(Pilha *pilha);
void push(Pilha *pilha);
void pop(Pilha *pilha);
void listar(Pilha *pilha);
void limpaP(Pilha *pilha);

void main(){
    int escolha;
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    if(!pilha){
        printf("nao foi possivel alocar");
    }else{
        reset(pilha);
    }

    do{
        printf("1 - Insere Pessoa\n"
               "2 - Deleta pessoa do topo\n"
               "3 - Lista pilha\n"
               "4 - Limpa pilha\n"
               "5 - Sair do programa\n");
        fflush(stdin);
        scanf("%d", &escolha);
        fflush(stdin);
        switch(escolha)
        {
            case 1:
                push(pilha);
                   break;
            case 2:
                pop(pilha);
                   break;
            case 3:
                listar(pilha);
                   break;
            case 4:
                limpaP(pilha);
                   break;
            case 5:
                exit(EXIT_SUCCESS);
                   break;
            default:
                printf("invalido\n");
                break;
        }

    }while(escolha);

}

void reset(Pilha *pilha){
    pilha->topo = NULL;
    pilha->limite = 0;
}

void push(Pilha *pilha){
    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));

    printf("Nome: ");
    scanf("%s", &p->nome);
    printf("Idade: ");
    scanf("%d", &p->idade);

    p->next = pilha->topo;
    pilha->topo = p;
    pilha->limite++;

}

void pop(Pilha *pilha){
    Pessoa *p;
    
    if(pilha->limite == 0){
        printf("erro.\n");
    }else{
        p = pilha->topo;
        pilha->topo = pilha->topo->next;
        free(p);
        pilha->limite--;
    }
}

void listar(Pilha *pilha){
    Pessoa *p;
    p = pilha->topo;

    for(int i = 0; i< pilha->limite; i++){
        printf("%s - %d\n", p->nome, p->idade);
        p = p->next;
    }
}

void limpaP(Pilha *pilha){
    Pessoa *p;
    
    if(pilha->limite == 0){
        printf("erro. pilha vazia.\n");
    }else{
        while(pilha->limite != 0){
            p = pilha->topo;
            pilha->topo = pilha->topo->next;

            free(p);
            pilha->limite--;
        }
    }
}