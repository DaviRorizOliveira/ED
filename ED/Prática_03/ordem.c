// Larissa de Brito 202210349
// Estêvão Sousa 202210345
// Davi Roriz 202210342
#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializa_lista(void) {
    return NULL;
}

Lista* inserir_ordenado(Lista* alfa, int num) {
  Lista *aux, *novo = (Lista*)malloc(sizeof(Lista));
  int cont = 0;
  if(novo) {
      novo->info = num;
      if(alfa == NULL) {
        novo->prox = NULL;
        alfa = novo;
        printf("0");
      }
      else if(novo->info < alfa->info) {
        novo->prox = alfa;
        alfa = novo;
        printf(" 0");
      }
      else {
        cont = 1;
        aux = alfa;
        while(aux->prox && novo->info > aux->prox->info) {
          aux = aux->prox;
          cont++;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
        printf(" %d", cont);
      }
  }
  else printf("Erro ao alocar memoria\n");
  return alfa;
}

int main(void) {
  Lista* teste;
  int TAM, num;
  while(scanf("%d", &TAM) == 1) {
    teste = inicializa_lista();
    for(int aux = 0 ; aux < TAM ; aux++) {
        scanf("%d%*c", &num);
        teste = inserir_ordenado(teste, num);
    }
    printf("\n");
  }
  return 0;
}