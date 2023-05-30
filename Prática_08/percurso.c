//Estêvão Sousa - 202210345
//Larissa de Brito - 202210349
//Davi Roriz - 202210342
#include <stdio.h>
#include <stdlib.h>

struct arvore {
    int info;
    struct arvore* left;
    struct arvore* right;
};
typedef struct arvore Arvore;

Arvore* inicializa_Arvore(int num) {
    Arvore* novo = (Arvore*)malloc(sizeof(Arvore));
    novo->info = num;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
}

Arvore* inserir(Arvore* pai, int num) {
    if (pai == NULL) {
        return inicializa_Arvore(num);
    }
    if (num <= pai->info) {
        pai->left = inserir(pai->left, num);
    } else {
        pai->right = inserir(pai->right, num);
    }
    return pai;
}

void preordem(Arvore* pai) {
    if (pai != NULL) {
        printf("%d ", pai->info);
        preordem(pai->left);
        preordem(pai->right);
    }
}

void posordem(Arvore* pai) {
    if (pai != NULL) {
        posordem(pai->left);
        posordem(pai->right);
        printf("%d ", pai->info);
    }
}

void libera_Arvore(Arvore* pai) {
    if (pai != NULL) {
        libera_Arvore(pai->left);
        libera_Arvore(pai->right);
        free(pai);
    }
}

int main(void) {
    int N;
    while (scanf("%d", &N) == 1 && N != 0) {
        Arvore* pai = NULL;
        for (int i = 0 ; i < N ; i++) {
            int num;
            scanf("%d", &num);
            pai = inserir(pai, num);
        }
        preordem(pai);
        printf("\n");
        posordem(pai);
        printf("\n\n");
        libera_Arvore(pai);
    }
    return 0;
}