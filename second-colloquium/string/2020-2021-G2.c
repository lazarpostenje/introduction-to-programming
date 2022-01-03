#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#define SIZE 100

int main() {

    ///hill forest woods lake forest hill

    char mojString[SIZE];

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    char kopijaStringa[SIZE];

    strcpy(kopijaStringa, mojString);


    char *token = strtok(mojString, " ");

    int min = INT_MAX;

    while(token != NULL){

        int brojac = 0;
        char *pok = kopijaStringa;

        while((pok = strstr(pok, token)) != NULL){

            brojac++;
            pok++;

        }

        if(brojac < min) min = brojac;


        token = strtok(NULL, " ");
    }

    strcpy(mojString, kopijaStringa);

    token = strtok(mojString, " ");

    char rezultat[SIZE] = "";

    while(token != NULL){

        int brojac = 0;
        char *pok = kopijaStringa;

        while((pok = strstr(pok, token)) != NULL){

            brojac++;
            pok++;

        }

        if(brojac != min) {

            strcat(rezultat, token);
            strcat(rezultat, " ");

        }


        token = strtok(NULL, " ");
    }


    rezultat[strlen(rezultat) - 1] = '\0';

    puts(rezultat);

    return 0;
}