//Estêvão Sousa - 202210345
//Larissa de Brito - 202210349
//Davi Roriz - 202210342
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int info;
    struct pilha* proximo;
} pilha;

pilha* inicializa_pilha(void) {
    return NULL;
}
/* Aqui há um erro onde você mistura dois conceitos:
1 - alfa aponta para o primeiro elemento da pilha, e deve ser atualizado quando empilhar para apontar para o novo elemento.
2 - alfa é um ponteiro fixo no início da pilha e o próximo elemento é o topo da pilha.
*/
void imprime_pilha(pilha* alfa) {
    if(alfa == NULL) {
        printf("*");
    }
    else {
        pilha* p;
/* Foi pedido para imprimir do topo à base, 
   Você tem duas opções:
   1 - Crie um ponteiro para o anterior (e guarde o final para facilitar) e imprima sentido ant
   2 - Crie a pilha colocando os novos elementos no começo da lista e não no final
   Observe que o 2 == 1 se trabalharmos no 1 só com o ponteiro de final e ant, ao invés do alfa e prox.
*/
        for(p = alfa ; p != NULL ; p = p->proximo) { 
            printf("%d ", p->info); // Faltou um espaço aqui: printf("%d ", ...
        }
    }
}

/* Do jeito que você fez, tanto empilhar, quanto desempilhar é O(n) quando poderia ser O(1) */
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
                printf("\n");
            }
            else if(op == 'E') {
                scanf("%d", &num);
                teste = empilhar(teste, num);
                imprime_pilha(teste);
                printf("\n");
            }
        }
    }
    return 0;
}