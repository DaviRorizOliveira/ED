#include <stdio.h>
#include <stdlib.h>
#define TAM 5 // Tamanho do vetor

/*
Considere um vetor de números racionais. Utilize o algoritmo do Bubble-Sort para classificá-lo em ordem não decrescente.
*/

void bubblesort(int *vetor) { // Função que faz o algoritmo do Bubble-Sort
    int aux;
    for(int a = 0 ; a < TAM - 1 ; a++) {
        for(int b = 0 ; b < TAM - a - 1 ; b++) {
            if(vetor[b] > vetor[b + 1]) {
                aux = vetor[b];
                vetor[b] = vetor[b + 1];
                vetor[b + 1] = aux;
            }
        }
    }
}

int main(void) {
    int vet[TAM] = {10, 57, 0, 256, 4}; // Valores do vetor pré-determinados para teste
    bubblesort(vet); // Chamada da função
    for(int aux = 0 ; aux < TAM ; aux++) {
        printf("%d ", vet[aux]);
    }
    return 0;
}