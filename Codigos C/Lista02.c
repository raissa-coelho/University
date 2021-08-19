#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pessoa{
    int idade;
    char nome[30];
    struct pessoa *next;
}Pessoa;

int tamanho;

void resetLista(Pessoa *p);
void listaP(Pessoa *p);
void limpaP(Pessoa *p);
void inserePos(Pessoa *p);
void insereIni(Pessoa *p);
void deletaPos(Pessoa *p);
void deleteNome(Pessoa *p);
int buscaNome(char *nome, Pessoa *p);

void main(){
    int escolha;
    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
    if(!p){
        printf("sem memoria.\n");
    }else{
        resetLista(p);
    }

     do{
        printf("1 - Insere Pessoa por posicao\n"
               "2 - Deleta pessoa por posicao\n"
               "3 - Deleta pessoa por nome\n"
               "4 - Lista pessoas\n"
               "5 - Limpa pessoas\n"
               "6 - Sair do programa\n");
        fflush(stdin);
        scanf("%d", &escolha);
        fflush(stdin);
        switch(escolha)
        {
            case 1:
                inserePos(p);
                   break;
            case 2:
                deletaPos(p);
                   break;
            case 3:
                deleteNome(p);
                   break;
            case 4:
                listaP(p);
                   break;
            case 5:
                limpaP(p);
                   break;
            case 6:
                exit(EXIT_SUCCESS);
                   break;
            default:
                printf("invalido\n");
                break;
        }

    }while(escolha);
    
}

void resetLista(Pessoa *p){
    p->next = NULL;
    tamanho = 0;
}

void listaP(Pessoa *p){
    if(p->next == NULL){
        printf("vazia.\n");
    }else{
        Pessoa *aux;
        aux = p->next;

        while(aux != NULL){
            printf("%s-%d\n", aux->nome, aux->idade);
            aux = aux->next;
        }
    }
}

void limpaP(Pessoa *p){
     if(p->next == NULL){
        printf("vazia.\n");
    }else{
        Pessoa *prox;
        Pessoa *pAtual;
        pAtual = p->next;

        while(pAtual != NULL){
            prox = pAtual->next;
            free(pAtual);
            pAtual = prox;
        }

    }
}

void inserePos(Pessoa *p){
    int posicao;

    printf("Posicao:(valido apenas ateh %d) ", tamanho);
    scanf("%d", &posicao);

    if(posicao == 0){
        Pessoa *nova = (Pessoa*)malloc(sizeof(Pessoa));
        Pessoa *ant = p->next;

        printf("Nome: ");
        scanf("%s", &nova->nome);
        printf("Idade: ");
        scanf("%d", &nova->idade);

        p->next = nova;
        nova->next = ant;

        tamanho++;
    }else{

    if(posicao > 0 && posicao <= tamanho )
    {
            if(posicao == 1)
            {
                insereIni(p);
            }else
            {
                Pessoa *pAtual = p->next;
                Pessoa *anter = p;
                Pessoa *novo = (Pessoa *)malloc(sizeof(Pessoa));

                printf("Nome: ");
                scanf("%s", &novo->nome);
                printf("Idade: ");
                scanf("%d", &novo->idade);
            
                    for(int i = 0; i < posicao; i++){
                        anter = pAtual;
                        pAtual = pAtual->next;
                    }

                anter->next = novo;
                novo->next = pAtual;
                tamanho++;
            }
    }else{
        printf("nao tem a posicao.\n");
    }
    }

}

void insereIni(Pessoa *p){
    Pessoa *nova = (Pessoa*)malloc(sizeof(Pessoa));
    Pessoa *ant = p->next;

    printf("Nome: ");
    scanf("%s", &nova->nome);
    printf("Idade: ");
    scanf("%d", &nova->idade);

    p->next = nova;
    nova->next = ant;

    tamanho++;
}

void deletaPos(Pessoa *p){
    int posicao;

    printf("Posicao:(valido apenas até %d) ", tamanho);
    scanf("%d", &posicao);

    if(posicao > 0 && posicao <= tamanho)
        {
            if(posicao == 1)
            {
                Pessoa *aux;
                aux = p->next;
                p->next = aux->next;
                tamanho--;
            }else
            {
                Pessoa *pAtual = p->next;
                Pessoa *anter = p;
                    for(int i = 0; i < posicao; i++){
                        anter = pAtual;
                        pAtual = pAtual->next;
                    }

                anter->next = pAtual->next;
                tamanho--;
            }
        }else{
            printf("nao tem a posicao.\n");
        }

}

void deleteNome(Pessoa *p){
    char nome[30];

    printf("Nome a achar: ");
    scanf("%s", &nome[30]);

    Pessoa *p1;
    Pessoa *p2;
    p1=p;
    p2=p->next;
	
    while((p2!=NULL) && (buscaNome(nome,p2) == 0)){
        p1=p2;
        p2=p2->next;
    }

    if(p2 != NULL){
        p1->next=p2->next;
        free(p2);
    }

    tamanho--;
}

int buscaNome(char *nome, Pessoa *p){
    Pessoa *p1;
    p1=p;
    for (p1 = p->next; p1 != NULL; p1 = p1->next){
		if(strcmp(nome,p1->nome) == 0){
            return 0;
        }
    }
    return -1;
}