#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 500


void nadji_krajnje_sekvence(char *string){

    char *token = strtok(string, " ");

    char noviString[SIZE] = "";

    while(token != NULL){

        for(int i = 0; i < strlen(token); i++){

            char substring[SIZE];
            substring[0] = '\0';
            int indexer = 0;

            for(int j = i; j < strlen(token); j++){

                substring[indexer++] = token[j];
                substring[indexer] = '\0';

            }
            strcat(noviString, substring);
            strcat(noviString, " ");
            strcat(noviString, "|");
        }
        token = strtok(NULL, " ");
    }
    strcpy(string, noviString);
}

int main(){

    char mojString[SIZE];

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    char kopija[SIZE];

    strcpy(kopija, mojString);

    mojString[strlen(mojString)] = ' ';
    mojString[strlen(mojString) + 1] = '\0'; //dodavanje razmaka na kraj

    nadji_krajnje_sekvence(kopija);

    char *token = strtok(kopija, "|");

    int max = 0;

    char zapamti[SIZE];

    while(token != NULL){

        char *pok = mojString;
        int brojac = 0;

        while((pok = strstr(pok, token)) != NULL){

            brojac++;
            pok++;
        }

        int duzina = 0;

        if(brojac > 1) {

            duzina = strlen(token) - 1;
            if(duzina > max){

                max = duzina;
                strcpy(zapamti, token);

            }
        }
        token = strtok(NULL, "|");

    }

    int indexer = 0;
    char noviString[SIZE];

    for(int i = 0; i < strlen(mojString); i++){

        if(mojString[i] == ' '){

            noviString[indexer++] = ' ';
            noviString[indexer++] = '|';
            noviString[indexer] = '\0';

        } else{

            noviString[indexer++] = mojString[i];
            noviString[indexer] = '\0';

        }
    }

    char *token2 = strtok(noviString, "|");

    while(token2 != NULL){

        if(strstr(token2, zapamti) != NULL) printf("%s", token2);

        token2 = strtok(NULL, "|");
    }

    return 0;

}
