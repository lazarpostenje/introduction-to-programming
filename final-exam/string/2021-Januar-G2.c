#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

/**

    2. (13p) Napisati program koji za dva data stringa P i S pronalazi najduži podstring
    stringa P za koji važi da počinje i završava se karakterom koji se nalazi u S i sva slova u
    podstringu koja se pojavljuju i u S poređana su u istom redosledu kao u S. Podstring
    može sadržati i slova koja se ne nalaze u S. Oba stringa se sastoje samo od malih slova,
    S ima sva različita slova.
    Primer
    Unos: P: fcghtdcbacvbbbffa S: dcba
    Ispis: cvbbbffa

**/

int proveri(char *substring, char *stringS){

    char prvoSlovo = substring[0];
    char poslednjeSlovo = substring[strlen(substring) - 1];

    char pomocnik[SIZE] = "";

    if(strchr(stringS, prvoSlovo) == NULL || strchr(stringS, poslednjeSlovo) == NULL) {

        return 0;

    }

    int indexer = 0;

    for(int i = 0; i < strlen(substring); i++){

        if(strchr(pomocnik, substring[i]) == NULL && strchr(stringS, substring[i]) != NULL){

            pomocnik[indexer++] = substring[i];
            pomocnik[indexer] = '\0';

        } else if(strchr(stringS, substring[i]) != NULL && pomocnik[indexer - 1] != substring[i]){

            return 0;

        }

    }

    if(strstr(stringS, pomocnik) != NULL) {

        return 1;

    }

    return 0;

}

int main(){

    char stringP[SIZE];
    char stringS[SIZE];

    fgets(stringP, SIZE, stdin);
    fgets(stringS, SIZE, stdin);

    stringP[strlen(stringP) - 1] = '\0';
    stringS[strlen(stringS) - 1] = '\0';

    int max = 0;

    char pomocnik[SIZE] = "";

    for(int i = 0; i < strlen(stringP); i++){

        for(int j = 0; j < strlen(stringP) - i; j++){

            char substring[SIZE];

            substring[0] = '\0';

            int indexer = 0;

            for(int k = j; k < j + 1 + i; k++){

                substring[indexer++] = stringP[k];
                substring[indexer] = '\0';

            }

            int duzina = strlen(substring);

            if(proveri(substring, stringS)){

                pomocnik[0] = '\0';

                strcat(pomocnik, substring);

            }

        }

    }

    puts(pomocnik);

    return 0;

}
