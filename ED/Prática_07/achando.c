#include <stdio.h>
#include <stdlib.h>

typedef struct listafilhos {
    struct arvore *filho;
    struct listafilhos *prox;
} listafilhos;

typedef struct arvore {
    char info;
    listafilhos *prole;
    struct arvore *pai;
} arvore;

void iniciar(arvore *a, char info) {
    a->info = info;
    a->prole = NULL;
    a->pai = NULL;
}

char info(arvore *a) {
    return a->info;
}

int altura(arvore *a) {
    if (a == NULL)
        return 0;

    int maxAlturaFilhos = 0;
    listafilhos *aux = a->prole;
    while (aux != NULL) {
        int alturaFilho = altura(aux->filho);
        if (alturaFilho > maxAlturaFilhos) {
            maxAlturaFilhos = alturaFilho;
        }
        aux = aux->prox;
    }

    return maxAlturaFilhos + 1;
}

int profundidade(arvore *a) {
    if (a == NULL)
        return -1;

    int profundidadePai = profundidade(a->pai);

    return profundidadePai + 1;
}

arvore *pai(arvore *a) {
    return a->pai;
}

int filhos(arvore *a) {
    int count = 0;
    listafilhos *aux = a->prole;
    while (aux != NULL) {
        count++;
        aux = aux->prox;
    }
    return count;
}

arvore *filho(arvore *a, int i) {
    listafilhos *aux = a->prole;
    int count = 1;
    while (aux != NULL && count < i) {
        aux = aux->prox;
        count++;
    }
    return aux != NULL ? aux->filho : NULL;
}

int insereFilho(arvore *a, arvore *f) {
    listafilhos *novo = (listafilhos *)malloc(sizeof(listafilhos));
    novo->filho = f;
    novo->prox = NULL;

    if (a->prole == NULL) {
        a->prole = novo;
    } else {
        listafilhos *aux = a->prole;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    f->pai = a;

    return 1;
}

void removeFilho(arvore *a, int i) {
    if (a->prole == NULL)
        return;

    if (i == 1) {
        listafilhos *aux = a->prole;
        a->prole = aux->prox;
        free(aux);
    } else {
        listafilhos *ant = a->prole;
        listafilhos *atual = ant->prox;
        int count = 2;

        while (atual != NULL && count < i) {
            ant = atual;
            atual = atual->prox;
            count++;
        }

        if (atual != NULL) {
            ant->prox = atual->prox;
            free(atual);
        }
    }
}

int achando(arvore *a, char c) {
    if (a == NULL)
        return 0;

    if (a->info == c)
        return 1;

    listafilhos *aux = a->prole;
    while (aux != NULL) {
        int encontrado = achando(aux->filho, c);
        if (encontrado)
            return 1;
        aux = aux->prox;
    }

    return 0;
}

int main() {
    arvore a, b, c, d, e, f;
    iniciar(&a, 'A');
    iniciar(&b, 'B');
    iniciar(&c, 'C');
    iniciar(&d, 'D');
    iniciar(&e, 'E');
    iniciar(&f, 'F');

    insereFilho(&a, &b);
    insereFilho(&a, &c);
    insereFilho(&a, &d);
    insereFilho(&b, &e);
    insereFilho(&b, &f);

    printf("%d\n", achando(&a, 'A'));  // 1
    printf("%d\n", achando(&a, 'B'));  // 1
    printf("%d\n", achando(&a, 'C'));  // 1
    printf("%d\n", achando(&a, 'D'));  // 1
    printf("%d\n", achando(&a, 'E'));  // 1
    printf("%d\n", achando(&a, 'F'));  // 1
    printf("%d\n", achando(&a, 'G'));  // 0

    return 0;
}
