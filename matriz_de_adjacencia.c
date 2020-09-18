#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct {

    char tamanho[100];

}Grafo;

int main()
{
    while(1){

        int entrada;

        printf("Selecione (1) para carregar um grafo ou (2) para criar um grafo ou (0) para encerrar o programa: ");

        scanf("%d", &entrada);

        if(entrada == 2){ // Cria grafo

            char nome_grafo[20];

            printf("Entre com o nome do grafo que deseja criar: ");

            scanf("%s", &nome_grafo);

            strcat(nome_grafo, ".txt\0");

            arquivo = fopen(nome_grafo, "r");

            /*if(arquivo!=NULL){
                printf("Arquivo com nome ja existente, por favor selecione outro. \n\n");
                fclose(arquivo);
                continue;
            }*/

            printf("Indique o n para a matriz de nxn: ");

            int n;

            scanf("%d", &n);

            int matriz[n][n];

            int i,j;

            for(i=0; i<n; i++){
                for(j=i; j<n; j++){
                    printf("Entre com o numero da posicao %dx%d : ", i+1,j+1);
                    int aux;
                    scanf("%d", &aux);
                    matriz[i][j] = aux;
                }
                printf("\n");

            }

            for(i=0; i<n; i++){
                for(j=i; j<n; j++){
                   if(i>j){
                        fprintf(arquivo, "  ");
                    }else{
                        fprintf(arquivo, "%d ", matriz[i][j]);
                    }
                }
            }

            arquivo = fopen(nome_grafo, "a");

            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    if(i>j){
                        printf("  ");
                    }else{
                        printf("%d ", matriz[i][j]);
                    }

                }
                printf("\n");

            }

            fclose(arquivo);

        }else if(entrada == 1){ // Carrega grafo

            char nome_grafo[20];

            char *results;

            char leitura[100];

            printf("Entre com o nome do grafo que deseja carregar: ");

            scanf("%s", &nome_grafo);

            strcat(nome_grafo, ".txt\0");

            arquivo = fopen(nome_grafo, "rt");

            while (1){

                results = fgets(leitura, 1000, arquivo);

                if(feof(arquivo)){break;}

                printf("%s", leitura);

            }

        }else if(entrada == 0){break;}
        else{
            printf("\nNumero invalido!\n\n");
        }

    }

    return 0;
}
