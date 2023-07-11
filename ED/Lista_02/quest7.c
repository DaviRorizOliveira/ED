#include <stdio.h>
#include <stdlib.h>
#define TAM 9

/*
O jogo SUDOKU é um jogo no qual, em um tabuleiro 9 × 9 deve-se escrever números de 1 a 9 de forma que: em cada
linha existam todos os números de 1 a 9, o mesmo em cada coluna e também em cada um dos 9 sub quadrantes 3 × 3
que o tabuleiro é dividido. Pede-se que implemente um programa que armazene uma solução do jogo na forma de um
vetor bidimensional e que verifique se a solução apresentada está correta, ou se apresenta conflitos, neste caso deve-se
imprimir as coordenadas (linha,coluna) dos valores em conflito (as coordenadas são de 1 a 9).
*/

void verifica(int *vetor) {
    int a, b, c;
    int cont = 0;
    for(a = 0 ; a < TAM ; a++) {
        for(b = 0 ; b < TAM ; b++) {
            for(c = b + 1 ; c < TAM ; c++) {
                if (vetor[a][b] == vetor[a][c]) {
                    printf("[%d][%d] e [%d][%d]\n", a, b, a, c);
                    cont++;
                }
            }
        }
    }
    for(b = 0 ; b < TAM ; b++) {
        for(a = 0 ; a < TAM ; a++) {
            for(c = a + 1 ; c < TAM ; c++) {
                if (vetor[a][b] == vetor[c][b]) {
                    printf("[%d][%d] e [%d][%d]\n", a, b, c, b);
                    cont++;
                }
            }
        }
    }
}

int main(void) {
    int sudoku1[TAM][TAM] = {
        1, 4, 8, 9, 5, 3, 7, 6, 2,
        9, 2, 5, 7, 1, 6, 4, 8, 3,
        6, 7, 3, 4, 2, 8, 5, 9, 1,
        7, 5, 4, 8, 3, 1, 6, 2, 9,
        8, 1, 6, 2, 9, 7, 3, 4, 5,
        3, 9, 2, 5, 6, 4, 1, 7, 8,
        2, 6, 9, 3, 7, 5, 8, 1, 4,
        5, 8, 1, 6, 4, 9, 2, 3, 7,
        4, 3, 7, 1, 8, 2, 9, 5, 6
    };
    int sudoku2[TAM][TAM] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9,
        4, 5, 6, 7, 8, 9, 1, 2, 3,
        7, 8, 9, 1, 2, 3, 8, 5, 6,
        2, 3, 4, 5, 6, 7, 8, 9, 1,
        5, 6, 7, 8, 9, 1, 2, 3, 4,
        9, 8, 1, 2, 3, 4, 5, 6, 7,
        3, 4, 5, 6, 7, 8, 9, 1, 2,
        6, 7, 8, 9, 1, 2, 3, 4, 5,
        9, 1, 2, 3, 4, 5, 6, 7, 8
    };
    return 0;
}