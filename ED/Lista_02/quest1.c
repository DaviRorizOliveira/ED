#include <stdio.h>
#include <stdlib.h>
#define TAM 10 // Tamnho do vetor

/*
Você possui um vetor de números inteiros. Quero fazer uma busca neste vetor para contar quantos são os elementos
pares e quantos os elementos ímpares. Para simplificar, vamos considerar o 0 (zero) como um número par.
*/

int par(int *vetor) { // Função que faz a contagem de quantos números pares há no vetor
    int cont = 0;
    for(int aux = 0 ; aux < TAM ; aux++) { // Laço for que percorre o vetor
        if(vetor[aux] % 2 == 0) cont++;
    }
    return cont;
}

int main(void) {
    int vet[TAM] = {1, 7, 14, 256, 17, 533, 4, 8, 9, 501}; // Inicialização do vetor com valores pré-determinados para teste
    printf("Par = %d\nImpar = %d", par(vet), 10 - par(vet));
    return 0;
}