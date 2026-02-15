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
    int linhaD1 = 6, colunaD1 = 0;
    int linhaD2 = 7, colunaD2 = 7;

    int i;

    for (i = 0; i < tamanhoNavio; i++)
        tabuleiro[linhaH][colunaH + i] = 3;

    for (i = 0; i < tamanhoNavio; i++)
        tabuleiro[linhaV + i][colunaV] = 3;

    for (i = 0; i < tamanhoNavio; i++)
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;

    for (i = 0; i < tamanhoNavio; i++)
        tabuleiro[linhaD2 + i][colunaD2 + i] = 3;


    // MATRIZES DE HABILIDADE 5x5
    int tamanho = 5;
    int centro = tamanho / 2;

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    for (linha = 0; linha < tamanho; linha++) {
        for (coluna = 0; coluna < tamanho; coluna++) {

            // CONE 
            if (linha >= centro &&
                coluna >= centro - (linha - centro) &&
                coluna <= centro + (linha - centro))
                cone[linha][coluna] = 1;
            else
                cone[linha][coluna] = 0;

            // CRUZ
            if (linha == centro || coluna == centro)
                cruz[linha][coluna] = 1;
            else
                cruz[linha][coluna] = 0;

            // OCTAEDRO (losango)
            if ((linha - centro < 0 ? centro - linha : linha - centro) +
                (coluna - centro < 0 ? centro - coluna : coluna - centro) <= centro)
                octaedro[linha][coluna] = 1;
            else
                octaedro[linha][coluna] = 0;
        }
    }

    // POSIÇÃO DAS HABILIDADES NO TABULEIRO
    int origemConeL = 1, origemConeC = 7;
    int origemCruzL = 6, origemCruzC = 6;
    int origemOctL = 4, origemOctC = 2;

    int l, c;

    // SOBREPOR CONE
    for (l = 0; l < tamanho; l++) {
        for (c = 0; c < tamanho; c++) {
            if (cone[l][c] == 1) {
                int tabL = origemConeL + l - centro;
                int tabC = origemConeC + c - centro;

                if (tabL >= 0 && tabL < 10 && tabC >= 0 && tabC < 10) {
                    if (tabuleiro[tabL][tabC] == 0)
                        tabuleiro[tabL][tabC] = 5;
                }
            }
        }
    }

    // SOBREPOR CRUZ
    for (l = 0; l < tamanho; l++) {
        for (c = 0; c < tamanho; c++) {
            if (cruz[l][c] == 1) {
                int tabL = origemCruzL + l - centro;
                int tabC = origemCruzC + c - centro;

                if (tabL >= 0 && tabL < 10 && tabC >= 0 && tabC < 10) {
                    if (tabuleiro[tabL][tabC] == 0)
                        tabuleiro[tabL][tabC] = 5;
                }
            }
        }
    }

    // SOBREPOR OCTAEDRO
    for (l = 0; l < tamanho; l++) {
        for (c = 0; c < tamanho; c++) {
            if (octaedro[l][c] == 1) {
                int tabL = origemOctL + l - centro;
                int tabC = origemOctC + c - centro;

                if (tabL >= 0 && tabL < 10 && tabC >= 0 && tabC < 10) {
                    if (tabuleiro[tabL][tabC] == 0)
                        tabuleiro[tabL][tabC] = 5;
                }
            }
        }
    }

    // EXIBIÇÃO FORMATADA (facil de mudar os simbolos)
    
    printf("===== TABULEIRO COM HABILIDADES =====\n\n");

    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {

            if (tabuleiro[linha][coluna] == 0)
                printf("0 ");

            else if (tabuleiro[linha][coluna] == 3)
                printf("3 ");

            else if (tabuleiro[linha][coluna] == 5)
                printf("5 ");
        }
        printf("\n");
    }

    return 0;
}
