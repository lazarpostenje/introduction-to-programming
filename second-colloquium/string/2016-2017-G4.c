#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define SIZE 500


int main() {

    char mojString[SIZE];

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    char *token = strtok(mojString, "-");

    char prviKarakter[SIZE] = "";

    char kecman[SIZE] = "";

    while(token != NULL){

        prviKarakter[0] = token[0];

        token++;

        strcat(kecman, token);

        kecman[strlen(kecman)] = prviKarakter[0];

        strcat(kecman, "-");

        token = strtok(NULL, "-");
    }

    kecman[strlen(kecman) - 1] = '\0';

    strcpy(mojString, kecman);

    printf("%s", mojString);

    return 0;
}