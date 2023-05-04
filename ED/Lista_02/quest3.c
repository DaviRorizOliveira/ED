#include <stdio.h>
#include <stdlib.h>
#define TAM1 4 // TAM1 vai indicar a quantidade de pontos existentes
#define TAM2 2 // TAM2 vai indicar os valores de X e Y dos pontos

/*
Considere uma área retangular, marcada pelos pontos que delimitam seus cantos: inferior-esquerdo, inferior-direito,
superior-direito e superior-esquerdo. Considere um conjunto de pontos na forma de um vetor. Faça um algoritmo que
conte quantos pontos se encontram dentro da área retangular.
*/

int main(void) {
    int area[TAM1][TAM2] = {
        0, 0, // Inferior esquerdo
        0, 5, // Superior esquerdo
        3, 0, // Inferior direito
        3, 5  // Superior dideito
    };
    int pontos[TAM1][TAM2] = { // Pontos pré-determinados para testes
        0, 1, // Ponto 1 de testes
        1, -1, // Ponto 2 de testes
        5, 2, // Ponto 3 de testes
        3, 0  // Ponto 4 de testes
    };
    int result = 0; // Variável que conta quantos pontos estão dentro do retângulo
    for(int a = 0 ; a < TAM1 ; a++) { // Laço for que faz uma busca entre os pontos para determinar se eles estão presentes dentro da área
        if(pontos[a][0] >= area[0][0] && pontos[a][0] <= area[3][0]) {
            if(pontos[a][1] >= area[0][1] && pontos[a][1] <= area[3][1]) result++; // Em caso positivo, o resultado é incrementado em 1
        }
    }
    printf("%d", result);
    return 0;
}