#include <stdio.h>
#include <stdlib.h>
#define TAM 10000000

void mergesort(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);

int main (void) {

    int *v, i;

    // RESERVA MEMORIAS LIMPAS PARA QUANTIDADE DE DADOS ESPECIFICADOS ESTATICAMENTE
    v = calloc(TAM, sizeof(int));

    /*
    * INICIA O GERADOR DE NÚMEROS ALEATORIOS COM O VALOR DA FUNÇÃO TIME(NULL)
    * ESTE VALOR É CALCULADO COMO SENDO O TOTAL DE SEGUNDOS PASSADOS DESDE
    * 1 DE JANEIRO 1970 ATE A DATA ATUAL.
    * DESTA FORMA A CADA EXECUÇÃO O VALOR DA "SEMENTE" É SERÁ DIFERENTE.
    */

    srand(time(NULL));

    for(i = 0; i < TAM; i++) {
        v[i] = rand() % 100;
    }

    mergesort(v, TAM);


    printf("\n");

    return 0;
}

/*
  Dado um vetor de inteiros v e um inteiro n >= 0, ordena o vetor v[0..n-1] em ordem crescente.
*/
void mergesort(int *v, int n) {
  int *vetorAux = malloc(sizeof(int) * n);
  sort(v, vetorAux, 0, n - 1);
  free(vetorAux);
}

/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor vetorAux é utilizado internamente durante a ordenação.
*/
void sort(int *v, int *vetorAux, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, vetorAux, i, m); // Primeiro pedaço
  sort(v, vetorAux, m + 1, f); // Segundo Pedaço

  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
  if (v[m] <= v[m + 1]) return;

  merge(v, vetorAux, i, m, f);
}


/*
  Dado um vetor v e três inteiros inicio, meio e fim, sendo v[inico..meio] e v[meio+1..fim] vetores ordenados,
  coloca os elementos destes vetores, em ordem crescente, no vetor em v[inicio..fim].
*/
void merge(int *v, int *vetorAux, int inicio, int meio, int fim) {
  int i,
      iv = inicio, ic = meio + 1;

  for (i = inicio; i <= fim; i++) vetorAux[i] = v[i];

  i = inicio;

  while (iv <= meio && ic <= fim) {
    if (vetorAux[iv] <= vetorAux[ic]) vetorAux[i++] = vetorAux[iv++];
    else v[i++] = vetorAux[ic++];
  }

  while (iv <= meio) v[i++] = vetorAux[iv++];

  while (ic <= fim) v[i++] = vetorAux[ic++];
}
