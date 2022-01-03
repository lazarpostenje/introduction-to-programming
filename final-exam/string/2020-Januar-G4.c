#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

/**

        Napisati program koji učitava string sastavljen od reči koje sadrže niz različitih
        malih slova abecede u tri vrste zagrada, (),{} i []. Program treba da napravi novi string
        na osnovu unetog u kom će slova u istim zagradama biti grupisana u jednu reč, pri čemu
        reč ne sme da sadrži ista slova. Redosled reči u rezultujućem stringu, kao i redosled
        slova u rečima unutar zagrada nisu bitni.
        Primer
        Unos: [adf] {dfg} {fgh} {nm} (jkl) [df]
        Ispis: [adf] {dfghnm} (jkl)

**/


int main()
{

    char mojString[SIZE];

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    char kopija[SIZE];

    strcpy(kopija, mojString);


    char kljucevi[3] = {'[', '{', '('};

    char kljucevi2[3] = {']', '}', ')'};

    char noviString[SIZE] = "";


    for(int i = 0; i < 3; i++){

        strcpy(mojString, kopija);

        char slova[SIZE];

        slova[0] = '\0';

        int indexer = 0;

        char *token = strtok(mojString, " ");


        ///Unos: [adf] {bmno} {mm} {nm} (jkl) [dv]
        ///Ispis: [addfv] {bmmmmnno} (jkl)

        while(token != NULL){

            if(kljucevi[i] == token[0]){

                for(int j = 1; j < strlen(token) - 1; j++){

                    if(strchr(slova, token[j]) == NULL){

                        slova[indexer++] = token[j];
                        slova[indexer] = '\0';

                    }

                }

            }

            token = strtok(NULL, " ");

        }

        char ch[2];
        ch[0] = kljucevi[i];
        ch[1] = '\0';

        char ch2[2];
        ch2[0] = kljucevi2[i];
        ch2[1] = '\0';

        strcat(noviString, ch);
        strcat(noviString, slova);
        strcat(noviString, ch2);
        strcat(noviString, " ");


    }

    puts(noviString);



    return 0;
}