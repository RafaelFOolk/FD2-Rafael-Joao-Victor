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

typedef struct{
    int codigo;
    char titulo[100];
    char genero[50];
    int classificacao;
    char plataforma[20];
    int duracao_med;
    int qnt_temporadas;
    char eps_por_temp[30];
}Serie2;

typedef struct{
    char titulo[100];
    int codigo;
    int ultima_temp;
    int ultimo_ep;
}Historico;




int main(){

    FILE *arq;
    FILE *arq_binario;
    FILE *historico_bin;
    int binario_existe = 0;
    char c;
    Serie *series;
    Serie2 nova_serie;
    Historico *historico;
    int  contadorDeLinhasArquivo = 0;


    int input_usuario=0;
    char nome_pesquisa[100];
    char genero_pesquisa[50];
    int achado = 0;

    char nome_historico[100];
    int ultimo_ep;
    int ultima_temp;
    int series_assistidas = 0;
    char pesquisa_historico[100];


    arq_binario = fopen("series.bin","r");{
        if (arq == NULL){
            binario_existe = 0;
        }
        else{
            binario_existe = 1;
        }

    }

if (binario_existe==0){
    printf("Boas-Vindas!");

}
    if (binario_existe == 0){
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
    historico = (Historico*) malloc(sizeof(Historico)*series_assistidas);
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
    }

    







        for (int  i = 0; i < contadorDeLinhasArquivo; i++)
        {


        printf("CSV: %d\n", series[i].codigo);
        printf("Nome: %s\n", series[i].titulo);
        printf("Gênero: %s\n", series[i].genero);
        printf("FE: %d\n", series[i].classificacao);
        printf("Plataforma: %s\n", series[i].plataforma);
        printf("Duração média: %d\n", series[i].duracao_med);
        printf("QTD temporada: %d\n", series[i].qnt_temporadas);
        printf("EP por temp: %s\n", series[i].eps_por_temp);
        }

        printf("%d",contadorDeLinhasArquivo);

    printf("\nDigite 1 para adicionar uma série.\n");
    setbuf(stdin,NULL);
    scanf("%d",&input_usuario);
    if (input_usuario==1){
        contadorDeLinhasArquivo+=1;
        printf("\nInsira o nome da série:");
        fgets(series[contadorDeLinhasArquivo].titulo,100, stdin);
        series[contadorDeLinhasArquivo].titulo[strcspn(nova_serie.titulo,"\n")]='\0';
        setbuf(stdin,NULL);
        printf("\nInsira o gênero da série:");
        fgets(series[contadorDeLinhasArquivo].genero,50, stdin);
        series[contadorDeLinhasArquivo].genero[strcspn(nova_serie.genero,"\n")]='\0';
        setbuf(stdin,NULL);
        printf("\nInsira a classificação da série:");
        scanf("%d",&nova_serie.classificacao);
        printf("\nInsira a plataforma da série:");
        fgets(series[contadorDeLinhasArquivo].plataforma,20, stdin);
        series[contadorDeLinhasArquivo].plataforma[strcspn(nova_serie.plataforma,"\n")]='\0';
        setbuf(stdin,NULL);
        printf("\nInsira a duração média da série em minutos:");
        scanf("%d",&nova_serie.duracao_med);
        printf("\nInsira a quantidade de temporadas da série:");
        scanf("%d",&nova_serie.qnt_temporadas);
        printf("Insira a quantidade de episódios por temporada:");
        for (int i = 0;i<nova_serie.qnt_temporadas;i++){
            printf("%dª:",i+1);
            scanf("%d",&nova_serie.eps_por_temp[i]);
        }

            series = realloc(series,contadorDeLinhasArquivo*sizeof(Serie));
            *series[contadorDeLinhasArquivo].titulo=nova_serie.titulo;
            *series[contadorDeLinhasArquivo].genero=nova_serie.genero;
            series[contadorDeLinhasArquivo].classificacao=nova_serie.classificacao;
            *series[contadorDeLinhasArquivo].plataforma=nova_serie.plataforma;
            series[contadorDeLinhasArquivo].duracao_med=nova_serie.duracao_med;
            series[contadorDeLinhasArquivo].qnt_temporadas=nova_serie.qnt_temporadas;
            *series[contadorDeLinhasArquivo].eps_por_temp=nova_serie.eps_por_temp;




        arq = fopen("streaming_db.csv", "w");
        fwrite(&series[contadorDeLinhasArquivo],1,sizeof(Serie),arq);
        fclose(arq);
    }
    
        printf("\nPesquise o nome de uma série:");
        fgets(nome_pesquisa,100, stdin);
        nome_pesquisa[strcspn(nome_pesquisa,"\n")]='\0';
        setbuf(stdin,NULL);

        for(int i = 0;i<contadorDeLinhasArquivo;i++){
            if (strcmp(nome_pesquisa,series[i].titulo) == 0){
                printf("CSV: %d\n", series[i].codigo);
                printf("Nome: %s\n", series[i].titulo);
                printf("Gênero: %s\n", series[i].genero);
                printf("FE: %d\n", series[i].classificacao);
                printf("Plataforma: %s\n", series[i].plataforma);
                printf("Duração média: %d\n", series[i].duracao_med);
                printf("QTD temporada: %d\n", series[i].qnt_temporadas);
                printf("EP por temp: %s\n", series[i].eps_por_temp);
            }

        }

        printf("\nPesquise um gênero:");
        fgets(genero_pesquisa,100, stdin);
        genero_pesquisa[strcspn(genero_pesquisa,"\n")]='\0';
        setbuf(stdin,NULL);
        printf("Séries de %s:\n",genero_pesquisa);
        for(int i = 0;i<contadorDeLinhasArquivo;i++){
            if (strcmp(genero_pesquisa,series[i].genero) == 0){
                 printf("Nome: %s\n", series[i].titulo);
        }
        }

    printf("\nAdicionar série ao histórico:");
    printf("\nNome da série:");
    fgets(nome_historico,100, stdin);
        nome_historico[strcspn(nome_historico,"\n")]='\0';
        setbuf(stdin,NULL);
         for(int i = 0;i<contadorDeLinhasArquivo;i++){
            if (strcmp(nome_historico,series[i].titulo) == 0){
                achado=i;   
        }
            else{
                achado = 0;
            }
        }
            if (achado != 0){
        series_assistidas+=1;
        historico = realloc(historico,series_assistidas*sizeof(Historico));
        *historico[series_assistidas-1].titulo = nome_historico;
        historico[series_assistidas-1].codigo = series[achado].codigo;
        printf("\nInsira a última temporada assistida:");
        scanf("%d",&historico[series_assistidas-1].ultima_temp);
        printf("\nInsira o último episódio assistido:");
        scanf("%d",&historico[series_assistidas-1].ultimo_ep);
            }

    printf("\nPesquisar no histórico:");
        printf("\nInsira o título:");
        fgets(pesquisa_historico,100, stdin);
        pesquisa_historico[strcspn(pesquisa_historico,"\n")]='\0';
        setbuf(stdin,NULL);

         for(int i = 0;i<series_assistidas;i++){
            if (strcmp(pesquisa_historico,historico[i-1].titulo) == 0){
                 printf("Nome: %s\n", historico[i-1].titulo);
                 printf("Última temporada assistida: %d\n", historico[i-1].ultima_temp);
                 printf("Último episódio assistido: %s\n", historico[i-1].ultimo_ep);
        }
        }

    printf("\nExibir histórico:");
        for(int i = 0;i<series_assistidas;i++){
                 printf("\nNome: %s\n", historico[i-1].titulo);
                 printf("Última temporada assistida: %d\n", historico[i-1].ultima_temp);
                 printf("Último episódio assistido: %s\n", historico[i-1].ultimo_ep);
        }




    FILE *arq_binario = fopen("series.bin","wb");
    FILE *historico_bin = fopen("historico.bin","wb");

        fwrite(series,sizeof(Serie),contadorDeLinhasArquivo,arq_binario);
        fwrite(historico,sizeof(Historico),contadorDeLinhasArquivo,historico_bin);



    return 0;
}