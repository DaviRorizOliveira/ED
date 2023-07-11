#include <stdio.h>
#include <stdlib.h>
#define TAM 7 // Tamnho do vetor

/*
Você possui um vetor de números classificados em ordem não decrescente (do menor para o maior, mas pode ter
repetição). Pede-se se, dado um valor x, existem 2 números no vetor cuja soma seja exatamente x. Tente resolver este
olhando no máximo n elementos (o tamanho do vetor). (Dica: precisa começar das duas pontas).
*/

int main(void) {
    int x = 10;
    int vetor[TAM] = {1, 2, 3, 4, 5, 8, 11};
    for(int a = 0, b = TAM - 1 ; a < b ; ) {
        if(vetor[a] + vetor[b] == x) {
            printf("%d %d", vetor[a], vetor[b]);
            return 0;
        }
        else if(vetor[a] + vetor[b] < x) a++;
        else b--;
    }
    return 0;
}