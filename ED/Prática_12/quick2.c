//Estêvão Sousa - 202210345
//Larissa de Brito - 202210349
//Davi Roriz - 202210342
#include <stdio.h>
#include <stdlib.h>

void quickSort(int A[], int p, int r) {
    if (p < r) {
        int i = p;
        int j = r;
        int pivo = A[(p + r) / 2];
        printf("%d ", pivo);
        while (i <= j) {
            while (A[i] < pivo)
                i++;
            while (A[j] > pivo)
                j--;
            if (i <= j) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i++;
                j--;
            }
        }
        quickSort(A, p, j);
        quickSort(A, i, r);
    }
}

int main() {
    int N;
    while (scanf("%d", &N) == 1 && N != 0) {
        int vetor[N];
        for (int i = 0; i < N; i++)
            scanf("%d", &vetor[i]);
        quickSort(vetor, 0, N - 1);
        printf("\n\n");
    }
    return 0;
}