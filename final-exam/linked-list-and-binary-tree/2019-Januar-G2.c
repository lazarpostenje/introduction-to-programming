#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 150

typedef struct podaci{

    int mesec;
    int godina;
    int decaci;
    int devojcice;
    struct podaci *sledeci;

}PODACI;

typedef struct info{

    int godina;
    int ukupno_decaka;
    int ukupno_devojcica;
    struct info *sledeci;

}INFO;

INFO *napravi_info(int godina, int ukupno_decaka, int ukupno_devojcica){

    INFO *novi = (INFO*) malloc(sizeof(INFO));

    novi->godina = godina;
    novi->ukupno_decaka = ukupno_decaka;
    novi->ukupno_devojcica = ukupno_devojcica;
    novi->sledeci = NULL;

    return novi;

}

INFO *dodaj_info(INFO *glava, int godina, int ukupno_decaka, int ukupno_devojcica){

    INFO *novi = napravi_info(godina, ukupno_decaka, ukupno_devojcica);

    if(glava == NULL){

        glava = novi;
        return glava;

    }

    INFO *privremeni = glava;

    if((ukupno_decaka + ukupno_devojcica) < (privremeni->ukupno_decaka + privremeni->ukupno_devojcica)){

        novi->sledeci = privremeni;
        glava = novi;
        return glava;

    }

    while(privremeni->sledeci != NULL &&
          (privremeni->sledeci->ukupno_decaka + privremeni->sledeci->ukupno_devojcica ) < (ukupno_decaka + ukupno_devojcica) ){

        privremeni = privremeni->sledeci;

    }

    novi->sledeci = privremeni->sledeci;
    privremeni->sledeci = novi;

    return glava;

}

PODACI *napravi(int mesec, int godina, int decaci, int devojcice){

    PODACI *novi = (PODACI*) malloc(sizeof(PODACI));

    novi->mesec = mesec;
    novi->godina = godina;
    novi->decaci = decaci;
    novi->devojcice = devojcice;
    novi->sledeci = NULL;

    return novi;

}

PODACI *dodaj(PODACI *glava, int mesec, int godina, int decaci, int devojcice){

    PODACI *novi = napravi(mesec, godina, decaci, devojcice);

    if(glava == NULL){

        glava = novi;
        return glava;

    }

    PODACI *privremeni = glava;

    if(godina >= privremeni->godina && mesec > privremeni->mesec){

        novi->sledeci = privremeni;
        glava = novi;

        return glava;

    }

    while(privremeni->sledeci != NULL && ((privremeni->sledeci->godina > godina) || (privremeni->sledeci->godina == godina && privremeni->sledeci->mesec > mesec))){

        privremeni = privremeni->sledeci;

    }

    novi->sledeci = privremeni->sledeci;
    privremeni->sledeci = novi;

    return glava;


}

void meni(){

    printf("\n\n1 - ucitavanje podataka\n");
    printf("2 - ispis broja meseci u kome je rodjeno vise od odredjenog broja dece (iterativno)\n");
    printf("3 - ispis broja meseci u kome je rodjeno vise od odredjenog broja dece (rekurzivno)\n");
    printf("4 - Po godini, broj rodjenih sortirano\n");
    printf("6 - izlaz\n");

}

void printuj(PODACI *glava){

    if(glava == NULL) {printf("\n"); return;}
    printf("%d %d %d %d\n", glava->mesec, glava->godina, glava->decaci, glava->devojcice);
    printuj(glava->sledeci);

}





PODACI *ucitaj(PODACI *glava, char *fajl){

    FILE *fp = fopen(fajl, "r");

    char linija[SIZE];

    while(fgets(linija, sizeof(linija), fp)){

        linija[strlen(linija) - 1] = '\0';

        char *token = strtok(linija, " ");

        int brojac = 0;
        int mesec, godina, decaci, devojcice;

        while(token != NULL){

            if(brojac == 0){

                mesec = atoi(token);

            }else if(brojac == 1){

                godina = atoi(token);

            }else if(brojac == 2){

                decaci = atoi(token);

            }else if(brojac == 3){

                devojcice = atoi(token);

            }

            brojac++;
            token = strtok(NULL, " ");
        }

        glava = dodaj(glava, mesec, godina, decaci, devojcice);

    }

    return glava;

}

void broj_meseci(PODACI *glava, int broj_dece){

    int brojac = 0;

    PODACI *privremeni = glava;

    while(privremeni){

        if( (privremeni->decaci + privremeni->devojcice) > broj_dece ) brojac++;

        privremeni = privremeni->sledeci;
    }

    printf("%d", brojac);

}

void broj_meseci_rek(PODACI *glava, int broj_dece, int brojac){

    if(glava == NULL) {printf("%d", brojac); return;}
    if( (glava->devojcice + glava->decaci) > broj_dece ) brojac++;
    broj_meseci_rek(glava->sledeci, broj_dece, brojac);

}

INFO *generisi(PODACI *glava, INFO *vugla){

    for(int i = 2000; i <= 2020; i++){

        int female = 0, male = 0;

        PODACI *privremeni = glava;

        while(privremeni){

            if(privremeni->godina == i){

                female += privremeni->devojcice;
                male += privremeni->decaci;



            }



            privremeni = privremeni->sledeci;

        }

        if(male != 0 && female != 0) vugla = dodaj_info(vugla, i, male, female);

    }

    return vugla;

}

void printuj_info(INFO *glava){

    if(glava == NULL){printf("\n"); return;}
    printf("%d %d %d\n",glava->ukupno_decaka, glava->ukupno_devojcica, glava->godina);
    printuj_info(glava->sledeci);

}


int main(){

    int opcija;

    PODACI *glava = NULL;
    INFO *vugla = NULL;

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

        }else if(opcija == 2){

            int broj_dece;

            printf("Unesite broj dece: ");

            scanf("%d", &broj_dece);

            broj_meseci(glava, broj_dece);

        } else if(opcija == 3){

            int broj_dece;

            printf("Unesite broj dece: ");

            scanf("%d", &broj_dece);

            broj_meseci_rek(glava, broj_dece, 0);

        } else if(opcija == 4){

            vugla = generisi(glava, vugla);
            printuj_info(vugla);

        }

    }

    return 0;
}
