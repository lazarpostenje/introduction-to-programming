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

    char drugiString[SIZE] = "";

    char treciString[SIZE] = "";

    while(token != NULL){

        int duzina = strlen(token) - 1;

        char poslednji = token[duzina];

        drugiString[0] = poslednji;
        drugiString[1] = '\0';

        token[duzina] = '\0';

        strcat(drugiString, token);

        strcat(treciString, drugiString);
        strcat(treciString, "-");

        token = strtok(NULL, "-");

    }

    treciString[strlen(treciString) - 1] = '\0';

    strcpy(mojString, treciString);

    printf("%s", mojString);


    return 0;
}