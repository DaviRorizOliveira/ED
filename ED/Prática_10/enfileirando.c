// Estêvão Sousa - 202210345
// Larissa de Brito - 202210349
// Davi Roriz - 202210342
#include <stdio.h>
#include <stdlib.h>

#define TAM 1000

struct heapfila {
    int info[TAM];
    int fim;
};
typedef struct heapfila Heapfila;

void inicializar(Heapfila *alfa) {
    alfa->fim = 0;
}

void enfileirar(Heapfila *p, int obj) {
    int i;
    if (p->fim != TAM) {
        p->info[p->fim++] = obj;
        i = p->fim;
        while ((i > 1) && (p->info[i - 1] > p->info[i / 2 - 1])) {
            int temp = p->info[i - 1];
            p->info[i - 1] = p->info[i / 2 - 1];
            p->info[i / 2 - 1] = temp;
            i = i / 2;
        }
    }
}

int desenfileirar(Heapfila *alfa) {
    int i = 1, max = 1;
    int o, para = 0;
    o = alfa->info[0];
    alfa->info[0] = alfa->info[--alfa->fim];
    while (!para) {
        if (((2 * i) <= alfa->fim) && (alfa->info[i - 1] < alfa->info[2 * i - 1]))
            max = 2 * i;
        if (((2 * i + 1) <= alfa->fim) && (alfa->info[max - 1] < alfa->info[2 * i]))
            max = 2 * i + 1;
        if (i != max) {
            int temp = alfa->info[i - 1];
            alfa->info[i - 1] = alfa->info[max - 1];
            alfa->info[max - 1] = temp;
            i = max;
        }
        else {
            para = 1;
        }
    }
    return o;
}

void imprime_fila(Heapfila *alfa) {
    if (alfa->fim == -1) {
        printf("*\n");
    }
    else {
        for (int aux = 0; aux < alfa->fim; aux++) {
            printf("%d ", alfa->info[aux]);
        }
        printf("\n");
    }
}

int main(void) {
    Heapfila *teste;
    int N, num;
    char op;
    while (scanf("%d", &N) == 1 && N != 0) {
        teste = malloc(sizeof(Heapfila));
        inicializar(teste);
        for (int aux = 0; aux < N; aux++) {
            scanf(" %c", &op);
            if (op == 'D') {
                int max = desenfileirar(teste);
                printf("%d", max);
                printf("\n");
            }
            else if (op == 'E') {
                scanf("%d", &num);
                enfileirar(teste, num);
                imprime_fila(teste);
            }
        }
        printf("\n");
        free(teste);
    }
    return 0;
}