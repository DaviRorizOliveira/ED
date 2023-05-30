#include <stdio.h>
#include <stdlib.h>

struct arvore {
    int info;
    struct arvore* esquerda;
    struct arvore* direita;
};
typedef struct arvore Arvore;

Arvore* inicializa_Arvore(int num) {
    Arvore* novo = (Arvore*)malloc(sizeof(Arvore));
    novo->info = num;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

Arvore* inserir(Arvore* pai, int num) {
    if (pai == NULL) {
        return inicializa_Arvore(num);
    }
    if (num <= pai->info) {
        pai->esquerda = inserir(pai->esquerda, num);
    } else {
        pai->direita = inserir(pai->direita, num);
    }
    return pai;
}

int altura(Arvore* pai) {
    if (pai == NULL) {
        return 0;
    }
    int altura_esq = altura(pai->esquerda);
    int altura_dir = altura(pai->direita);
    return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
}

int balanceada(Arvore* pai) {
    if (pai == NULL) {
        return 1;
    }
    int altura_esq = altura(pai->esquerda);
    int altura_dir = altura(pai->direita);
    if (abs(altura_esq - altura_dir) > 1) {
        return 0;
    }
    return balanceada(pai->esquerda) && balanceada(pai->direita);
}

void libera_Arvore(Arvore* pai) {
    if (pai != NULL) {
        libera_Arvore(pai->esquerda);
        libera_Arvore(pai->direita);
        free(pai);
    }
}

int main(void) {
    int N;
    while (scanf("%d", &N) == 1 && N != 0) {
        Arvore* pai = NULL;
        for (int i = 0; i < N; i++) {
            int num;
            scanf("%d", &num);
            pai = inserir(pai, num);
        }
        if (balanceada(pai)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        libera_Arvore(pai);
    }
    return 0;
}
