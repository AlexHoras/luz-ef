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
    * INICIA O GERADOR DE N�MEROS ALEATORIOS COM O VALOR DA FUN��O TIME(NULL)
    * ESTE VALOR � CALCULADO COMO SENDO O TOTAL DE SEGUNDOS PASSADOS DESDE
    * 1 DE JANEIRO 1970 ATE A DATA ATUAL.
    * DESTA FORMA A CADA EXECU��O O VALOR DA "SEMENTE" � SER� DIFERENTE.
    */

    srand(time(NULL));

    for(i = 0; i < TAM; i++) {
        numeros[i] = rand() % 100;
    }


    // Algoritimos de ordena��o InsertionSort
    for(i = 1; i < TAM; i++){

        aux = numeros[i];
        contador = i - 1;

        // S� entra nesta condi��o se o contador for iqual o menor que  ZERO
        // ou aux for menor que a casa do array no la�o FOR
        // EX do primeiro la�o :
        // aux = 10
        // contador = i - 1 = 1 - 1 = 0
        // contador � >= 0 e aux < numeros[0] -> faz a compara��o do segundo indice com o primeiro
        //
        // Apos isso ele compara todas de frente pra traz ate terminalas

        while((contador >= 0) && (aux < numeros[contador])){
            numeros[ contador + 1 ] = numeros[contador];
            contador--;
        }
        numeros[contador + 1] = aux;
    }

    printf("\n Elementos do array em ordem crescente: \n");

    for(i = 0; i < TAM; i++) {
        printf("%4d", numeros[i]);
    }

    printf("\n");

    return 0;
}
