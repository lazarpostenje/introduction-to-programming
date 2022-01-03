#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

/**

        Napisati program koji učitava string sastavljen od reči koje sadrže sekvencu
        malih slova abecede poređanih alfabetski u tri vrste zagrada, (),{} i []. Program treba da
        napravi novi string na osnovu unetog u kom će slova u istim zagradama biti grupisana u
        jednu reč, pri čemu se mora očuvati alfabetski poredak. Redosled reči u rezultujućem
        stringu nije bitan.
        Primer
        Unos: [adf] {bmno} {mm} {nm} (jkl) [dv]
        Ispis: [addfv] {bmmmno} (jkl)

**/

void sortiraj(char *string){

    for(int i = 0; i < strlen(string) - 1; i++){

        for(int j = 0; j < strlen(string) - i - 1; j++){

            if(string[j] > string[j + 1]){

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

                    slova[indexer++] = token[j];
                    slova[indexer] = '\0';

                }

            }

            token = strtok(NULL, " ");

        }

        sortiraj(slova);

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