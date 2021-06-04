#include <iostream>
#include <time.h>
//definindo a struct
typedef struct estrutura
{

    char nome[41];         //nome
    int ano_de_nascimento; //ano de nascimento
    char cargo[21];        //cargo
    float salario;         //salario
    struct estrutura *p;   //ponteiro
} estrutura;               // definindo a struct estrutura como estrutura apenas

int main()
{
    //gravando o ano
    int anoAtual;
    time_t data_ano;
    time(&data_ano);
    struct tm *data = localtime(&data_ano);
    anoAtual = (data->tm_year + 1900);
    // ...............

    // guardar dados
    FILE *ponteiro_arquivo;                     //ponteiro que aponta para o arquivo de texto
    ponteiro_arquivo = fopen("dados.txt", "a"); //criando arquivo
    if (ponteiro_arquivo == NULL)               //se não houver espaço
    {
        printf("erro no programa!"); //erro no programa
        exit(1);
    }

    //.............

    int m;                                        //variavel de controle para adicionar uma nova estrutura
    estrutura *ini;                               //ponteiro que aponta para a estrutura inicial
    estrutura *prox;                              //ponteiro que aponta para a próxima estrutura
    ini = (estrutura *)malloc(sizeof(estrutura)); //criação da estrutura
    if (ini == NULL)                              //se o ponteiro inicial for NULL
    {
        printf("VAZIO");
        exit(1);
    }
    prox = ini; //o proximo ponteiro criará uma estrutura semelhante
    while (1)   //enquanto 1(repetição controlada por m)
    {
        fprintf(ponteiro_arquivo, "\n...............................\n");
        printf("\n nome: \t");
        setbuf(stdin, NULL); //para evitar o bug do fgets
        fgets(prox->nome, 40, stdin);
        fflush(stdin);
        fprintf(ponteiro_arquivo, "\nNome: %s", prox->nome); //escreve no arquivo

        printf("\n ano de nascimento: \t");
        scanf("%d", &prox->ano_de_nascimento);
        fprintf(ponteiro_arquivo, "\nano de nascimento: %d", prox->ano_de_nascimento); //escreve no arquivo
        printf("\n cargo: \t");
        setbuf(stdin, NULL);
        fgets(prox->cargo, 20, stdin);
        fflush(stdin);
        fprintf(ponteiro_arquivo, "\ncargo: %s", prox->cargo); //escreve no arquivo

        printf("\n salario: \t");
        scanf("%f", &prox->salario);
        fprintf(ponteiro_arquivo, "salário: %.2f R$", prox->salario); //escreve no arquivo

        printf("\n deseja cadastrar mais pessoas? <1>SIM  <2>NÂO \t");
        scanf("%d", &m);
        if (m == 1)
        {
            prox->p = (estrutura *)malloc(sizeof(estrutura));
            prox = prox->p;
        }
        else //se não for adicionar mais estruturas a repetição acaba.

            break;
    }
    prox->p = NULL; //o ponteiro da ultima estrutura aponta pra null
    prox = ini;     // o ponteiro prox aponta para o ponteiro inicial

    //impressão
    while (prox != NULL)
    {
        printf("\n...............Funcionario..................");
        printf("\n Nome:..............%s", prox->nome);
        printf(" idade:..............%d\n", anoAtual - (prox->ano_de_nascimento));
        printf(" cargo:..............%s", prox->cargo);
        printf(" salario:.............. %.2f R$\n", prox->salario);

        prox = prox->p;
        printf("......................................\n");
    }
    fclose(ponteiro_arquivo);
    return 0;
}
