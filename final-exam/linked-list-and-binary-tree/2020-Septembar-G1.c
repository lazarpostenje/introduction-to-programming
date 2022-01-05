#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#define SIZE 200

int konvertuj(char *string){

    int indexer = 0;

    char noviString[SIZE];

    for(int i = 0; i < strlen(string); i++){

        if(string[i] != '.'){

            noviString[indexer++] = string[i];
            noviString[indexer] = '\0';

        }

    }

    return atoi(noviString);

}

void meni(){

    printf("\n\n1 - ucitavanje podataka\n");
    printf("2 - ispis u rasponu (iterativno)\n");
    printf("3 - ispis u rasponu (rekurzivno)\n");
    printf("4 - razlika izmedju istih meseci\n");
    printf("5 - izlaz i brisanje struktura\n");

}

typedef struct zarada{

    char mesec[SIZE];
    int godina;
    char bruto[SIZE];
    char neto[SIZE];
    struct zarada *sledeci;

}ZARADA;

ZARADA *napravi(char *mesec, int godina, char *bruto, char *neto){

    ZARADA *novi = (ZARADA*) malloc(sizeof(ZARADA));

    strcpy(novi->mesec, mesec);
    novi->godina = godina;
    strcpy(novi->bruto, bruto);
    strcpy(novi->neto, neto);
    novi->sledeci = NULL;

    return novi;

}

ZARADA *dodaj(ZARADA *glava, char *mesec, int godina, char *bruto, char *neto){

    ZARADA *novi = napravi(mesec, godina, bruto, neto);

    if(glava == NULL){

        glava = novi;

        return glava;

    }

    ZARADA *privremeni = glava;

    if(konvertuj(bruto) > konvertuj(privremeni->bruto)){

        novi->sledeci = privremeni;
        glava = novi;

        return glava;

    }

    while(privremeni->sledeci != NULL && konvertuj(privremeni->sledeci->bruto) > konvertuj(bruto) ){

        privremeni = privremeni->sledeci;

    }

    novi->sledeci = privremeni->sledeci;
    privremeni->sledeci = novi;

    return glava;

}

ZARADA *ucitaj(ZARADA *glava, char *fajl){

    FILE *fp = fopen(fajl, "r");

    char linija[SIZE];

    while(fgets(linija, sizeof(linija), fp)){

        linija[strlen(linija) - 1] = '\0';

        char *token = strtok(linija, " ");

        int brojac = 0;

        char mesec[SIZE]; int godina; char bruto[SIZE]; char neto[SIZE];


        while(token != NULL){

            if(brojac == 0) strcpy(mesec, token);
            else if(brojac == 1) godina = atoi(token);
            else if(brojac == 2) strcpy(bruto, token);
            else if(brojac == 3) strcpy(neto, token);


            brojac++;
            token = strtok(NULL, " ");

        }

        glava = dodaj(glava, mesec, godina, bruto, neto);

    }

    return glava;


}

void ispis_raspon(ZARADA *glava, int pocetak, int kraj){

    ZARADA *privremeni = glava;

    while(privremeni){

        if(pocetak < konvertuj(privremeni->neto) && kraj > konvertuj(privremeni->neto)){

            printf("%s %d\n", privremeni->mesec, privremeni->godina);

        }

        privremeni = privremeni->sledeci;

    }

}

void ispis_raspon_rek(ZARADA *glava, int pocetak, int kraj){

    if(glava == NULL) {printf("\n"); return;}
    if(konvertuj(glava->neto) > pocetak && konvertuj(glava->neto) < kraj){

        printf("%s %d\n", glava->mesec, glava->godina);

    }
    ispis_raspon_rek(glava->sledeci, pocetak, kraj);

}

void printuj(ZARADA *glava){

    if(glava == NULL){printf("\n"); return;}
    printf("%s %d\t %s %s\n", glava->mesec, glava->godina, glava->bruto, glava->neto);
    printuj(glava->sledeci);

}

void razlika_meseci(ZARADA *glava){

    ZARADA *privremeni = glava;

    while(privremeni){

        ZARADA *privremeni2 = glava;

        while(privremeni2){

            if(strcmp(privremeni2->mesec, privremeni->mesec) == 0){

                if(privremeni->godina != privremeni2->godina){

                    int max;
                    int razlika;
                    int godina;

                    if(konvertuj(privremeni->neto) > konvertuj(privremeni2->neto)){

                        max = konvertuj(privremeni->neto);
                        razlika = max - konvertuj(privremeni2->neto);
                        godina = privremeni->godina;

                    } else {

                        max = konvertuj(privremeni2->neto);
                        razlika = max - konvertuj(privremeni->neto);
                        godina = privremeni2->godina;
                    }

                    printf("%s %d %d\n", privremeni->mesec, razlika, godina);

                }

            }


            privremeni2 = privremeni2->sledeci;

        }

        privremeni = privremeni->sledeci;
    }


}

ZARADA *obrisi(ZARADA *glava){

    while(glava){

        ZARADA *temp = glava;
        glava = glava->sledeci;
        free(temp);

    }

    return glava;

}

int main() {

    int opcija;
    char fajl[SIZE];
    ZARADA *glava = NULL;

    while(1){

        meni();

        scanf("%d", &opcija);

        if(opcija == 5){

            glava = obrisi(glava);
            return 0;

        }else if(opcija == 1){

            printf("Unesite naziv fajla: ");
            scanf("%s", fajl);

            glava = ucitaj(glava, fajl);

            printuj(glava);

        } else if(opcija == 2){

            printf("Unesite raspon(dva broja): ");

            int pocetak, kraj;

            scanf("%d%d", &pocetak, &kraj);

            if(pocetak > kraj) {printf("Uneli ste pogresan raspon"); continue;}

            ispis_raspon(glava, pocetak, kraj);

        } else if(opcija == 3){

            printf("Unesite raspon(dva broja): ");

            int pocetak, kraj;

            scanf("%d%d", &pocetak, &kraj);

            if(pocetak > kraj) {printf("Uneli ste pogresan raspon"); continue;}

            ispis_raspon_rek(glava, pocetak, kraj);

        }else if(opcija == 4){

            razlika_meseci(glava);

        }


    }

    return 0;

}