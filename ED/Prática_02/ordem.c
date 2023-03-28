#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int TAM, pos, menor;
    int aux;
    scanf("%d", &TAM);
    int vetor[TAM];
    for(int a = 0 ; a < TAM ; a++) {
        scanf("%d", &vetor[a]);
    }
    for (int a = 0 ; a < TAM ; a++) {
        menor = vetor[a];
        pos = a;
        for (int b = a + 1 ; b < TAM ; b++) {
            if(vetor[b] < menor) {
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