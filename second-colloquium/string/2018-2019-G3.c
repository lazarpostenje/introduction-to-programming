#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define SIZE 500

int main() {

    char mojString[SIZE];

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    char pomocniString[SIZE] = "";
    char pomocnoSlovo[SIZE] = "";

    char *token = strtok(mojString, " ");

    while(token != NULL){

        int duzinaTokena = strlen(token);

        if(token[0] == '"' && token[duzinaTokena - 1] == '"'){

            for(int i = 1; i < duzinaTokena - 1; i++){

                if(token[i] == 'a' || token[i] == 'e' || token[i] == 'i' || token[i] == 'o' || token[i] == 'u' ||
                   token[i] == 'A' || token[i] == 'E' || token[i] == 'I' || token[i] == 'O' || token[i] == 'U'){

                    pomocnoSlovo[0] = token[i];
                    strcat(pomocniString, pomocnoSlovo);

                }
            }

            strcat(pomocniString, " ");

        }else {
            strcat(pomocniString, token);
            strcat(pomocniString, " ");

        }

        token = strtok(NULL, " ");
    }

    printf("%s", pomocniString);

    return 0;
}