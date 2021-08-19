#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int chave;
    struct arvore *direita;
    struct arvore *esquerda;
}Arvore;

Arvore * insereArvore(Arvore *arv, int chave);
void imprimiArvore(Arvore *arv);
Arvore * removeArvore(Arvore *arv, int chave);

int main(){
    Arvore *arv = NULL;
    int escolha;
    int chave;

    do{
         printf("1 - Inserir\n"
                "2 - Remover\n"
                "3 - Imprimir\n"
                "4 - Sair\n");
               fflush(stdin);
               scanf("%d", &escolha);
               fflush(stdin);
        switch(escolha){
                case 1:
                    printf("Chave: ");
                    scanf("%d", &chave);
                    fflush(stdin);
                    arv = insereArvore(arv,chave);
                    break;
                case 2:
                    printf("Chave: ");
                    scanf("%d", &chave);
                    fflush(stdin);
                    arv = removeArvore(arv, chave);
                    break;
                case 3:
                    imprimiArvore(arv);
                    break;
                case 4:
                    exit(EXIT_SUCCESS);
                    break;
                default:
                    printf("invalido\n");
                    break;
        }

    }while(escolha);

    return 0;
}

Arvore * insereArvore(Arvore *arv, int chave){

    if(arv == NULL){
        arv = (Arvore *)malloc(sizeof(Arvore));
        arv->chave = chave;
        arv->esquerda = NULL;
        arv->direita = NULL;
    }else{
        if(chave < arv->chave)
        {
            arv->esquerda = insereArvore(arv->esquerda, chave);
        }else
            {
                if(chave > arv->chave)
                {
                    arv->direita = insereArvore(arv->direita, chave);
                }
            }
    }

    return arv;
}

void imprimiArvore(Arvore *arv){
    if(arv != NULL){
        imprimiArvore(arv->esquerda);
        printf("%d\n", arv->chave);
        imprimiArvore(arv->direita);
    }
}

Arvore * removeArvore(Arvore *arv, int chave){
    if(arv == NULL)
    {
        return NULL;
    }else
    {
        if(arv->chave > chave)
        {
            arv->esquerda = removeArvore(arv->esquerda, chave);
        }else
        {
            if(arv->chave < chave)
            {
                arv->direita = removeArvore(arv->direita, chave);
            }else
            {
                if(arv->esquerda == NULL && arv->direita == NULL)
                {
                    free(arv);
                    arv = NULL;
                }else
                {
                    if(arv->esquerda == NULL)
                    {
                        Arvore *antE = arv;
                        arv = arv->direita;
                        free(antE);
                    }else
                    {
                        if(arv->direita == NULL)
                        {
                            Arvore *antD = arv;
                            arv = arv->esquerda;
                            free(antD);
                        }else
                        {
                            Arvore *ant = arv->esquerda;
                            while(ant->direita != NULL){
                                ant = ant->direita;
                            }
                            arv->chave = ant->chave;
                            ant->chave = chave;
                            arv->esquerda = removeArvore(arv->esquerda, chave);
                        }
                    }
                }
            }
        }
    }

 return arv;   
}