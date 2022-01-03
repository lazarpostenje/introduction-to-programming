#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

/**

        Napisati program koji učitava string sastavljen od reči koji imaju oblik
        ključ:vrednost, gde je ključ jedan karakter, a vrednost niz različitih karaktera (koriste se
        samo mala slova abecede). Program treba da napravi novi string na osnovu unetog u
        kom će se grupisati reči sa istim ključem tako što svaki ključ dobija kao vrednost sve
        različite karaktere iz reči sa tim ključem u ulaznom stringu. Redosled reči u rezultujućem
        stringu, kao i redosled slova iza dvotačke nisu bitni.
        Primer
        Unos: a:dfg b:drt a:ght g:ase g:zua
        Ispis: a:dfght b:drt g:asezu

**/

int main()
{

    char mojString[SIZE];

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    char kljucevi[SIZE];

    char kopija[SIZE];

    strcpy(kopija, mojString);

    char *token = strtok(mojString, " ");

    int indexer = 0;

    char noviString[SIZE] = "";

    while(token != NULL){

        if(strchr(kljucevi, token[0]) == NULL){

            kljucevi[indexer++] = token[0];

        }

        token = strtok(NULL, " ");

    }

    /// Unos: a:dfg b:drt a:ght g:ase g:zua
    /// Ispis: a:dfght b:drt g:asezu


    for(int i = 0; i < indexer; i++){

        char vrednost[SIZE];

        int k = 0;

        vrednost[0] = '\0';

        strcpy(mojString, kopija);

        char *token2 = strtok(mojString, " ");

        while(token2 != NULL){

            if(token2[0] == kljucevi[i]){

                for(int j = 2; j < strlen(token2); j++){

                    if(strchr(vrednost, token2[j]) == NULL) {

                        vrednost[k++] = token2[j];
                        vrednost[k] = '\0';

                    }

                }

            }

            token2 = strtok(NULL, " ");

        }

        char ch[2];

        ch[0] = kljucevi[i];
        ch[1] = '\0';

        strcat(noviString, ch);
        strcat(noviString, ":");
        strcat(noviString, vrednost);
        strcat(noviString, " ");

        //printf("%c:%s ", kljucevi[i], vrednost);

    }

    puts(noviString);

    return 0;
}