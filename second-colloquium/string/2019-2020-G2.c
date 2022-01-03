#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define SIZE 500

void reverse(char *string){

    int duzina = strlen(string) - 1;

    char reversovan[SIZE] = "";

    int j = 0;

    for(int i = duzina; i >= 0; i--){

        reversovan[j++] = string[i];

    }

    strcpy(string, reversovan);

}


int main() {

    char mojString[SIZE];

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    char bezRazmaka[SIZE] = "";

    char *token = strtok(mojString, " ");

    while(token != NULL){

        strcat(bezRazmaka, token);

        token = strtok(NULL, " ");

    }

    //imamo bezRazmaka

    char normalan[SIZE] = "";
    char reversovan[SIZE] = "";
    strcpy(normalan, bezRazmaka);
    reverse(bezRazmaka);
    strcpy(reversovan, bezRazmaka);

    int duzina = strlen(normalan) - 1;

    for(int i = 0; i < duzina; i++){

        if(normalan[i] == reversovan[i]) continue;
        else if(normalan[i] == 'l' && normalan[i + 1] == 'j'){

            reversovan[i] = 'l';
            reversovan[i + 1] = 'j';

        } else if(normalan[i] == 'n' && normalan[i + 1] == 'j'){

            reversovan[i] = 'n';
            reversovan[i + 1] = 'j';

        }

    }

    if(strcmp(normalan, reversovan) == 0) printf("Jeste palindrom");
    else printf("Nije palindrom");

    return 0;
}