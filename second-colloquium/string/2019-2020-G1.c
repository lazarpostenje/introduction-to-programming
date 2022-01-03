#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define SIZE 500
void reverse(char *token){

    char reversovan[SIZE] = "";

    int duzina = strlen(token) - 1;

    int j = 0;

    for(int i = duzina; i >= 0; i--){

        reversovan[j++] = token[i];

    }

    reversovan[j] = '\0';

    strcpy(token, reversovan);

}


int palindrom(char *token){

    char kopija[SIZE] = "";

    strcpy(kopija, token); // kopija = normalan string

    reverse(token); // token = reversovan

    if(strcmp(token, kopija) == 0) return 1;

    return 0;

}

int main() {

    char mojString[SIZE];

    fgets(mojString, SIZE, stdin);

    mojString[strlen(mojString) - 1] = '\0';

    char *token = strtok(mojString, " ");

    char kopija[SIZE] = "";

    while(token != NULL){

        if(palindrom(token)){

            int duzina = strlen(token) - 1;

            for(int i = 0; i <= duzina; i++){

                token[i] -= 32;

            }

        }

        printf("%s ", token);

        token = strtok(NULL, " ");
    }

    return 0;
}