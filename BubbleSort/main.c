#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#define TAM 10000000

int main()
{
    setlocale(LC_ALL, "");

    int *numeros, i, aux, contador;

    // RESERVA MEMORIAS LIMPAS PARA AQ QUANTIDADE DE DADOS ESPECIFICADOS ESTACICAMENTE
    numeros = calloc(TAM, sizeof(int));

    /*
    * INICIA O GERADOR DE NÚMEROS ALEATORIOS COM O VALOR DA FUNÇÃO TIME(NULL)
    * ESTE VALOR É CALCULADO COMO SENDO O TOTAL DE SEGUNDOS PASSADOS DESDE
    * 1 DE JANEIRO 1970 ATE A DATA ATUAL.
    * DESTA FORMA A CADA EXECUÇÃO O VALOR DA "SEMENTE" É SERÁ DIFERENTE.
    */

    srand(time(NULL));

    for(i = 0; i < TAM; i++) {
        numeros[i] = rand() % 100;
    }

    printf("Ordem atual dos itens no array: \n");

    for(i = 0; i < TAM; i++) {
        printf("%4d", numeros[i]);
    }

    // Algoritimos de ordenação BubbleSort
    for(contador = 1; contador < TAM; contador++){
        for(i = 0; i < TAM - 1; i++) {
            if(numeros[i] > numeros[i + 1]){
                aux = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = aux;
            }
        }
    }

    printf("\nElementos do array em ordem crescente: \n");

    for(i = 0; i < TAM; i++) {
        printf("%4d", numeros[i]);
    }

    printf("\n");

    return 0;
}
