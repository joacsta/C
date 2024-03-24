#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //inclusao de bibliotecas
#include <locale.h>
#include <ctype.h>
// Definicoes de biblioteca

#define OPCAO1_CONSULTAR_MINIUSINA 1
#define OPCAO2_CONSULTAR_CONSUMIDOR 2
#define OPCAO3_LISTAGEM_MINIUSINAS 3
#define OPCAO4_LISTAGEM_MINIUSINAS_OPERACAO_DECRESCENTE 4
#define OPCAO5_LISTAGEM_RAS_ORDEM_DESCRESCENTE_QUANTIDADE_MINIUSINAS 5
#define OPCAO6_LISTAGEM_RAS_ORDEM_CRESCENTE_CONTRATOS 6 //opcoes do menu
#define OPCAO7_LISTAGEM_RAS_ORDEM_DESCRESCENTE_CAPACIDADE_GERACAO 7
#define OPCAO8_LISTAGEM_RAS_ORDEM_DESCRESCENTE_PERCENTUAL_ENERGIA_DISPONIVEL 8
#define OPCAO9_SAIR 9

#define TAM_CNPJ 19
#define TAM_CPF 15
#define TAM_NOME_MINIUSINA 100 //tamanho permitido de caracteres
#define TAM_ENERGIA_MINIUSINA 100 //OPCAO1_CONSULTAR_MINIUSINA
#define TAM_RA_MINIUSINA 99
#define TAM_STATUS_MINIUSINA 10

#define TAM_ID_CONTRATO 3 //tamanho permitido de caracteres
#define TAM_ID_CONSUMIDOR 19 //OPCAO1_CONSULTAR_MINIUSINA e OPCAO2_CONSULTAR_CONSUMIDOR
#define TAM_DATA_CONTRATO 11

#define TAM_NOME_CONSUMIDOR 100 //OPCAO2_CONSULTAR_CONSUMIDOR

struct miniusinaopcao6 {
    char cnpj[TAM_CNPJ];
    char nome[TAM_NOME_MINIUSINA];
    char energia[TAM_ENERGIA_MINIUSINA];
    char idra[TAM_RA_MINIUSINA];
    int idrainteiro;
    char status[TAM_STATUS_MINIUSINA];
    float capacidade;

};

// Definição do registro para representar um contrato no software
struct contratosopcao6 {
    char idcontrato[TAM_ID_CONTRATO];
    char idconsumidor[TAM_ID_CONSUMIDOR];
    char energia[TAM_ENERGIA_MINIUSINA];
    char cnpj[TAM_CNPJ];
    char datacontrato[TAM_DATA_CONTRATO];
    float energia_contratada;
};


// Definição do registro para representar uma ra no software
struct raopcao6 {
    char idra[TAM_RA_MINIUSINA];
    char nome_ra[TAM_NOME_CONSUMIDOR];
    int quantidade;
    int id_ra;
    int quantidade_contratos;
    float capacidade_total;
    float percentual_energia_disponivel;
};

struct consumidoropcao6 {
    char id_consumidor[TAM_ID_CONSUMIDOR];
    char nome[100];
    int id_ra;
};

void SortRasPorContratosCrescente(struct ra *ras, int quantidade_ras) {
    int i, j, minIndex;
    struct ra temp;

    for (i = 0; i < quantidade_ras - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < quantidade_ras; j++) {
            if (ras[j].quantidade_contratos < ras[minIndex].quantidade_contratos) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = ras[i];
            ras[i] = ras[minIndex];
            ras[minIndex] = temp;
        }
    }
}

void listar_ras_ordenadas_por_contratos_crescente() {
    FILE *arquivo_consumidores;
    FILE *arquivo_contratos;
    FILE *arquivo_ra;
    struct consumidor consumidores[100];
    struct contratos contratos[100];
    struct ra ras[100];
    int quantidade_consumidores = 0;
    int quantidade_contratos = 0;
    int quantidade_ras = 0;

    // Abertura dos arquivos
    arquivo_consumidores = fopen("consumidores.csv", "r");
    arquivo_contratos = fopen("contratos.csv", "r");
    arquivo_ra = fopen("ra.csv", "r");

    if (arquivo_consumidores != NULL && arquivo_contratos != NULL && arquivo_ra != NULL) {
        // Leitura dos consumidores
        char linha_consumidor[1000];
        fscanf(arquivo_consumidores, "%[^\n]\n", linha_consumidor);  // Ignora a primeira linha

        while (fscanf(arquivo_consumidores, "%[^;];%[^;];%d\n",
                      consumidores[quantidade_consumidores].id_consumidor,
                      consumidores[quantidade_consumidores].nome,
                      &consumidores[quantidade_consumidores].id_ra) == 3) {
            quantidade_consumidores++;
        }

        // Leitura dos contratos
        char linha_contrato[1000];
        fscanf(arquivo_contratos, "%[^\n]\n", linha_contrato);  // Ignora a primeira linha

        while (fscanf(arquivo_contratos, "%[^;];%[^;];%[^;];%[^;];%f\n",
                      contratos[quantidade_contratos].idcontrato,
                      contratos[quantidade_contratos].idconsumidor,
                      contratos[quantidade_contratos].cnpj,
                      contratos[quantidade_contratos].datacontrato,
                      &contratos[quantidade_contratos].energia_contratada) == 5) {
            quantidade_contratos++;
        }

        // Leitura das RAs
        char linha_ra[1000];
        fscanf(arquivo_ra, "%[^\n]\n", linha_ra);  // Ignora a primeira linha

        while (fscanf(arquivo_ra, "%d;%[^\n]\n",
                      &ras[quantidade_ras].id_ra,
                      ras[quantidade_ras].nome_ra) == 2) {
                      ras[quantidade_ras].quantidade_contratos = 0;
                      quantidade_ras++;
        }

        // Verificação dos contratos para cada consumidor
        for (int i = 0; i < quantidade_consumidores; i++) {
            for (int j = 0; j < quantidade_contratos; j++) {
                if (strcmp(consumidores[i].id_consumidor, contratos[j].idconsumidor) == 0) {
                    for (int k = 0; k < quantidade_ras; k++) {
                        if (consumidores[i].id_ra == ras[k].id_ra) {
                            ras[k].quantidade_contratos++;
                            break;
                        }
                    }
                    break;
                }
            }
        }

        // Ordenação das RAs por quantidade de contratos
        SortRasPorContratosCrescente(ras, quantidade_ras);

        // Exibição das RAs
        for (int i = 0; i < quantidade_ras; i++) {
            printf("\nID_RA: %d\n", ras[i].id_ra);
            printf("Nome_RA: %s\n", ras[i].nome_ra);
            printf("Quantidade de Contratos: %d\n", ras[i].quantidade_contratos);
        }

        // Fechamento dos arquivos
        fclose(arquivo_consumidores);
        fclose(arquivo_contratos);
        fclose(arquivo_ra);
    } else {
        printf("Erro, nao foi possivel abrir os arquivos.\n");
    }

}
