#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

/**

    2. (13p) Napisati program koji od dva data stringa P i S koji sadrže različita mala slova
    pravi treći tako što slova u P koja se pojavljuju i u S ređa u istom redosledu u kom se ista
    slova pojavljuju u S, pri tom ne menjajući mesta slovima iz P koji se ne pojavljuju u S.
    Primer
    Unos: P: aefughckl S: cdea
    Ispis: cefughakl

**/



int main(){

    char stringP[SIZE];
    char stringS[SIZE];

    fgets(stringP, SIZE, stdin);
    fgets(stringS, SIZE, stdin);

    stringP[strlen(stringP) - 1] = '\0';
    stringS[strlen(stringS) - 1] = '\0';

    int k = 0;

    char pomocniString[SIZE];

    int indexer = 0;

    for(int i = 0; i < strlen(stringS); i++){

        if(strchr(stringP, stringS[i]) != NULL){

            pomocniString[indexer++] = stringS[i];
            pomocniString[indexer] = '\0';

        }

    }

    strcpy(stringS, pomocniString);

    for(int i = 0; i < strlen(stringP); i++){

        if(strchr(stringS, stringP[i]) != NULL){

            for(int j = k; j < strlen(stringS); j++){

                    stringP[i] = stringS[j];
                    k++;
                    break;

            }

        }

    }

    puts(stringP);


    return 0;

}
