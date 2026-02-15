#include <stdio.h>

int main() {


    // CRIAÇÃO DO TABULEIRO 10x10

    int tabuleiro[10][10];
    int linha, coluna;

    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // NAVIOS

    int tamanhoNavio = 3;

    int linhaH = 1, colunaH = 2;
    int linhaV = 7, colunaV = 3;

    int i;

    for (i = 0; i < tamanhoNavio; i++)
        tabuleiro[linhaH][colunaH + i] = 3;

    for (i = 0; i < tamanhoNavio; i++)
        tabuleiro[linhaV + i][colunaV] = 3;

    // EXIBIÇÃO FORMATADA (facil de mudar os simbolos)
    
    printf("===== TABULEIRO COM HABILIDADES =====\n\n");

    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {

            if (tabuleiro[linha][coluna] == 0)
                printf("0 ");

            else if (tabuleiro[linha][coluna] == 3)
                printf("3 ");
        }
        printf("\n");
    }

    return 0;
}
