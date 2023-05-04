#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct lista {
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializa_lista(void) { // Função para inicializar a lista com NULL
    return NULL;
}
Lista* insere_lista(Lista* alfa, int num) { // Função para inserir um elemento na lista
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = alfa;
    return novo;
}
Lista* insere_ultimo(Lista* alfa, int num) { // Função para inserir um elemento no final da lista
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = num;
    novo->prox = NULL;
    if(alfa == NULL) {
        alfa = novo;
    }
    else {
        Lista* atual = alfa;
        while(atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    return novo;
}
void imprime_lista(Lista* alfa) { // Função para imprimir a lista
    Lista* p;
    for(p = alfa ; p != NULL ; p = p->prox) {
        printf("Elemento: %d\n", p->info);
    }
}
int maior_lista(Lista* alfa) { // Função para achar o maior valor na lista
    int maior = INT_MIN;
    for(alfa ; alfa != NULL ; alfa = alfa->prox) {
        if(alfa->info > maior) maior = alfa->info;
    }
    return maior;
}
int conta_lista(Lista* alfa) { // Função para contar quantos elementos tem na lista
    int cont = 0;
    for(alfa ; alfa != NULL ; alfa = alfa->prox) {
        cont++;
    }
    return cont;
}
Lista* exclui_eneximo_no_lista(Lista* alfa, int num) { // Função para excluir o enésimo nó da lista
    Lista* novo;
    if(num == 1){
        Lista* proximo = alfa->prox;
        return proximo;
    }
    int x = 1;
    for(novo = alfa ; novo != NULL ; novo = novo->prox, x++) {
        if(x + 1 == num){
            Lista* aux = novo->prox;
            novo->prox = aux->prox;
            free(aux);
            break;
        }
    }
    return alfa;
}
Lista* exclui_elemento_n_lista(Lista* alfa, int num) { // Função para excluir o primeiro elemento n da lista
    Lista* novo;
    Lista* aux;
    for(novo = alfa ; novo->prox != NULL && novo->prox->info != num ; novo = novo->prox) {
    }
    if(novo->prox->info == num) {
        aux = novo->prox;
        novo->prox = aux->prox;
        free(aux);
    }
    return alfa;
}
Lista* inverte_lista(Lista* alfa) { // Função para inverter a lista
    Lista* novo;
    Lista* aux = NULL;
    novo = alfa->prox;
    alfa->prox = NULL;
    do {
        aux = novo->prox;
        novo->prox = alfa;
        alfa = novo;
        novo = aux;
    } while(novo != NULL);
    return alfa;
}
Lista* pares_lista(Lista* alfa) { // Função para retornar a lista apenas com números pares
    Lista* novo;
    Lista* aux;
    novo = inicializa_lista();
    for(aux = alfa ; aux != NULL ; aux = aux->prox){
         if(aux->info % 2 == 0){
             novo = insere_lista(novo, aux->info);
         }
    }
    return novo;
}
Lista* exclui_todo_n_lista(Lista* alfa, int num) { // Função para excluir todos os elementos n da lista
    Lista* novo;
    Lista* aux;
    novo = inicializa_lista();
    for(aux = alfa ; aux != NULL ; aux = aux->prox) {
        if(aux->info != num) {
            novo = insere_lista(novo, aux->info);
        }
    }
    return novo;
}
Lista* exclui_primeiro_no_lista(Lista* alfa) { // Função para excluir o primeiro nó da lista
    Lista* novo;
    novo = alfa->prox;
    return novo;
}
int verifica_lista(Lista* alfa) { // Função que verifica se a lista está vazia ou não
    if(alfa == NULL) {
        return 0;
    }
    else {
        return 1;
    }
}
int tamanho_lista(Lista* alfa) { // Função que verifica o tamanho da lista
    Lista* p;
    int aux;
    for(p = alfa ; p != NULL ; p = p->prox) {
        aux++;
    }
    return aux;
}
int no_maior_n(Lista* alfa, int num) { // Função que conta quantos "info" da lista são maiores que o número n
    Lista* aux;
    int cont = 0;
    for(aux = alfa ; aux != NULL ; aux = aux->prox) {
        if(aux->info > num) {
            cont++;
        }
    }
    return cont;
}
Lista* exclui_n_primeiros_no(Lista* alfa, int num) { // Função que exclui os n primeiros nós da lista
    int cont = 0;
    do {
        alfa = alfa->prox;
        cont++;
    } while(cont < num);
    return alfa;
}
Lista* vetor_lista(int* vet, int tam) {
    Lista* alfa;
    alfa = inicializa_lista();
    for(int aux = 0 ; aux < tam ; aux++) {
        alfa = insere_lista(alfa, vet[aux]);
    }
    return alfa;
}

int main(void) {
    Lista* teste;
    int maior;
    int vetor[6];
    for(int aux = 0 ; aux < 6 ; aux++) {
        vetor[aux] = aux;
    }
    //for(int aux = 0 ; aux < 6 ; aux++) {
    //    printf("%d\n", vetor[aux]);
    //}
    //teste = inicializa_lista();
    //teste = insere_lista(teste, 22);
    //teste = insere_lista(teste, 23);
    //teste = insere_lista(teste, 77);
    //teste = insere_lista(teste, 11);
    //teste = insere_lista(teste, 40);
    teste = vetor_lista(vetor, 6);
    //printf("%d", maior);
    imprime_lista(teste);
    return 0;
}