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

    char magarac[SIZE] = "";

    char *token = strtok(mojString, "-");



    while(token != NULL){

         int j = 0;

        pomocnik[0] = '\0';

        int duzina = strlen(token) - 1;

        for(int i = 0; i <= duzina; i++){

            if(strchr(pomocnik, token[i]) != NULL){

                continue;

            } else {

                pomocnik[j] = token[i];
                j++;
            }

        }

        pomocnik[j] = '-';
        pomocnik[j + 1] = '\0';
        strcat(magarac, pomocnik);



        token = strtok(NULL, "-");
    }

    magarac[strlen(magarac) - 1] = '\0';

    puts(magarac);

    return 0;
}