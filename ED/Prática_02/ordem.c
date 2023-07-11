#include <stdio.h>
#include <stdlib.h>

/*
Código que faz a leitura de um vetor, e o ordena de forma crescente
*/

int main(void) {
    int TAM, pos, menor;
    int aux;
    scanf("%d", &TAM); // Faz a leitura do tamanho do vetor
    int vetor[TAM]; // Cria o vetor
    for(int a = 0 ; a < TAM ; a++) { // Faz a leitura dos elementos do vetor
        scanf("%d", &vetor[a]);
    }
    for (int a = 0 ; a < TAM ; a++) { // Percorre o vetor a partir do primeiro elemento
        menor = vetor[a]; // Assume como o valor a ser comparado com os seguintes para saber se é menor ou não
        pos = a;
        for (int b = a + 1 ; b < TAM ; b++) { // Compara com os elementos da posição seguinte ao que foi atribuida na linha 17
            if(vetor[b] < menor) { // Se um dos valores seguintes for menor que o elemento da linha 17 faz a troca dos dois valores
                menor = vetor[b];
                pos = b;
            }
        }
        aux = vetor[a];
        vetor[a] = vetor[pos];
        vetor[pos] = aux;
    }
    for(int a = 0 ; a < TAM ; a++) {
        printf("%d ", vetor[a]);
    }
}