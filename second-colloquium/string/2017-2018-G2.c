#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define SIZE 500


int main()
{
    char mojString[SIZE];
    fgets(mojString, SIZE, stdin);
    mojString[strlen(mojString)-1] = '\0';
    char *token = strtok(mojString, " ");
    char pomocnik[SIZE] = "", kecman[SIZE] = "";
    while (token != NULL) {

        if (strchr(pomocnik, *token) != NULL) {
            if (!(strchr(kecman, *token) != NULL)) {
                strcat(kecman, token);
                strcat(kecman, " ");
            }

        }
        else {
            strcat(pomocnik, token);
            strcat(pomocnik, " ");
        }

        token = strtok(NULL, " ");
    }
    kecman[strlen(kecman) - 1] = '\0';
    strcpy(mojString, kecman);
    printf("%s", kecman);
}

    magarac[strlen(magarac) - 1] = '\0';

    puts(magarac);

    return 0;
}