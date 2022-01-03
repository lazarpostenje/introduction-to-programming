#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define SIZE 1000

void izmeni(char *str) {
    int n = strlen(str) - 1;
    str[n] = '\0';
    char pomocni_niz[SIZE] = "";
    char *token = strtok(str, " ");
    while (token != NULL) {
        if (strchr(pomocni_niz, *token) == NULL) {
            strcat(pomocni_niz, token);
            strcat(pomocni_niz, " ");
        }
        token = strtok(NULL, " ");
    }
    pomocni_niz[strlen(pomocni_niz)-1] = '\0';
    puts(pomocni_niz);
}

int main()
{
    char str[SIZE];
    fgets(str, SIZE, stdin);
    izmeni(str);
    return 0;
}