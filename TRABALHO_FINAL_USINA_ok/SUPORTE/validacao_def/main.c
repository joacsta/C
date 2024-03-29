#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#define TAM_CNPJ 19

void validacao_e_consulta_cnpj(const char *str) {
    int tamanho = strlen(str);
    char cnpj[TAM_CNPJ];
    int j = 0;
    int icnpj[TAM_CNPJ];
    int i, digito1, digito2, result1, result2, valor, somador = 0;

    for (int i = 0; i < tamanho; i++) {
        if (isdigit(str[i])) {
            cnpj[j] = str[i];
            j++;
        }
    }

    cnpj[j] = '\0';

    for (i = 0; i < 14; i++) {
        icnpj[i] = cnpj[i] - '0';
    }

    // C�lculo do primeiro d�gito
    somador = icnpj[0]*5 + icnpj[1]*4 + icnpj[2]*3 + icnpj[3]*2 +
              icnpj[4]*9 + icnpj[5]*8 + icnpj[6]*7 + icnpj[7]*6 +
              icnpj[8]*5 + icnpj[9]*4 + icnpj[10]*3 + icnpj[11]*2;

    result1 = somador % 11;
    digito1 = (result1 < 2) ? 0 : 11 - result1;

    // C�lculo do segundo d�gito
    somador = icnpj[0]*6 + icnpj[1]*5 + icnpj[2]*4 + icnpj[3]*3 +
              icnpj[4]*2 + icnpj[5]*9 + icnpj[6]*8 + icnpj[7]*7 +
              icnpj[8]*6 + icnpj[9]*5 + icnpj[10]*4 + icnpj[11]*3 + icnpj[12]*2;
    valor = (somador / 11) * 11;
    result2 = somador - valor;
    digito2 = (result2 < 2) ? 0 : 11 - result2;

    if (digito1 == icnpj[12] && digito2 == icnpj[13]) {
        printf("O CNPJ � v�lido!\n");
    } else {
        printf("O CNPJ � n�o � v�lido!\n");
    }

setlocale(LC_CTYPE, "Portuguese");
struct usina usina_cadastrada;
char cnpj_consulta[TAM_CNPJ];
int encontrei_usina = 0;
FILE *arquivo_usina;


printf("\nPor favor, confirme o CNPJ para a consulta: ");
scanf(" %[^\n]", cnpj_consulta);

arquivo_usina = fopen("miniusinas.csv", "r");

if(arquivo_usina != NULL)
    {
    while(!feof(arquivo_usina))
        {
        fscanf(arquivo_usina, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
            usina_cadastrada.cnpj,
            usina_cadastrada.nome,
            usina_cadastrada.energia,
            usina_cadastrada.idra,
            usina_cadastrada.status); //Escaneamneto e armazenamento

        if (strcmp(cnpj_consulta, usina_cadastrada.cnpj)==0) //Compara�ao de entrada com o arquivo
            {
            printf("\nAQUI EST�O AS SEGUINTES INFORMA��ES SOLICITADAS.");
            printf("\n\nCNPJ: %s\n", usina_cadastrada.cnpj);
            printf("Nome da Usina: %s\n", usina_cadastrada.nome);
            printf("Capacidade de energia: %s\n", usina_cadastrada.energia);
            printf("Regi�o Administrativa: %s\n", usina_cadastrada.idra);
            printf("Status: %s\n", usina_cadastrada.status);
            encontrei_usina = 1;
            }
        }
        if(encontrei_usina == 0)
            {
            printf("\nAVISO!\nN�o foi encontrada nenhuma usina com o CNPJ: %s.", cnpj_consulta);
            }
    }else
        {
        printf("ERRO, N�O FOI POSS�VEL ABRIR O ARQUIVO.");
        }

    FILE *arquivo_contrato;
    struct contrato contrato_cadastrado;
    arquivo_contrato = fopen("contratos.csv", "r");
    int encontrei_contrato = 0;

    if(arquivo_contrato != NULL)
    {
    while(!feof(arquivo_contrato))
        {
        fscanf(arquivo_contrato, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
               contrato_cadastrado.idcontrato,
               contrato_cadastrado.idconsumidor,
               contrato_cadastrado.cnpj,
               contrato_cadastrado.inicio_data,
               contrato_cadastrado.energiacontratada); //Escaneamneto e armazenamento

        if (strcmp(cnpj_consulta, contrato_cadastrado.cnpj)==0) //Compara�ao de entrada com o arquivo
            {
            printf("ID Contrato: %s\n", contrato_cadastrado.idcontrato);
            printf("ID Consumidor: %s\n", contrato_cadastrado.idconsumidor);
            printf("Data: %s\n", contrato_cadastrado.inicio_data);

            encontrei_contrato = 1;
            }
        }
        if(encontrei_contrato == 0)
            {
            printf("\nN�o foi encontrada nenhum contrato com o CNPJ: %s.\nPor favor, selecione outra op��o.\n", cnpj_consulta);
            }
    }else
        {
        printf("\nERRO, N�O FOI POSSIVEL ABRIR O ARQUIVO.\n\n");
        }


}

int main()
{
    char cnpj_consulta[TAM_CNPJ];

    printf("Digite um CNPJ: ");
    fgets(cnpj_consulta, sizeof(cnpj_consulta), stdin);

    validacao_e_consulta_cnpj(cnpj_consulta);

    return 0;
}
