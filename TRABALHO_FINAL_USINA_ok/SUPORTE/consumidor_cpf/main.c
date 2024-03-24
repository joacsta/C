#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#define TAM_CNPJ 19
#define TAM_CPF 15
#define TAM_NOME_MINIUSINA 100
#define TAM_ENERGIA_MINIUSINA 1000000 //OPCAO1_CONSULTAR_MINIUSINA
#define TAM_RA_MINIUSINA 99
#define TAM_STATUS_MINIUSINA 10
#define TAM_ID_CONTRATO 3
#define TAM_ID_CONSUMIDOR 19 //OPCAO1_CONSULTAR_MINIUSINA e OPCAO2_CONSULTAR_CONSUMIDOR
#define TAM_DATA_CONTRATO 11
#define TAM_NOME_CONSUMIDOR 100

struct consumidor1 //struct destinado para opcao 2
{
  char cnpj[TAM_CNPJ];
  char nome[TAM_NOME_CONSUMIDOR];
  char idra[TAM_RA_MINIUSINA];
};

struct consumidor2
{
    char cpf[TAM_CPF];
    char nome[TAM_NOME_CONSUMIDOR];
    char idra[TAM_RA_MINIUSINA];
};

void consumidor_cpf(const char *str) {
setlocale(LC_CTYPE, "Portuguese");
//struct consumidor2 consumidor_cad;   //void para a opcao 2, com a opcao de validacao apenas para cnpj
char cpf_consulta[TAM_CPF];
//int encontrei_consumidor = 0;
//FILE *arquivo_consumidor;
    int tamanho = strlen(str);
    int j = 0;      //DECLARACAO DE VARIAVEIS PARA A VALIDACAO DE CNPJ
    int icpf[TAM_CPF];
    int i, result1, result2, somador = 0;

printf("\nOPÇÃO 2, 'Consultar consumidor cadastrado' selecionada.\nPor favor, digite um CPF para realizar a operação: ");
scanf(" %[^\n]", cpf_consulta);

    for (int i = 0; i < tamanho; i++)
        {
        if (isdigit(str[i]))
            {
            cpf_consulta[j] = str[i];
            j++;
            }
        }
    cpf_consulta[j] = '\0';

    for (i = 0; i < 14; i++)
        {
        icpf[i] = cpf_consulta[i] - '0';
        }

    // Cálculo do primeiro dígito
    somador = icpf[0]*10 + icpf[1]*9 + icpf[2]*8 + icpf[3]*7 +
              icpf[4]*6 + icpf[5]*5 + icpf[6]*4 + icpf[7]*3 +
              icpf[8]*2;

    result1 = (somador % 11 < 2) ? 0 : 11 - (somador % 11);

    // Cálculo do segundo dígito
    somador = icpf[0]*11 + icpf[1]*10 + icpf[2]*9 + icpf[3]*8 +
              icpf[4]*7 + icpf[5]*6 + icpf[6]*5 + icpf[7]*4 +
              icpf[8]*3 + result1*2;

    result2 = (somador % 11 < 2) ? 0 : 11 - (somador % 11);

    if (result1 == icpf[9] && result2 == icpf[10]) {
        printf("CPF: válido\n\nCaso queira continuar, selecione outra opção.");
    } else {
        printf("CPF: inválido!\n\nCaso queira continuar, selecione outra opção.");
    }
}

int main()
{
    char cpf_ou_cnpj [100];
    fgets(cpf_ou_cnpj,sizeof(cpf_ou_cnpj), stdin);
    consumidor_cpf(cpf_ou_cnpj);
    return 0;
}
