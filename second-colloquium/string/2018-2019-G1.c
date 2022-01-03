#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define SIZE 100

 /**
Korisnik unosi rečenicu. Ispisati najučestaliju reč (reč koja se pojavila najvedi broj puta) i njenu
učestalost. Ukoliko postoji više reči koje imaju najvedu učestalost ispisati prvu koja se pojavila u rečenici.
primer:

prvi drugi prvi drugi treci prvi
izlaz: prvi 3
**/




int main()
{
    char string[SIZE];
    fgets(string, SIZE, stdin);

    string[strlen(string) - 1] = '\0';
    char pomocnik[SIZE][SIZE], kopija[SIZE], element[SIZE] = "";
    strcpy(kopija, string);
    char *token = strtok(string, " ");
    int k = 0;
    while (token != NULL) {
        strcpy(pomocnik[k++], token);
        token = strtok(NULL, " ");
    }
    int brojac = 0, max = 0;
    token = strtok(kopija, " ");
    while (token != NULL) {

        for (int i = 0; i <= k; i++) {
            if (strcmp(pomocnik[i], token) == 0) brojac++;
            else {
                if (brojac > max) {
                    max = brojac;
                    element[0] = '\0';
                    strcat(element, token);
                }
            }
        }
        brojac = 0;
        token = strtok(NULL, " ");
    }
    printf("%s %d", element, max);
    return 0;
}