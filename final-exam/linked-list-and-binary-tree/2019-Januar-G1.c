#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100


/**

        Napisati program koji učitava podatke o broju rođenih beba po datumima u jednom gradu i
        smešta ih u listu. Podaci se u fajlu nalaze u obliku: dan mesec godina broj beba, svi podaci su
        razdvojeni spejsom. Primer: 23 2 2018 12 (23. februara 2018. rođeno je 12 beba).
        Napraviti meni za interakciju preko konzole sa slededim opcijama.

        a) (7p) učitavanje podataka, unosi se naziv fajla koji sadrži opisane podatke i učitava se u listu
        uređenu nerastude po broju rođenih beba,

        b) (8p) ispis broja rođenih beba u jednoj godini, unosi se godina i treba ispisati broj rođenih u toj
        godini, ovu funkcionalnost je potrebno implementirati na dva načina, iterativno i rekurzivno,

        c) (10p) ispis broja rođenih beba po mesecima sortirano rastude po godini i mesecu, posmatra se
        broj rođenih beba u konkretnom mesecu (na primer 2.2018.) i ispisuje se mesec, godina i broj
        rođenih u tom mesecu, sortirano rastude po mesecu (dozvoljeno je praviti nove strukture podataka).



**/

void meni(){

    printf("\n\n1 - Ucitaj podatke\n");
    printf("2 - Prikazi podatke\n");
    printf("3 - ispis broja rodjenih beba u jednoj godini (iterativno)\n");
    printf("4 - ispis broja rodjenih beba u jednoj godini (rekurzivno)\n");
    printf("5 - ispis broja rodjenih beba po mesecima\n");
    printf("6 - Izlaz\n");

}

typedef struct bebe{

    int dan;
    int mesec;
    int godina;
    int broj_beba;
    struct bebe *sledeci;

}BEBE;

typedef struct mesec{

    int mesec;
    int godina;
    int broj_beba;
    struct mesec *sledeci;

}MESEC;


MESEC *napravi_mesec(int mesec, int godina, int broj_beba){

    MESEC *novi = (MESEC*) malloc(sizeof(MESEC));

    novi->mesec = mesec;
    novi->godina = godina;
    novi->broj_beba = broj_beba;
    novi->sledeci = NULL;

    return novi;
}

BEBE *napravi(int dan, int mesec, int godina, int broj_beba){

    BEBE *novi = (BEBE*) malloc(sizeof(BEBE));

    novi->dan = dan;
    novi->mesec = mesec;
    novi->godina = godina;
    novi->broj_beba = broj_beba;
    novi->sledeci = NULL;

    return novi;

}


BEBE *dodaj_sortirano(BEBE *glava, int dan, int mesec, int godina, int broj_beba){

    BEBE *novi = napravi(dan, mesec, godina, broj_beba);

    if(glava == NULL){

        glava = novi;
        return glava;

    }

    BEBE *privremeni = glava;

    if(privremeni->broj_beba < broj_beba){

        novi->sledeci = privremeni;
        glava = novi;

        return glava;

    }

    while(privremeni->sledeci != NULL && privremeni->sledeci->broj_beba > broj_beba){

        privremeni = privremeni->sledeci;

    }

    novi->sledeci = privremeni->sledeci;
    privremeni->sledeci = novi;

    return glava;

}

BEBE *ucitaj(BEBE *glava, char *fajl){

    FILE *fp = fopen(fajl, "r");

    char linija[SIZE];

    while(fgets(linija, sizeof(linija), fp)){

        int brojac = 0;

        char *token = strtok(linija, " ");

        int dan, mesec, godina, broj_beba;

        while(token != NULL){

            if(brojac == 0) dan = atoi(token);
            else if(brojac == 1) mesec = atoi(token);
            else if(brojac == 2) godina = atoi(token);
            else if(brojac == 3) broj_beba = atoi(token);

            brojac++;
            token = strtok(NULL, " ");

        }

        glava = dodaj_sortirano(glava, dan, mesec, godina, broj_beba);

    }

    return glava;

}

void printuj(BEBE *glava){

    if(glava == NULL) {printf("\n"); return;}
    printf("%d %d %d %d\n", glava->dan, glava->mesec, glava->godina, glava->broj_beba);
    printuj(glava->sledeci);

}

void printuj_mesece(MESEC *glava){

    if(glava == NULL) {printf("\n"); return;}
    printf("%d.%d - %d\n", glava->mesec, glava->godina, glava->broj_beba);
    printuj_mesece(glava->sledeci);

}

int bebe_po_godini(BEBE *glava, int godina){

    int zbir = 0;

    if(glava == NULL) return -1;

    BEBE *privremeni = glava;

    while(privremeni != NULL){

        if(privremeni->godina == godina){

            zbir += privremeni->broj_beba;

        }

        privremeni = privremeni->sledeci;

    }

    return zbir;

}

int bebe_po_godini_rek(BEBE *glava, int godina, int zbir){

    if(glava == NULL) return zbir;
    if(glava->godina == godina) zbir += glava->broj_beba;
    bebe_po_godini_rek(glava->sledeci, godina, zbir);

}

MESEC *dodaj_sortirane_mesece(MESEC *glava, int mesec, int godina, int broj_beba){

    MESEC *novi = napravi_mesec(mesec, godina, broj_beba);

    if(glava == NULL){

        glava = novi;
        return glava;

    }

    MESEC *privremeni = glava;

    if(mesec <= privremeni->mesec && godina <= privremeni->godina){

        novi->sledeci = privremeni;
        glava = novi;

        return glava;

    }

    while(privremeni->sledeci != NULL && ((privremeni->sledeci->godina < godina)
            || (privremeni->sledeci->godina == godina && privremeni->sledeci->mesec < mesec) )){

        privremeni = privremeni->sledeci;

    }

     novi->sledeci = privremeni->sledeci;
     privremeni->sledeci = novi;

     return glava;

}

MESEC *generisi(BEBE *glava, MESEC *vugla){

    for(int i = 2010; i <= 2020; i++){

        for(int j = 1; j <= 12; j++){

            //i = godina
            //j = mesec

            BEBE *privremeni = glava;

            int zbir = 0;

            while(privremeni != NULL){

                if(privremeni->godina == i && privremeni->mesec == j){

                    zbir += privremeni->broj_beba;

                }

                privremeni = privremeni->sledeci;

            }

            if(zbir != 0) vugla = dodaj_sortirane_mesece(vugla, j, i, zbir);

        }

    }

    return vugla;

}

int main()
{

    int opcija;

    BEBE *glava = NULL;
    MESEC *vugla = NULL;

    while(1){

        meni();

        scanf("%d", &opcija);

        if(opcija == 1){

            char fajl[SIZE];

            printf("\nUnesite naziv fajla: ");

            scanf("%s", fajl);

            glava = ucitaj(glava, fajl);



        } else if(opcija == 2){

            printuj(glava);


        }else if(opcija == 3){

            int godina;

            printf("Unesite godinu: ");

            scanf("%d", &godina);

            printf("Broj rodjenih beba je %d", bebe_po_godini(glava, godina));

        }else if(opcija == 4){

            int godina;

            printf("Unesite godinu: ");

            scanf("%d", &godina);

            printf("Broj rodjenih beba je %d", bebe_po_godini_rek(glava, godina, 0));

        }else if(opcija == 5){

            vugla = generisi(glava, vugla);

            printuj_mesece(vugla);

        } else if(opcija == 6){

            return 0;

        }

    }

    return 0;
}
