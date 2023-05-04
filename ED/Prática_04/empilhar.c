#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int info;
    struct pilha* proximo;
} pilha;

pilha* inicializa_pilha(void) {
    return NULL;
}

void imprime_pilha(pilha* alfa) {
    if(alfa == NULL) {
        printf("*\n");
    }
    else {
        pilha* p;
        for(p = alfa ; p != NULL ; p = p->proximo) {
            printf("%d\n", p->info);
        }
    }
}

pilha* empilhar(pilha* alfa, int num) {
    pilha* novo = (pilha*)malloc(sizeof(pilha));
    novo->info = num;
    novo->proximo = NULL;
    if(alfa == NULL) {
        alfa = novo;
    }
    else {
        pilha* atual = alfa;
        while(atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    return alfa;
}

pilha* desempilhar(pilha* alfa) {
    if(alfa == NULL) {
        return alfa;
    }
    if(alfa->proximo == NULL) {
        free(alfa);
        return NULL;
    }
    pilha* penultimo = alfa;
    while(penultimo->proximo->proximo != NULL) {
        penultimo = penultimo->proximo;
    }
    free(penultimo->proximo);
    penultimo->proximo = NULL;
    return alfa;
}

int main(void) {
    pilha* teste;
    int qtd, num;
    char op;
    while(scanf("%d", &qtd) == 1) {
        teste = inicializa_pilha();
        for(int aux = 0 ; aux < qtd ; aux++) {
            scanf(" %c", &op);
            if(op == 'D') {
                teste = desempilhar(teste);
                imprime_pilha(teste);
            }
            else if(op == 'E') {
                scanf("%d", &num);
                teste = empilhar(teste, num);
                imprime_pilha(teste);
            }
        }
    }
    return 0;
}