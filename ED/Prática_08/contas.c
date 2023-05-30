#include <stdio.h>
#include <stdlib.h>

struct arvore {
    int info;
    struct arvore* left;
    struct arvore* right;
};
typedef struct arvore Arvore;

Arvore* inicializa_arvore(int num) {
    Arvore* novo = (Arvore*)malloc(sizeof(Arvore));
    novo->info = num;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
}

int avaliar_expressao(Arvore* raiz) {
    if (raiz->left == NULL && raiz->right == NULL) {
        return raiz->info;
    }

    int esquerda = avaliar_expressao(raiz->left);
    int direita = avaliar_expressao(raiz->right);

    switch (raiz->info) {
        case '+':
            return esquerda + direita;
        case '-':
            return esquerda - direita;
        case '*':
            return esquerda * direita;
        case '/':
            return esquerda / direita;
        default:
            return 0; // Operador inválido
    }
}

Arvore* construir_arvore(char expressao[], int* indice) {
    if (expressao[*indice] == '(') {
        (*indice)++;
        if (expressao[*indice] == '(') {
            Arvore* no = inicializa_arvore(0);
            no->left = construir_arvore(expressao, indice);
            (*indice)++; // Pular o ')'
            no->info = expressao[*indice] - '0';
            (*indice)++;
            no->right = construir_arvore(expressao, indice);
            (*indice)++; // Pular o ')'
            return no;
        } else {
            Arvore* no = inicializa_arvore(expressao[*indice] - '0');
            (*indice)++; // Pular o ')'
            return no;
        }
    } else {
        return NULL;
    }
}

void liberar_arvore(Arvore* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->left);
        liberar_arvore(raiz->right);
        free(raiz);
    }
}

int main(void) {
    int N;
    while (scanf("%d", &N) == 1) {
        if (N == 0) {
            break;
        }
        getchar();
        char expressao[100];
        int i;
        for (i = 0; i < N - 1; i++) {
            scanf("%c", &expressao[i]);
        }
        expressao[N - 1] = '\0';
        int indice = 0;
        Arvore* raiz = construir_arvore(expressao, &indice);
        int resultado = avaliar_expressao(raiz);
        printf("%d\n", resultado);
        liberar_arvore(raiz);
    }
    return 0;
}