#include <stdio.h>
#include <stdlib.h>
#define TAM 10000000

void quick_sort(int *a, int inicio, int fim);

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

    quickSort(v, 0, TAM - 1);

    return 0;
}

// Função de Ordenação por Seleção
void quickSort(int *a, int inicio, int fim) {
    int i, j, x, y;

    i = inicio;
    j = fim;
    x = a[(inicio + fim) / 2];

    while(i <= j) {
        while(a[i] < x && i < fim) {
            i++;
        }
        while(a[j] > x && j > inicio) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > inicio) {
        quickSort(a, inicio, j);
    }
    if(i < fim) {
        quickSort(a, i, fim);
    }
}
