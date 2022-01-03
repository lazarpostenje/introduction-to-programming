#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define SIZE 500


int main() {

    char mojString[SIZE];

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    char pomocnik[SIZE] = "";

    char *token = strtok(mojString, " ");

    while(token != NULL){

        int duljina = strlen(token) - 1;

        if( !((token[0] >= 'a' && token[0] <= 'z') && (token[duljina] >= 'a' && token[duljina] <= 'z')) ) {

            strcat(pomocnik, token);
            strcat(pomocnik, " ");

        }

        token = strtok(NULL, " ");

    }

    pomocnik[strlen(pomocnik) - 1] = '\0';

    strcpy(mojString, pomocnik);

    puts(mojString);


    return 0;
}