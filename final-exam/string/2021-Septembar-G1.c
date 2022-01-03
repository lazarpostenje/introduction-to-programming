#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/**
acdj"knaan"nhn"prcf"ak"dfffs"j
Unos: acdj "knaan" nhn "prcf" ak "dfffs" j
Ispis: acdj"naan"nhn""ak"fff"j
**/

#define SIZE 500

int main () {

    char string[SIZE];
    fgets(string, SIZE, stdin);
    string[strlen(string)-1] = '\0';
    int duzina = strlen(string);
    char pomocnik[SIZE];
    int k = 0, flag = 0;

    for(int i = 0; i < duzina; i++){
            if (string[i] == '"') {
                if (flag == 0) {
                pomocnik[k++] = ' ';
                pomocnik[k++] = '"';
                flag = 1;
                }
                else {
                    pomocnik[k++] = '"';
                    pomocnik[k++] = ' ';
                    flag = 0;
                }
            }
            else pomocnik[k++] = string[i];
    }
    pomocnik[k] = '\0';

    char prenosnik[SIZE] = "", kontejner[SIZE] = "";
    char* token = strtok(pomocnik, " ");
    int brojac = 0, c = 0;

    while (token != NULL) {

        if (token[0] == '"' && token[strlen(token)-1] == '"') {

            for (int i = 0; i < strlen(token); i++) {
                brojac = 0;
                for (int j = 0; j < strlen(token); j++)
                        if (token[i] == token[j]) brojac++;

                if (brojac > 1) {
                    kontejner[c++] = token[i];
                    kontejner[c] = '\0';
                }
                }
            }

        else {
            strcat(prenosnik, token);
        }
        strcat(prenosnik, kontejner);
        kontejner[0] = '\0';
        c = 0;
        token = strtok(NULL, " ");
    }
    strcpy(string, prenosnik);
    puts(string);
    return 0;
}