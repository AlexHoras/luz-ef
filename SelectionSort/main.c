#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#define TAM 10000000

int main()
{
    setlocale(LC_ALL, "");

    int *numeros, i, menor, troca, contador;

    // RESERVA MEMORIAS LIMPAS PARA QUANTIDADE DE DADOS ESPECIFICADOS ESTATICAMENTE
    numeros = calloc(TAM, sizeof(int));

    /*
    * INICIA O GERADOR DE N�MEROS ALEATORIOS COM O VALOR DA FUN��O TIME(NULL)
    * ESTE VALOR � CALCULADO COMO SENDO O TOTAL DE SEGUNDOS PASSADOS DESDE
    * 1 DE JANEIRO 1970 ATE A DATA ATUAL.
    * DESTA FORMA A CADA EXECU��O O VALOR DA "SEMENTE" � SER� DIFERENTE.
    */

    srand(time(NULL));

    for(i = 0; i < TAM; i++) {
        numeros[i] = rand() % 100;
    }

    printf("Ordem atual dos itens no array: \n");

    for(i = 0; i < TAM; i++) {
        printf("%4d", numeros[i]);
    }

    // Algoritimos de ordena��o SelectionSort

    for(i = 0; i < TAM - 1; i++) {

        menor = i;

        for(contador = i + 1; contador < TAM; contador++){
            if(numeros[contador] < numeros[menor]){
                menor = contador;
            }
        }

        if(i != menor){
           troca = numeros[i];
           numeros[i] = numeros[menor];
           numeros[menor] = troca;
        }
    }


    printf("\n Elementos do array em ordem crescente: \n");

    for(i = 0; i < TAM; i++) {
        printf("%4d", numeros[i]);
    }

    printf("\n");

    return 0;
}
