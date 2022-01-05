#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 150

typedef struct sinonimi{

    char rec[SIZE];
    char sinonim[SIZE];
    struct sinonimi *sledeci;

}SINONIMI;

SINONIMI *napravi(char *rec, char *sinonim){

    SINONIMI *novi = (SINONIMI*) malloc(sizeof(SINONIMI));

    strcpy(novi->rec, rec);
    strcpy(novi->sinonim, sinonim);
    novi->sledeci = NULL;

    return novi;

}

SINONIMI *dodaj(SINONIMI *glava, char *rec, char *sinonim){

    SINONIMI *novi = napravi(rec, sinonim);

    if(glava == NULL){

        glava = novi;
        return glava;

    }

    SINONIMI *privremeni = glava;

    if(compare(rec, privremeni->rec) < 0){

        novi->sledeci = privremeni;
        glava = novi;

        return glava;

    }

    while(privremeni->sledeci != NULL && compare(rec, privremeni->sledeci->rec) > 0){

        privremeni = privremeni->sledeci;

    }

    novi->sledeci = privremeni->sledeci;
    privremeni->sledeci = novi;

    return glava;

}

SINONIMI *ucitaj(SINONIMI *glava, char *fajl){

    FILE *fp = fopen(fajl, "r");

    char linija[SIZE];

    while(fgets(linija, sizeof(linija), fp)){

        linija[strlen(linija) - 1] = '\0';

        char *token = strtok(linija, "-");
        int brojac = 0;

        char rec[SIZE];
        char sinonim[SIZE];

        while(token != NULL){

            if(brojac == 0){

                strcpy(rec, token);

            } else if(brojac == 1){

                strcpy(sinonim, token);

            }

            brojac++;
            token = strtok(NULL, "-");
        }

        glava = dodaj(glava, rec, sinonim);


    }

    return glava;

}

int compare(char *string1, char *string2){

    return strcmp(string1, string2);

}

void printuj(SINONIMI *glava){

    if(glava == NULL) {printf("\n"); return;}

    printf("%s-%s\n", glava->rec, glava->sinonim);

    printuj(glava->sledeci);

}

void meni(){

    printf("\n\n1 - ucitavanje sinonima\n");
    printf("2 - ispis svih sinonima jedne reci (iterativno)\n");
    printf("3 - ispis svih sinonima jedne reci (rekurzivno)\n");
    printf("4 - rec sa najvise sinonima\n");
    printf("6 - Izlaz\n");

}

void pronadji_sinonime(SINONIMI *glava, char *uneta_rec){

    SINONIMI *privremeni = glava;

    while(privremeni != NULL){

        if(compare(uneta_rec, privremeni->sinonim) == 0) printf("%s\n", privremeni->rec);

        if(compare(uneta_rec, privremeni->rec) == 0) printf("%s\n", privremeni->sinonim);

        privremeni = privremeni->sledeci;
    }

}

void pronadji_sinonime_rek(SINONIMI *glava, char *uneta_rec){

    if(glava == NULL) {printf("\n"); return;}
    if(compare(uneta_rec, glava->sinonim) == 0) printf("%s\n", glava->rec);
    if(compare(uneta_rec, glava->rec) == 0) printf("%s\n", glava->sinonim);
    pronadji_sinonime_rek(glava->sledeci, uneta_rec);

}

int broj_sinonima_po_reci(SINONIMI *glava, char *uneta_rec){

    SINONIMI *privremeni = glava;

    int brojac = 0;

    while(privremeni != NULL){

        if(compare(uneta_rec, privremeni->sinonim) == 0) brojac++;

        if(compare(uneta_rec, privremeni->rec) == 0) brojac++;

        privremeni = privremeni->sledeci;

    }

    return brojac;

}

void broj_sinonima(SINONIMI *glava){

    int brojac = 0, max = 0;

    SINONIMI *privremeni = glava;

    char najvisePonavljanja[SIZE];

    while(privremeni){

        int po_reci = broj_sinonima_po_reci(glava, privremeni->rec);

        int po_sinonimu = broj_sinonima_po_reci(glava, privremeni->sinonim);

        if(po_reci > po_sinonimu){

            if(po_reci > max){

                max = po_reci;
                strcpy(najvisePonavljanja, privremeni->rec);

            }

        } else {

            if(po_sinonimu > max){

                max = po_sinonimu;
                strcpy(najvisePonavljanja, privremeni->sinonim);

            }
        }

        privremeni = privremeni->sledeci;
    }

    printf("Rec: %s\n", najvisePonavljanja);
    pronadji_sinonime_rek(glava, najvisePonavljanja);

}

int main(){

    int opcija;
    SINONIMI *glava = NULL;
    char fajl[SIZE];

    while(1){

        meni();

        scanf("%d", &opcija);

        if(opcija == 6){

            break;

        } else if(opcija == 1){

            printf("Unesite ime fajla: ");
            scanf("%s", fajl);

            glava = ucitaj(glava, fajl);
            printuj(glava);

        } else if(opcija == 2){

            char rec[SIZE];

            printf("Unesi rec: ");

            scanf("%s", rec);

            pronadji_sinonime(glava, rec);

        }else if(opcija == 3){

            char rec[SIZE];

            printf("Unesi rec: ");

            scanf("%s", rec);

            pronadji_sinonime_rek(glava, rec);

        } else if(opcija == 4){

            broj_sinonima(glava);

        }

    }

    return 0;
}
