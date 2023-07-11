//Estêvão Sousa - 202210345
//Larissa de Brito - 202210349
//Davi Roriz - 202210342
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 1000

struct pilha {
    int info[TAM];
    int topo;
};
typedef struct pilha Pilha;

void empilhar(Pilha* alfa, char c) {
    alfa->topo++;
    alfa->info[alfa->topo] = c;
}

char desempilhar(Pilha* alfa) {
    char c = alfa->info[alfa->topo];
    alfa->topo--;
    return c;
}

char topo(Pilha *alfa) {
   return alfa->info[alfa->topo];
}

int main(void) {
    char exp[TAM];
    Pilha operadores;
    Pilha posfixa;
    operadores.topo = -1;
    posfixa.topo = -1;
    while(scanf("%c", exp) == 1) {
        for(int aux = 0 ; exp[aux] != NULL ; aux++) {
            if(isalpha(exp[aux])) {
                empilhar(&posfixa, exp[aux]);
            }
            else if (exp[aux] == '(') { // se é parenteses aberto, adiciona na pilha de operadores
                empilhar(&operadores, exp[0]);
            }
            else if (exp[aux] == ')') { // se é parenteses fechado, desempilha todos os operadores até encontrar o parenteses aberto correspondente
                while (topo(&operadores) != '(') {
                    char op = desempilhar(&operadores);
                    empilhar(&posfixa, op);
                }
                desempilhar(&operadores);
            }
            else if (exp[aux] == '+' || exp[aux] == '-' || exp[aux] == '*' || exp[aux] == '/') {
                while (operadores.topo >= 0 && topo(&operadores) != '(' && precedencia(topo(&operadores)) >= precedencia(exp[aux])) {
                    char op = desempilhar(&operadores);
                    empilhar(&posfixa, op);
                }
                empilhar(&operadores, exp[aux]);
            }
        }
    }
    while (operadores.topo >= 0) {
        char op = desempilhar(&operadores);
        empilhar(&posfixa, op);
    }
    for(int aux = 0 ; aux <= posfixa.topo ; aux++) {
        printf("%c", posfixa.info[aux]);
    }
    printf("\n");
    return 0;
}