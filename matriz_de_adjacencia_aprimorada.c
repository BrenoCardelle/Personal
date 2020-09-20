#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
    while(1){

        FILE *arquivo = NULL;

        int entrada;

        printf("Selecione (1) para carregar um grafo ou (2) para criar um grafo ou (0) para encerrar o programa: ");

        scanf("%d", &entrada);

        if(entrada == 2){

            char nome_grafo[50];

            printf("Entre com o nome do grafo que deseja criar: ");

            scanf("%s", &nome_grafo);

            strcat(nome_grafo, ".txt\0");

            arquivo = fopen(nome_grafo, "r");

            if(arquivo!=NULL){
                printf("Arquivo com nome ja existente, por favor selecione outro. \n\n");
                fclose(arquivo);
                continue;
            }

            printf("Indique o n para a matriz de nxn: ");

            int n;

            scanf("%d", &n);

            int matriz[n][n];

            int i,j;

            char alf[27] = "0abcdefghijklmnopqrstuvwxyz";

            for(i=0; i<n; i++){
                matriz[i][i] = 0;
                for(j=(i+1); j<n; j++){
                    printf(" %c eh vizinho de %c? R(s)|(n): ", alf[i+1], alf[j+1]);
                    while(1){
                        char aux;
                        scanf("%s", &aux);
                        if(aux == 's'){
                            matriz[i][j] = 1;
                            matriz[j][i] = 1;
                            break;
                        } else if(aux == 'n'){
                            matriz[i][j] = 0;
                            matriz[j][i] = 0;
                            break;
                        } else {printf("invalido.\n");
                            printf(" %c eh vizinho de %c? R(s)|(n): ", alf[i+1], alf[j+1]);
                        }
                    }

                }
                printf("\n");

            }

            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    printf("%d ", matriz[i][j]);
                }
                printf("\n");
            }

            arquivo = fopen(nome_grafo, "a"); // Abre o arquivo

            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    fprintf(arquivo, "%d ", matriz[i][j]);
                }
                fprintf(arquivo, "\n");

            }

            fclose(arquivo); // Fecha arquivo

        }else if(entrada == 1){

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
