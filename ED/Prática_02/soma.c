#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int TAM;
    scanf("%d", &TAM);
    int vetor1[TAM];
    int vetor2[TAM];
    for(int aux = 0 ; aux < TAM ; aux++) {
        scanf("%d", &vetor1[aux]);
    }
    for(int aux = 0 ; aux < TAM ; aux++) {
        scanf("%d", &vetor2[aux]);
    }
    for(int a = 0, b = TAM - 1 ; a <= TAM, b >= 0 ; a++, b--) {
        printf("%d ", vetor1[a] + vetor2[b]);
    }
}