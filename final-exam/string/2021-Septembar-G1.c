#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 500

/**

        2. (12p) Napisati program koji učitava string koji sadrži mala slova i pravilno
        zatvorene dvostruke navodnike. Program treba da na osnovu učitanog stringa
        napravi novi koji iz navodnika izbacuje sva slova koja se pojavljuju samo jednom
        između navodnika.
        Primer
        Unos: acdj"knaan"nhn"prcf"ak"dfffs"j
        Ispis: acdj"naan"nhn""ak"fff"j
**/


int main(){

    char mojString[SIZE];

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    char noviString[SIZE];

    int indexer = 0;

    int navodnici = 0;

    for(int i = 0; i < strlen(mojString); i++){

        if(mojString[i] == '"' && navodnici == 0){

            navodnici = 1;
            noviString[indexer++] = ' ';
            noviString[indexer++] = mojString[i];
            noviString[indexer] = '\0';


        }else if(mojString[i] == '"' && navodnici == 1) {

            navodnici = 0;
            noviString[indexer++] = mojString[i];
            noviString[indexer++] = ' ';
            noviString[indexer] = '\0';
        } else {

            noviString[indexer++] = mojString[i];
            noviString[indexer] = '\0';

        }

    }

    char *token = strtok(noviString, " ");

    char output[SIZE] = "";

    char pomocnik[SIZE];

    while(token != NULL){

        pomocnik[0] = '\0';

        int indexer = 0;

        if(token[0] == '"' && token[strlen(token) - 1] == '"'){

            for(int i = 0; i < strlen(token); i++){

                char *pok = token;
                int brojac = 0;

                while((pok = strchr(pok, token[i])) != NULL){

                    pok++;
                    brojac++;

                }

                if(brojac > 1) {

                    pomocnik[indexer++] = token[i];
                    pomocnik[indexer] = '\0';

                }

            }

        } else {

            for(int i = 0; i < strlen(token); i++){

                pomocnik[indexer++] = token[i];
                pomocnik[indexer] = '\0';

            }

        }

        strcat(output, pomocnik);

        token = strtok(NULL, " ");

    }

    puts(output);

    return 0;/// acdj"knaan"nhn"prcf"ak"dfffs"j

}
