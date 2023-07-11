//Estêvão Sousa - 202210345
//Larissa de Brito - 202210349
//Davi Roriz - 202210342
#include <stdio.h>
#include <stdlib.h>

#define TAM 6

struct no {
    int chave[TAM];
    struct no* filhos[TAM + 1];
    int info;
};

struct no* inicializar() {
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    novo->info = 0;
    for (int aux = 0 ; aux < TAM + 1 ; aux++) {
        novo->filhos[aux] = NULL;
    }
    return novo;
}

void insertValue(struct no** pai, int value, int M) {
    if ((*pai) == NULL) {
        struct no* novo = inicializar();
        novo->chave[0] = value;
        novo->info = 1;
        (*pai) = novo;
        return;
    }
    if ((*pai)->info < M - 1) {
        int i = (*pai)->info - 1;
        while (i >= 0 && (*pai)->chave[i] > value) {
            (*pai)->chave[i + 1] = (*pai)->chave[i];
            i--;
        }
        (*pai)->chave[i + 1] = value;
        (*pai)->info++;
        return;
    }

    int i = 0;
    while (i < (*pai)->info && (*pai)->chave[i] < value) {
        i++;
    }

    insertValue(&((*pai)->filhos[i]), value, M);
}

int altura(struct no* pai) {
    if (pai == NULL) {
        return -1;
    }
    int alturaMaxFilho = -1;
    for (int i = 0 ; i < pai->info + 1 ; i++) {
        int alturaFilho = altura(pai->filhos[i]);
        if (alturaFilho > alturaMaxFilho) {
            alturaMaxFilho = alturaFilho;
        }
    }
    return alturaMaxFilho + 1;
}

int main(void) {
    int M, N;
    while (scanf("%d %d", &M, &N) == 2) {
        int* valor = (int*)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            scanf("%d", &valor[i]);
        }
        struct no* pai = NULL;
        for (int i = 0; i < N; i++) {
            insertValue(&pai, valor[i], M);
        }
        int height = altura(pai);
        printf("%d\n", height);
        free(valor);
    }
    return 0;
}