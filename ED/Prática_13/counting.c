//Estêvão Sousa - 202210345
//Larissa de Brito - 202210349
//Davi Roriz - 202210342
#include <stdio.h>
#include <stdlib.h>

void countingSort(int A[], int B[], int C[], int n, int k) {
    for (int i = 0; i <= k; i++)
        C[i] = 0;

    for (int j = 0; j < n; j++)
        C[A[j]]++;

    for (int i = 1; i <= k; i++)
        C[i] += C[i - 1];

    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

int main() {
    int N;
    while (scanf("%d", &N) == 1 && N != 0) {
        int A[N];
        int B[N];
        int C[2 * N + 1];

        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        countingSort(A, B, C, N, 2 * N);

        for (int i = 1; i <= 2 * N; i++)
            printf("%d ", C[i]);
        printf("\n");

        for (int i = 0; i < N; i++)
            printf("%d ", B[i]);
        printf("\n\n");
    }

    return 0;
}