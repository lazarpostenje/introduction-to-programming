#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

/**

        Napisati program koji učitava string sastavljen od reči koji sadrže mala slova
        abecede, a neke reči imaju i veliko X, koje ne može biti na kraju reči. Program treba da
        od unetog stringa napravi novi string u kom će se reči koje sadrže X promeniti tako što se
        ukrste stringovi pre i posle X. Ukrštanje se radi tako što se između svaka dva slova levo
        od X umetne jedno slovo iz podstringa desno od X, slova se umeću redom, kada se
        potroše sva slova iz desnog podstringa, kreće se od početka. Reči koje ne sadrže X
        prenose se u rezultujući string bez izmena.
        Primer:
        Unos: abcdeXhz zhj bbbbXac cccXs
        Ispis: ahbzchdze zhj babcbab cscsc

**/


int main()
{

    char mojString[SIZE];

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    char noviString[SIZE] = "";

    char *token = strtok(mojString, " ");

    while(token != NULL){

        char levo[SIZE];
        char desno[SIZE];

        levo[0] = '\0';
        desno[0] = '\0';

        int i = 0;
        int indexer = 0;

        int flagX = 0;

        while(token[i] != 'X'){

            levo[indexer++] = token[i];
            levo[indexer] = '\0';

            i++;
        }

        if(strlen(token) == strlen(levo)) flagX = 0;
        else flagX = 1;

        //printf("\t%d\t", flagX);

        indexer = 0;


            for(int j = i + 1; j < strlen(token); j++){

                desno[indexer++] = token[j];
                desno[indexer] = '\0';

            }




        ///   Unos: abcdeXhz zhj bbbbXac cccXs
        ///   Ispis: ahbzchdze zhj babcbab cscsc

        int l = 0;

        if(flagX){

            for(int k = 0; k < strlen(levo); k++){

                if(l > strlen(desno) - 1) l = 0;

                if(k == strlen(levo) - 1) {

                    char ch[2];
                    ch[0] = levo[k];
                    ch[1] = '\0';
                    strcat(noviString, ch);


                }
                else {

                    char ch[2];
                    char ch2[2];
                    ch[0] = levo[k];
                    ch[1] = '\0';
                    ch2[0] = desno[l++];
                    ch2[1] = '\0';
                    strcat(noviString, ch);
                    strcat(noviString, ch2);

                }

            }

        } else strcat(noviString, token); //printf("%s", token);

        strcat(noviString, " ");


        token = strtok(NULL, " ");

    }

    puts(noviString);

    return 0;
}