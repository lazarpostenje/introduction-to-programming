#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define SIZE 100

void meni(){

    printf("\n\n1 - Ucitavanje podataka\n");
    printf("2 - Broj ocena na predmetu (iterativno)\n");
    printf("3 - Broj ocena na predmetu (rekurzivno)\n");
    printf("4 - Dodavanje ocene za predmet\n");
    printf("5 - Izlaz i brisanje struktura\n");

}

typedef struct ucenik{

    int redni_broj;
    char predmet[4];
    int ocene[5];
    struct ucenik *sledeci;

}UCENIK;

UCENIK *napravi(int redni_broj, char *predmet, int *ocene){

    UCENIK *novi = (UCENIK*) malloc(sizeof(UCENIK));

    novi->redni_broj = redni_broj;
    strcpy(novi->predmet, predmet);

    for(int i = 0; i < 5; i++){

        novi->ocene[i] = ocene[i];

    }
    novi->sledeci = NULL;

    return novi;

}

int uporedi(char *str1, char *str2){

    return strcmp(str1, str2);

}

UCENIK *dodaj(UCENIK *glava, int redni_broj, char *predmet, int *ocene){

    UCENIK *novi = napravi(redni_broj, predmet, ocene);

    if(glava == NULL){

        glava = novi;
        return glava;

    }

    UCENIK *privremeni = glava;



    if(redni_broj < privremeni->redni_broj || redni_broj == privremeni->redni_broj && uporedi(predmet, privremeni->predmet) < 0){

        novi->sledeci = privremeni;
        glava = novi;
        return glava;

    }

    while(privremeni->sledeci && ((redni_broj > privremeni->sledeci->redni_broj) ||
    (privremeni->sledeci->redni_broj == redni_broj && uporedi(predmet, privremeni->sledeci->predmet) > 0 ) ) ){

        privremeni = privremeni->sledeci;

    }

    novi->sledeci = privremeni->sledeci;
    privremeni->sledeci = novi;
    return glava;

}

void printuj(UCENIK *glava){

    if(glava == NULL){printf("\n"); return;}
    printf("%d %s ", glava->redni_broj, glava->predmet);
    for(int i = 0; i < 5; i++){

        if(glava->ocene[i] == 0) break;
        printf("%d ", glava->ocene[i]);

    }
    printf("\n");
    printuj(glava->sledeci);

}

UCENIK *ucitaj(UCENIK *glava, char *fajl){

    FILE *fp = fopen(fajl, "r");

    char linija[SIZE];

    while(fgets(linija, sizeof(linija), fp)){

        int brojac = 0;
        linija[strlen(linija) - 1] = '\0';
        int redni_broj; char predmet[4]; int ocene[5] = {0,0,0,0,0};
        char *token = strtok(linija, " ");

        while(token){

            if(brojac == 0) redni_broj = atoi(token);
            else if(brojac == 1) strcpy(predmet, token);
            else if(brojac == 2 && atoi(token) > 0) ocene[0] = atoi(token);
            else if(brojac == 3 && atoi(token) > 0) ocene[1] = atoi(token);
            else if(brojac == 4 && atoi(token) > 0) ocene[2] = atoi(token);
            else if(brojac == 5 && atoi(token) > 0) ocene[3] = atoi(token);
            else if(brojac == 6 && atoi(token) > 0) ocene[4] = atoi(token);

            brojac++;
            token = strtok(NULL, " ");
        }

        glava = dodaj(glava, redni_broj, predmet, ocene);

    }

    return glava;

}

int broj_ocena_iter(UCENIK *glava, char *predmet, int min, int max){

    UCENIK *privremeni = glava;

    int brojac = 0;

    while(privremeni){

        if(strcmp(privremeni->predmet, predmet) == 0){

            for(int i = 0; i < 5; i++){

                if(privremeni->ocene[i] == 0) break;

                if(privremeni->ocene[i] >= min && privremeni->ocene[i] <= max) brojac++;

            }

        }

        privremeni = privremeni->sledeci;
    }

    return brojac;

}

int broj_ocena_rek(UCENIK *glava, char *predmet, int min, int max, int brojac){

    if(glava == NULL) return brojac;
    if(strcmp(glava->predmet, predmet) == 0){

        for(int i = 0; i < 5; i++){

            if(glava->ocene[i] == 0) break;

            if(glava->ocene[i] >= min && glava->ocene[i] <= max) brojac++;

        }

    }

    broj_ocena_rek(glava->sledeci, predmet, min, max, brojac);

}

int dodavanje_ocene(UCENIK *glava, int redni_broj, char *predmet, int ocena){

    UCENIK *privremeni = glava;

    while(privremeni){

        if(strcmp(predmet, privremeni->predmet) == 0 && redni_broj == privremeni->redni_broj){

            int brojac = 0;

            for(int i = 0; i < 5; i++){

                if(privremeni->ocene[i] > 0) brojac++;

            }

            if(brojac < 5) {

                for(int i = 0; i < 5; i++){

                    if(privremeni->ocene[i] > 0) continue;

                    privremeni->ocene[i] = ocena;
                    return 1;

                }

            } else return 0;

        }

        privremeni = privremeni->sledeci;
    }

}

UCENIK *brisi(UCENIK *glava){

    while(glava){

        UCENIK *temp = glava;
        glava = glava->sledeci;
        free(temp);

    }

    return glava;

}

int main(){

    int opcija;
    UCENIK *glava = NULL;
    char fajl[10] = "file.txt";

    while(1){

        meni();
        scanf("%d", &opcija);

        if(opcija == 5){

            glava = brisi(glava);

            return 0;

        } else if(opcija == 1){

            glava = ucitaj(glava, fajl);

            printuj(glava);

        } else if(opcija == 2){

            printf("Unesite predmet i raspon ocena: ");

            char predmet[4]; int min; int max;

            scanf("%s %d %d", predmet, &min, &max);

            printf("Na %s ima %d ocena. ", predmet, broj_ocena_iter(glava, predmet, min, max));

        } else if(opcija == 3){

            printf("Unesite predmet i raspon ocena: ");

            char predmet[4]; int min; int max;

            scanf("%s %d %d", predmet, &min, &max);

            printf("Na %s ima %d ocena. ", predmet, broj_ocena_rek(glava, predmet, min, max, 0));

        } else if(opcija == 4){

            printf("Unesite redni broj ucenika, predmet i ocenu: ");
            int redni_broj; char predmet[4]; int ocena;

            scanf("%d %s %d", &redni_broj, predmet, &ocena);

            if(dodavanje_ocene(glava, redni_broj, predmet, ocena)) printuj(glava);
            else printf("Ucenik vec ima 5 ocena");

        }

    }

    return 0;

}
