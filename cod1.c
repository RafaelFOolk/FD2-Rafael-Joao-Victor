#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



typedef struct{
    int codigo;
    char titulo[100];
    char genero[50];
    int classificacao;
    char plataforma[20];
    int duracao_med;
    int qnt_temporadas;
    char eps_por_temp[30];
}Serie;



int main(){

    FILE *arq;
    char c;
    Serie *series;
    int  contadorDeLinhasArquivo = 0;
    arq = fopen("streaming_db.csv", "r");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo.\n");
        perror("Erro.");
    }
    while((c = fgetc(arq)) != EOF){
        if(c == '\n'){
            contadorDeLinhasArquivo++;
        } 
    }
    fclose(arq);



    arq = fopen("streaming_db.csv", "r");
    series = (Serie*) malloc(sizeof(Serie)*contadorDeLinhasArquivo);
    if(series == NULL){
        printf("Erro ao alocar memória para séries.\n");
        perror("Erro.");
    }
    for(int i=0; i<contadorDeLinhasArquivo; i++){
        char linha[200];
        fgets(linha,sizeof(linha),arq);
        sscanf(linha, "%d, %[^,], %[^,], %d, %[^,], %d, %d, %[^,\n]", &series[i].codigo, series[i].titulo, series[i].genero, &series[i].classificacao, series[i].plataforma, 
        &series[i].duracao_med, &series[i].qnt_temporadas, series[i].eps_por_temp);
        fflush(NULL);
    }
    fclose(arq);

        
        int deleta_serie;

        while(deleta_serie < 0 || deleta_serie > contadorDeLinhasArquivo){
            printf("\nDigite o código de uma série que deseje apagar: ");
            scanf("%d", &deleta_serie);
        }//W;
        
    
        int ultimo = 259;

      

        //series = (Serie*) realloc(series, ultimo * sizeof(Serie));

        for (int  i = 0; i < contadorDeLinhasArquivo; i++){

  
            printf("CSV: %d\n", series[i].codigo);
            printf("Nome: %s\n", series[i].titulo);
            printf("Gênero: %s\n", series[i].genero);
            printf("FE: %d\n", series[i].classificacao);
            printf("Plataforma: %s\n", series[i].plataforma);
            printf("Duração média: %d\n", series[i].duracao_med);
            printf("QTD temporada: %d\n", series[i].qnt_temporadas);
            printf("EP por temp: %s\n", series[i].eps_por_temp);
            
        
        }//for;

        printf("%d",contadorDeLinhasArquivo);

        
        
         for(int i=0;i<ultimo;i++){

            if(series[i].codigo == deleta_serie){
                for(int j = i; j<ultimo-1; j++){
                    series[j].codigo = series[j+1].codigo;
                    ultimo--;
                }      
                
            }
            printf("codigo = %d\n",series[i].codigo);
        }

      




            

       
        




    return 0;
}