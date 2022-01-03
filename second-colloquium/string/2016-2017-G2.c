#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define SIZE 500


int main() {

    int n;

    scanf("%d ", &n);

    char mojString[SIZE];

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    char pomocnik[SIZE] = "";

    char *token = strtok(mojString, " ");

    while(token != NULL){

        int duljina = strlen(token) - 1;

        if(duljina > n) {

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