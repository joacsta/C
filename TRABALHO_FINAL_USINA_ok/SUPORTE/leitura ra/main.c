#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct num_RA {
    char idra[99];
    char cidade[30];
};

void RA() {
    FILE* arquivo_RA;
    struct num_RA RA_cad;

    arquivo_RA = fopen("ra.csv", "r");

    if (arquivo_RA != NULL) {
        char entrada_id[100];
        printf("Digite a ID da Região Administrativa: ");
        scanf(" %s", entrada_id);

        int encontrou = 0;

        while (fscanf(arquivo_RA, " %[^;];%[^\n]\n", RA_cad.idra, RA_cad.cidade) == 2) {
            if (strcmp(RA_cad.idra, entrada_id) == 0) {
                printf("N° Região Administrativa: %s\n", RA_cad.idra);
                printf("Cidade: %s\n\n", RA_cad.cidade);
                encontrou = 1;
            }
        }

        if (!encontrou) {
            printf("Nenhuma correspondência encontrada para a ID: %s\n", entrada_id);
        }

        fclose(arquivo_RA);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

int main() {
    setlocale(LC_CTYPE, "Portuguese");
    RA();
    return 0;
}
