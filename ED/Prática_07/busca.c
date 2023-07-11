#include <stdio.h>

#define N 3

typedef struct arvore {
    char info;
    struct arvore *filhos[N];
    struct arvore *pai;
} arvore;

void preordem(arvore *a) {
    if (a == NULL)
        return;

    printf("%c", a->info);

    for (int i = 0; i < N; i++) {
        preordem(a->filhos[i]);
    }
}

void posordem(arvore *a) {
    if (a == NULL)
        return;

    for (int i = 0; i < N; i++) {
        posordem(a->filhos[i]);
    }

    printf("%c", a->info);
}

int main() {
    // Exemplo de uso das funções
    arvore a = { 'A', { NULL, NULL, NULL }, NULL };
    arvore b = { 'B', { NULL, NULL, NULL }, NULL };
    arvore c = { 'C', { NULL, NULL, NULL }, NULL };
    arvore d = { 'D', { NULL, NULL, NULL }, NULL };
    arvore e = { 'E', { NULL, NULL, NULL }, NULL };
    arvore f = { 'F', { NULL, NULL, NULL }, NULL };

    a.filhos[0] = &b;
    a.filhos[1] = &c;
    a.filhos[2] = &d;
    b.filhos[0] = &e;
    b.filhos[1] = &f;

    preordem(&a);
    printf("\n");
    posordem(&a);

    return 0;
}