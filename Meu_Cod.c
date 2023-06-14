/*
- - - - - - - - - - - - - - TÓPICOS DE CADA CONTEÚDO NECESSÁRIO NO CÓDIGO - - - - - - - - - - - - -
A)
Defina uma estrutura Série contendo: Código (contador inteiro), Título (string), Gênero
(String), Classificação(int), Plataforma(String), Quantidade de temporadas(int),
Quantidade de episódios e cada temporada (vetor de inteiros), duração média dos
episódios. Deverá permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) as séries
disponíveis para serem assistidas nas plataformas. Essa relação deve aumentar e
diminuir dinamicamente.

B)
Defina uma estrutura Histórico que deve armazenar a relação de séries já assistidas por
um espectador, para isso utilize os códigos. Essa relação deve aumentar e diminuir
dinamicamente. Adicionalmente, armazene dados sobre a última temporada/episódio
assistido . O sistema deverá permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) os
históricos de séries assistidas.

C) V
Deverá permitir visualizar as séries por Gênero, navegando entre elas. Para isso utilize
cores, sons e sua criatividade.

D)
Deverá apresentar um menu inicial com as opções disponíveis. Caso necessário,
submenus. A interface deverá ser fácil e intuitiva, seja criativo, utilize cores e beeps :) .
Trate erros do usuário com mensagens e alertas;

E) V
A lista com os dados iniciais de todas as séries será construída colaborativamente (15
séries por grupo, sem repetição). Será gerado um arquivo .csv (valores separados por
vírgula) que deve ser lido e carregado em um vetor de tamanho dinâmico na primeira
abertura do programa.

F)
Ao sair do programa, todos os dados sobre as séries e históricos devem ser salvos em
arquivos binários no HD e recarregados novamente ao iniciar. Caso os arquivos não
existam, eles devem ser criados e uma mensagem de boas vindas deve ser apresentada
ao usuário;

G)
O sistema deverá exibir no menu uma opção de exportar ao dados das estruturas em
um arquivo texto no formato .CSV (separados por vírgula);
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -




- - - - - - - - - - - - - - - - - - OBSERVAÇÕES SOBRE O CÓDIGO - - - - - - - - - - - - - - - - - -
    Os códigos referentes a cada estrutura devem estar em um arquivo fonte (.c) separado
com seu respectivo arquivo de cabeçalho(.h). Utilize outros arquivos para organizar seu
código conforme necessidade;

    O programa deverá acompanhar um arquivo makefile que permita as operações básicas
de make (compilação), clean (limpeza) e run (execução);

    Como parte do critério de avaliação, a qualidade do código-fonte do sistema será
avaliada. Organize seu programa em arquivos .c e .h, funções. Evite o uso de variáveis
globais. O código deverá estar comentado, edentado e com bons nomes de variáveis e
funções. Siga o padrão de documentação apresentado na disciplina (Doxygen).
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/




//B I B L I O T E C A S;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>




//D E F I N I Ç Ã O   D E   C O R E S;
//LETRAS:
#define BLK "\033[0;30m" // Preto 
#define RED "\033[0;31m" // Vermelho
#define GRN "\033[0;32m" // Verde
#define YEL "\033[0;33m" // Amarelo
#define BLU "\033[0;34m" // Azul
#define MAG "\033[0;35m" // Magenta
#define CYN "\033[0;36m" // Ciano
#define WHT "\033[0;37m" // Branco

//FUNDO:
#define BLKB "\e[40m" // Fundo Preto
#define REDB "\e[41m" // Fundo Vermelho
#define GRNB "\e[42m" // Fundo Verde
#define YELB "\e[43m" // Fundo Amarelo
#define BLUB "\e[44m" // Fundo Azul
#define MAGB "\e[45m" // Fundo Magenta
#define CYNB "\e[46m" // Fundo Ciano
#define WHTB "\e[47m" // Fundo Branco




//F U N Ç Õ E S;
void funcao_LimpaTela(){
    printf("\033[2J\033[1;1H");
}//Função Limpa Tela LINUX;




//E S T R U T U R A S;
typedef struct{
    int codigo;
    char titulo[100];
    char genero[50];
    int classificacao;
    char plataforma[20];
    int duracao_med;
    int qnt_temporadas;
    char eps_por_temp[30];
} Serie;
//CONTEÚDO A);

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
//CONTEÚDO A);

typedef struct{
    char titulo[100];
    int codigo;
    int ultima_temp;
    int ultimo_ep;
}Historico;
//CONTEÚDO B);




//MAIN PRINCIPAL;
int main(){



    //PONTEIRO PARA ESTRUTURA SÉRIE;
    Serie *series;

    //VARIÁVEIS;
    int energia = 1;
    int opcao;
    int opcao_pesquisa;
    int opcao_historico;
    int binario_existe = 0;
    char c;
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

    //PONTEIRO PARA ABERTURA DOS ARQUIVOS;
    FILE* arq;
    FILE *arq_binario;
    FILE *historico_bin;


    




    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    - - - - - - - - - - - - - - - - - - - - - - MENU DE SÉRIES - - - - - - - - - - - - - - - - - - - - -*/
    /*

      while(energia == 1){

        funcao_LimpaTela();
        printf("\n\033[42m\033[1;32mC  O  D  F  L  I  X\033[1;32m\033[0m\n");
        printf("\033[1;32mO que deseja realizar no dia de hoje?\033[1;32m\n\n");
        printf("V - Visualizar séries\n");
        printf("1 - Pesquisar séries\n");
        printf("2 - Adicionar séries\n");
        printf("3 - Excluir séries\n");
        printf("4 - Histórico de séries\n");
        printf("5 - Fechar programa\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                funcao_LimpaTela();
                printf("\n\033[47m\033[1;32m##########-SÉRIES-##########\033[47m\033[1;32m\n");

                for(int  i = 0; i < contadorDeLinhasArquivo; i++){
                    printf("\nCSV: %d\n", series[i].codigo);
                    printf("Nome: %s\n", series[i].titulo);
                    printf("Gênero: %s\n", series[i].genero);
                    printf("FE: %d\n", series[i].classificacao);
                    printf("Plataforma: %s\n", series[i].plataforma);
                    printf("Duração média: %d\n", series[i].duracao_med);
                    printf("QTD temporada: %d\n", series[i].qnt_temporadas);
                    printf("EP por temp: %s\n", series[i].eps_por_temp);
                }//FOR DE EXIBIÇÃO DE DADOS DAS SÉRIES;
            break;



            case 1:
                funcao_LimpaTela();
                printf("\n\033[47m\033[1;32mDeseja pesquisar as séries por qual local?\033[47m\033[1;32m\n");
                printf("1 - Pelo nome da série\n");
                printf("2 - Pelo gênero da série\n");
                printf("3 - Pelo histórico de séries\n");
                printf("4 - Retornar ao menu inicial\n");
                printf("5 - Fechar programa\n");
                scanf("%d", &opcao_pesquisa);


            switch(opcao_pesquisa){
                case 1:
                    //PESQUISA POR NOME DA SÉRIE;
                    printf("\n\nPesquise o nome de uma série:");
                        fgets(nome_pesquisa,100, stdin);
                        nome_pesquisa[strcspn(nome_pesquisa,"\n")]='\0';
                        setbuf(stdin,NULL);

                        for(int i = 0;i<contadorDeLinhasArquivo;i++){
                            if(strcmp(nome_pesquisa,series[i].titulo) == 0){
                                printf("CSV: %d\n", series[i].codigo);
                                printf("Nome: %s\n", series[i].titulo);
                                printf("Gênero: %s\n", series[i].genero);
                                printf("FE: %d\n", series[i].classificacao);
                                printf("Plataforma: %s\n", series[i].plataforma);
                                printf("Duração média: %d\n", series[i].duracao_med);
                                printf("QTD temporada: %d\n", series[i].qnt_temporadas);
                                printf("EP por temp: %s\n", series[i].eps_por_temp);
                            }//IF PARA COMPARAÇÃO DO NOME DIGITADO, E DO NOME DE ALGUMA SÉRIE VETOR;

                        }//FOR PARA COMPARAR AS SÉRIES E PESQUISÁ-LAS PELO NOME;
                break;



                case 2:
                    //PESQUISA POR GÊNERO DA SÉRIE;
                    printf("\n\nPesquise um gênero:");
                        fgets(genero_pesquisa,100, stdin);
                        genero_pesquisa[strcspn(genero_pesquisa,"\n")]='\0';
                        setbuf(stdin,NULL);
                    printf("Séries de %s:\n",genero_pesquisa);

                    for(int i = 0;i<contadorDeLinhasArquivo;i++){
                        if (strcmp(genero_pesquisa,series[i].genero) == 0){
                            printf("Nome: %s\n", series[i].titulo);
                        }//IF PARA COMPARAÇÃO DO NOME DIGITADO, E DO NOME DE ALGUMA SÉRIE DO VETOR;

                    }//FOR PARA COMPARAR AS SÉRIES E PESQUISÁ-LAS PELO GÊNERO;
                break;
                


                case 3:
                    //PESQUISA POR HISTÓRICO DA SÉRIE;
                    printf("\n\nPesquisar no histórico:");
                    printf("\nInsira o título:");
                        fgets(pesquisa_historico,100, stdin);
                        pesquisa_historico[strcspn(pesquisa_historico,"\n")]='\0';
                        setbuf(stdin,NULL);

                    for(int i = 0;i<series_assistidas;i++){
                        if(strcmp(pesquisa_historico,historico[i-1].titulo) == 0){
                            printf("Nome: %s\n", historico[i-1].titulo);
                            printf("Última temporada assistida: %d\n", historico[i-1].ultima_temp);
                            printf("Último episódio assistido: %s\n", historico[i-1].ultimo_ep);
                        }//if;
                    }//for;
                break;



                case 4:
                    //LIMPA A TELA E RETORNA AO MENU;
                    funcao_LimpaTela();
                    printf("\033[40m\033[1,37m\n\033[40m\033[1;37m");
                break;



                case 5:
                    funcao_LimpaTela();
                    printf("\033[40m\033[1,37m\n\033[40m\033[1;37m");
                    exit(1);
                break;
                    
                
                default:
                    funcao_LimpaTela();
                    printf("\n\033[40m\033[1;31mERROR, você não selecionou nada!!!\033[40m\033[1;31m\n");
                break;
            }//SWITCH DA ESCOLHA DA PESQUISA EM QUAL LOCAL DESEJA PESQUISAR;
                    
        break;






        case '2':
            funcao_LimpaTela();
            printf("\n\033[47m\033[1;32mVocê selecionou a Adição de Séries\033[47m\033[1;32m\n");
        
            printf("\nDigite 1 para adicionar uma série.\n");
            setbuf(stdin,NULL);
            scanf("%d",&input_usuario);

            if(input_usuario==1){
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
                }//for;

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
            }//if;
            printf("Série adicionada!!\n");
        break;
  





        case '3':
            funcao_LimpaTela();
        break;




            
        case '4':
            funcao_LimpaTela();
            printf("\n\033[47m\033[1;32m##########-HISTÓRICO-##########\033[47m\033[1;32m\n");
            printf("1 - Visualizar\n");
            printf("2 - Adicionar Série\n");
            printf("3 - Excluir Série\n");
            printf("4 - Retornar ao Menu\n");
            printf("5 - Fechar programa\n");
            scanf("%d", &opcao_historico);

            switch(opcao_historico){
                case 1:
                    printf("\n\nExibir histórico:");
                    for(int i = 0;i<series_assistidas;i++){
                        printf("\nNome: %s\n", historico[i-1].titulo);
                        printf("Última temporada assistida: %d\n", historico[i-1].ultima_temp);
                        printf("Último episódio assistido: %d\n", historico[i-1].ultimo_ep);
                    }//FOR PARA EXIBIÇÃO DO HISTÓRICO;
                break;


                case 2:
                    printf("\n\nAdicionar série ao histórico:");
                    printf("\nNome da série:");
                        fgets(nome_historico,100, stdin);
                        nome_historico[strcspn(nome_historico,"\n")]='\0';
                        setbuf(stdin,NULL);

                    for(int i = 0;i<contadorDeLinhasArquivo;i++){
                        if(strcmp(nome_historico,series[i].titulo) == 0){
                            achado = i;   
                        } else {
                            achado = 0;
                        }//IF E ELSE PARA COMPARAR A SÉRIE ESCRITA COM A DO VETOR DE SÉRIES;
                    }//FOR PARA ENCONTRAR A SÉRIE DIGITADA;

                    if(achado != 0){
                        series_assistidas+=1;
                        historico = realloc(historico,series_assistidas*sizeof(Historico));
                        *historico[series_assistidas-1].titulo = nome_historico;
                        historico[series_assistidas-1].codigo = series[achado].codigo;
                        printf("\nInsira a última temporada assistida:");
                        scanf("%d",&historico[series_assistidas-1].ultima_temp);
                        printf("\nInsira o último episódio assistido:");
                        scanf("%d",&historico[series_assistidas-1].ultimo_ep);
                    }//IF SÉRIE FOI ENCONTRADA E ADICIONADA AO HISTÓRICO;
                break;



                case 3:
                    a;
                break;



                case 4:
                    //LIMPA A TELA E RETORNA AO MENU;
                    funcao_LimpaTela();
                    printf("\033[40m\033[1,37m\n\033[40m\033[1;37m");
                break;



                case 5:
                    funcao_LimpaTela();
                    printf("\033[40m\033[1,37m\n\033[40m\033[1;37m");
                    exit(1);
                break;
                
                default:
                    funcao_LimpaTela();
                    printf("\n\033[40m\033[1;31mERROR, você não selecionou nada!!!\033[40m\033[1;31m\n");
                break;
            }//SWITCH;
        break;




        case '5':
            funcao_LimpaTela();
            printf("\033[40m\033[1,37m\n\033[40m\033[1;37m");
            exit(1);
        break;



        default:
            funcao_LimpaTela();
            printf("\n\033[40m\033[1;31mERROR, você não selecionou nada!!!\033[40m\033[1;31m\n");
            break;
        }//SWITCH DE MENU;

    }//WHILE;
    */

    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/




   



    return 0;//FECHA O CÓDIGO;
}//MAIN;