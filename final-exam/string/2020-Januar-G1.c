#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

/**

        Napisati program koji učitava string sastavljen od reči koji imaju oblik
        ključ:vrednost, gde je ključ jedna cifra, a vrednost niz malih slova sortiranih alfabetski
        (redom po ASCII tabeli). Program treba da napravi novi string na osnovu unetog u kom će
        se grupisati karakteri sa istim ključem tako što svaki ključ dobija kao vrednost sve
        karaktere iz reči sa tim ključem u ulaznom stringu pri tom se mora očuvati alfabetski
        poredak slova. Redosled reči u rezultujućem stringu nije bitan.
        Primer

        Unos: 2:adfh 1:ijjk 4:op 2:fghi 1:jk
        Ispis: 2:adffghhi 1:ijjjkk 4:op

**/

void sortiraj(char *string){

    for(int i = 0; i < strlen(string) - 1; i++){

        for(int j = 0; j < strlen(string) - i - 1; j++){

            if(string[j] > string[j+1]){

                char temp = string[j];
                string[j] = string[j + 1];
                string[j + 1] = temp;

            }

        }

    }

}

int main()
{

    char mojString[SIZE];

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    char kopija[SIZE];

    strcpy(kopija, mojString);

    char *token = strtok(mojString, " ");

    char kljucevi[SIZE];

    int i = 0;

    while(token != NULL){

        if(strchr(kljucevi, token[0]) == NULL){

            kljucevi[i] = token[0];
            i++;

        }

        token = strtok(NULL, " ");
    }

    char slova[SIZE] = "";

    char pomocni[SIZE] = "";

    for(int j = 0; j < i; j++){

        strcpy(mojString, kopija);

        int indexer = 0;

//        if(j != 0) {
//
//            //slova[indexer] = ' ';
//            //slova[indexer + 1] = '\0';
//
//        }

        char *token2 = strtok(mojString, " ");

        while(token2 != NULL){

            if(token2[0] == kljucevi[j]){

                for(int k = 2; k < strlen(token2); k++){

                    slova[indexer] = token2[k];
                    indexer++;
                    slova[indexer] = '\0';

                }

            }/// 2:adfh 1:ijjk 4:op 2:fghi 1:jk

            token2 = strtok(NULL, " ");

        }

        char ch[2];
        ch[0] = kljucevi[j];
        ch[1] = '\0';

        strcat(pomocni, ch);
        strcat(pomocni, ":");
        strcat(pomocni, slova);
        strcat(pomocni, " ");

    }

    //puts(pomocni);

    char *token3 = strtok(pomocni, " ");

    char output[SIZE] = "";

    while(token3 != NULL){

        sortiraj(token3);

        strcat(output, token3);

        strcat(output, " ");

        token3 = strtok(NULL, " ");

    }

    puts(output);



    return 0;
}