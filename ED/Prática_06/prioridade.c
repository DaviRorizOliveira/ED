//Estêvão Sousa - 202210345
//Larissa de Brito - 202210349
//Davi Roriz - 202210342
#include <stdio.h>
#include <stdlib.h>

#define TAM 1000

struct fila {
    int info[TAM];
    int inicio;
    int fim;
    int tamanho;
};
typedef struct fila Fila;

void inicializar(Fila* alfa) {
    alfa->inicio = 0;
    alfa->fim = -1;
    alfa->tamanho = 0;
}

void imprime_fila(Fila* alfa) {
    if(alfa->fim == -1) {
        printf("*\n"); // Se a fila estiver vazia, printa *
    }
    else { // Se não, percorre a fila printando seus valores
        for(int aux = 0 ; aux <= alfa->fim ; aux++) {
            printf("%d ", alfa->info[aux]);
        }
        printf("\n");
    }
}

void enfileirar(Fila* alfa, int num) {
    alfa->fim++;
    alfa->tamanho++;
    alfa->info[alfa->fim] = num;
}

int desenfileirar(Fila* alfa) {
    if(alfa->tamanho == 0) {
        return -1;
    }
    int maior = alfa->info[alfa->inicio];
    int pos_maior = alfa->inicio;
    for(int aux = alfa->inicio + 1 ; aux <= alfa->fim ; aux++) {
        if(alfa->info[aux] > maior) {
            maior = alfa->info[aux];
            pos_maior = aux;
        }
    }
    for(int aux = pos_maior ; aux < alfa->fim ; aux++) {
        alfa->info[aux] = alfa->info[aux + 1];
    }
    alfa->fim--;
    alfa->tamanho--;
    return maior;
}

int main(void) {
    Fila* teste;
    int N, num;
    char op;
    while(scanf("%d", &N) == 1) {
        inicializar(&teste);
        for(int aux = 0 ; aux < N ; aux++) {
            scanf(" %c", &op);
            if(op == 'D') {
                int max = desenfileirar(&teste);
            }
            else if(op == 'E') {
                scanf("%d", &num);
                enfileirar(&teste, num);
            }
            imprime_fila(&teste);
        }
    }
    return 0;
}