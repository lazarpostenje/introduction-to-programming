#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define SIZE 500

int main() {

    //234-567-908-171-456-432

    char mojString[SIZE];

    char kecmanovString[SIZE] = "";

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    strcpy(kecmanovString, mojString);

    char *token = strtok(mojString, "-");

    int mapa[SIZE];

    int max = 0;

    int pomocniNiz[SIZE];

    int i = 0;

    while(token != NULL){

        int duzina = strlen(token);

        int zbir = 0;

        for(int i = 0; i < duzina; i++){

            zbir += token[i] - '0';

        }

        pomocniNiz[i] = zbir;

        if(zbir > max) max = zbir;

        token = strtok(NULL, "-");
        i++;
    }

    for(int j = 0; j < max + 1; j++)
        mapa[j] = 0;


    for(int j = 0; j < i; j++)
        mapa[pomocniNiz[j]]++;


    int max2 = 0;
    for(int j = 0; j < max + 1; j++){

        if(mapa[j] > max2) max2 = j;

    }

    token = strtok(kecmanovString, "-");

    printf("Zbir %d, ", max2);

    while(token != NULL){

        int duzina = strlen(token);

        int zbir = 0;

        for(int i = 0; i < duzina; i++){

            zbir += token[i] - '0';

        }

        if(zbir == max2) printf("%s ", token);

        token = strtok(NULL, "-");

    }


    return 0;
}