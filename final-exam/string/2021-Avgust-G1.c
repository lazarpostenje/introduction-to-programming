#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 500

/**

        2. (12p) Napisati program koji učitava string koji sadrži mala slova i pravilno
        otvorene i zatvorene zagrade. Program treba da na osnovu učitanog stringa
        napravi novi koji ima izbačena višestruka pojavljivanja slova u zagradama, ako
        se neko slovo u zagradi pojavljuje više puta ostaviti samo prvo pojavljivanje, a
        ostala izbaciti.
        Primer
        Unos: acdj(knaan)nhn(prcf)ak(sdfffs)j
        Ispis: acdj(kna)nhn(prcf)ak(sdf)j

**/


int main(){

    char mojString[SIZE];

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    char noviString[SIZE];

    int indexer = 0;

    for(int i = 0; i < strlen(mojString); i++){

        if(mojString[i] == '('){

            noviString[indexer++] = ' ';
            noviString[indexer++] = mojString[i];
            noviString[indexer] = '\0';

        }else if(mojString[i] == ')'){

            noviString[indexer++] = mojString[i];
            noviString[indexer++] = ' ';
            noviString[indexer] = '\0';

        }else {

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

        if(token[0] == '(' && token[strlen(token) - 1] == ')'){

            for(int i = 0; i < strlen(token); i++){

                if(strchr(pomocnik, token[i]) == NULL){

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

    return 0;

}
