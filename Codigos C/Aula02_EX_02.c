#include <stdio.h>
#include <stdlib.h>

int ** criaMatriz(int m, int n); 
void leiaMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n); 
int * colunaMatriz(int **mat, int m, int n, int nColuna); 
void imprimeVetor(int *vet, int m); 
void imprimeMatriz(int **mat, int m, int n); 
void liberaMatriz(int **mat, int nLinha); 

void main(){
    char escolha;
    int m, n;
    int **matriz = NULL;
    int *vet = NULL;
    int col;

    do{
        printf("A - Cria matriz\n"
               "B - Leitura dos elementos\n"
               "C - Soma dos elementos\n"
               "D - Retornar elementos de uma coluna\n"
               "E - Imprimi a matriz\n"
               "F - Sair do programa\n");
               fflush(stdin);
               scanf("%c", &escolha);
               fflush(stdin);
               switch(escolha){
                    case 'a': case 'A':
                       printf("Linha: ");
                       fflush(stdin);
                       scanf("%d", &m);
                       fflush(stdin);
                       printf("Coluna: ");
                       scanf("%d", &n);
                       fflush(stdin);
                        matriz = criaMatriz(m,n);
                        break;
                    case 'b': case 'B':
                        leiaMatriz(matriz,m, n);
                        break;
                    case 'c': case 'C':
                        somaMatriz(matriz,m,n);
                        break;
                    case 'd': case 'D':
                        printf("Coluna: ");
                        fflush(stdin);
                        scanf("%d", &col);
                        fflush(stdin);
                        if( (col - 1) < 0 || (col - 1) > (n - 1) ){
                            printf("Numero da coluna invalido.\n");
                        }
                        vet = colunaMatriz(matriz,m,n,col);
                        imprimeVetor(vet,m);
                        break;
                    case 'e': case 'E':
                        imprimeMatriz(matriz,m,n);
                        break;
                    case 'f': case 'F':
                        liberaMatriz(matriz, m);
                        break;
                    default:
                        printf("Invalido.\n");

               }

    }while(escolha != 'F' && escolha != 'f');


}

int ** criaMatriz(int m, int n){
    int **matriz;

    matriz = (int **)malloc(m * sizeof(int *));
    for(int i = 0; i < m; i++ ){
        matriz[i] = (int *)malloc(n * sizeof(int));
     }

    return matriz;

}

void leiaMatriz(int **mat, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d %d: ", i,j);
            fflush(stdin);
            scanf("%d", &mat[i][j] );
            fflush(stdin);
        }
    }

}

int somaMatriz(int **mat, int m, int n){
    int soma = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            soma += mat[i][j];
        }
    }
    printf("Soma da matriz eh: %d\n", soma);
}

int * colunaMatriz(int **mat, int m, int n, int nColuna){
    int *vet = NULL;
    vet = (int*)malloc(m * sizeof(int));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(j == (nColuna - 1) ){
                printf("%d - ", mat[i][j]);
                vet = &mat[i][j];
                vet++;
            }
        }
    } 

    return vet;

}

void imprimeVetor(int *vet, int m){

    for(int j = 0; j < m; j++){
        printf(" %d \n", *vet);
        vet++;
    }

}

void liberaMatriz(int **mat, int mLinha){
    for(int i = 0; i < mLinha; i++){
        free(mat[i]);
    }
    free(mat);
}

void imprimeMatriz(int **mat, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t", mat[i][j] );
        }
        printf("\n");
    }
}