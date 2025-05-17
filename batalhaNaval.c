#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração do tabuleiro 10x10, inicializado com zeros (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posicionamento do primeiro navio (horizontal)
    // Coordenadas iniciais (linha e coluna)
    int linhaNavio1 = 2; // exemplo: linha 2
    int colunaNavio1 = 4; // exemplo: coluna 4

    // Posicionamento do segundo navio (vertical)
    int linhaNavio2 = 5; // exemplo: linha 5
    int colunaNavio2 = 7; // exemplo: coluna 7

    // Verificação de validade das posições do primeiro navio (horizontal)
    if (linhaNavio1 < 0 || linhaNavio1 >= TAMANHO_TABULEIRO ||
        colunaNavio1 < 0 || colunaNavio1 + TAMANHO_NAVIO - 1 >= TAMANHO_TABULEIRO) {
        printf("Posição do primeiro navio inválida.\n");
        return 1;
    }

    // Verificação de validade das posições do segundo navio (vertical)
    if (linhaNavio2 < 0 || linhaNavio2 + TAMANHO_NAVIO - 1 >= TAMANHO_TABULEIRO ||
        colunaNavio2 < 0 || colunaNavio2 >= TAMANHO_TABULEIRO) {
        printf("Posição do segundo navio inválida.\n");
        return 1;
    }

    // Checar sobreposição dos navios
    // Para simplificar, verificamos se as posições do primeiro navio se sobrepõem ao segundo
    bool sobrepoem = false;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int pos1_linha = linhaNavio1;
        int pos1_coluna = colunaNavio1 + i;

        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            int pos2_linha = linhaNavio2 + j;
            int pos2_coluna = colunaNavio2;

            if (pos1_linha == pos2_linha && pos1_coluna == pos2_coluna) {
                sobrepoem = true;
                break;
            }
        }
        if (sobrepoem) break;
    }

    if (sobrepoem) {
        printf("Os navios se sobrepõem. Posicione-os em locais diferentes.\n");
        return 1;
    }

    // Posiciona o navio horizontal na matriz
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavio1][colunaNavio1 + i] = 3;
    }

    // Posiciona o navio vertical na matriz
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavio2 + i][colunaNavio2] = 3;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i <
