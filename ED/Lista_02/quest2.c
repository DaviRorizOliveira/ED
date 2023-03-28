#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 30 // Tamnho do vetor

/*
Eu tenho um vetor representando os dias de um mês (1 a 30), para quem se lembra do biorritmo, o biorritmo representa
quando uma situação é favorável ou não de acordo com sua intensidade. No caso o biorritmo para o amor naquele
mês é representado pela funçãoo: f(x) = sin(0.126x − 1.6). Queremos um algoritmo construa um vetor armazenando a
intensidade do biorritmo para cada dia e, indique qual o dia no qual o biorritmo para o amor é mais intenso e vale a
pena arriscar sair para conquistar uma paixão.
*/

int main(void) {
    float zero = -0.000001; // Variável auxiliar para descobrir o maior biorritmo
    int result; // Dia que o amor é mais intenso
    int dias[TAM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    float bioint[TAM];
    for(int aux = 0 ; aux < TAM ; aux++) { // Laço for que percorre o vetor
        bioint[aux] = sin(0.126 * dias[aux] - 1.6);
        if(bioint[aux] > zero) {
            zero = bioint[aux];
            result = aux + 1;
        }
    }
    printf("%d", result);
    return 0;
}