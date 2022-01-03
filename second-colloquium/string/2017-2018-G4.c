#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define SIZE 100

 /**
abba-afgf-ccc-fgh
ab-f-c
**/

int main() {

    char str[SIZE];
    fgets(str, SIZE, stdin);
    str[strlen(str) - 1] = '\0';
    char pomocnik[SIZE] = "", otpad[SIZE] = "", prenosnik[SIZE] = "";
    char *token = strtok(str, "-");
    int n, j, k, brojac = 0, prethodniBrojac = 0;
    while (token != NULL) {
        pomocnik[0] = '\0';
        otpad[0] = '\0';
        n = strlen(token);
        j = 0, k = 0;
        for (int i = 0; i < n; i++) {
            puts(otpad);
            if (strchr(otpad, token[i]) != NULL) {
                if (strchr(pomocnik, token[i]) == NULL) {
                    pomocnik[k] = token[i];
                    k++;
                }
            }
            else {
                otpad[j] = token[i];
                j++;
                otpad[j] = '\0';
            }

        }
        puts(otpad);
        pomocnik[k] = '\0';
        strcat(prenosnik, pomocnik);
        if (k != 0) strcat(prenosnik, "-");
        token = strtok(NULL, "-");
    }
    prenosnik[strlen(prenosnik)-1] = '\0';
    strcpy(str, prenosnik);
    printf("\n");
    puts(str);
    return 0;
}