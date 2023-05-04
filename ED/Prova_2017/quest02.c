#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

void insere_decrescente(Lista* alfa, int num) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = NULL;
    if(alfa == NULL) {
        *alfa = *novo;
    }
    else {
        Lista* atual = alfa;
        Lista* anterior = NULL;
        while(atual != NULL && atual->info > num) {
            anterior = atual;
            atual = atual->prox;
        }
        if(anterior == NULL) {
            novo->prox = alfa;
            alfa = novo;
        }
        else {
            anterior->prox = novo;
            novo->prox = atual;
        }
    }
}

void imprime_lista(Lista* alfa) { // Função para imprimir a lista
    Lista* p;
    for(p = alfa ; p != NULL ; p = p->prox) {
        printf("%d\n", p->info);
    }
}

int main (void) {
    Lista* teste = NULL;
    insere_decrescente(teste, 14);
    insere_decrescente(teste, 2);
    insere_decrescente(teste, 53);
    insere_decrescente(teste, 109);
    insere_decrescente(teste, 0);
    insere_decrescente(teste, 29);
    imprime_lista(teste);
    return 0;
}