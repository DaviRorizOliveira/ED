#include <stdio.h>
#include <stdlib.h>

/*
Cria uma estrutura de fila que armazena o peso (int) dos carros que entram em uma balsa e cria a funcao "enfileirar" que armazena estes valores
e retorna o peso total acumulado na balsa.
*/

#define TAM 1000

struct fila {
    int info[TAM];
    int inicio;
    int fim;
    int tamanho;
};
typedef struct fila Fila;

void enfileirar(Fila* alfa, int num) {
    int total = 0;
    alfa->fim++;
    alfa->tamanho++;
    alfa->info[alfa->fim] = num;
    for(int aux = 0 ; aux < alfa->tamanho ; aux++) {
        total = total + alfa->info[aux];
    }
    printf("%d\n", total);
}

int main (void) {
    Fila teste;
    teste.inicio = 0;
    teste.fim = -1;
    teste.tamanho = 0;
    enfileirar(&teste, 50);
    enfileirar(&teste, 500);
    enfileirar(&teste, 150);
    enfileirar(&teste, 100);
}