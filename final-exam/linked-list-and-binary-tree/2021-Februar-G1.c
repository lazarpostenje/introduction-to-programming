#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define SIZE 100

/**
Napisati program koji učitava podatke o rezultatima trka za više trkača. U jednom
redu u fajlu nalaze se podaci o rezultatu jednog trkača na jednoj trci i to redom brojčana
oznaka trke, slovna oznaka igrača i postignuti rezultat trkača na trci.
Primer
10 c 11.09 - na trci pod brojem 10 trkač sa oznakom c postigao je rezultat 11.09 sekundi.
Napraviti meni za interakciju preko konzole i implementirati sledeće opcije:

a) (7p) učitavanje podataka, podaci o rezultatima trka učitavaju se u listu uređenu
prvo po brojčanoj oznaci trke rastuće, a zatim za istu trku po vremenu trkača opadajuće,
nakon učitavanja ispisati listu.

b) (8p) redni broj na trci za igrača, unosi se oznaka trke i oznaka igrača i treba
izračunati koje mesto je uneti igrač osvojio na unetoj trci (iskoristiti način na koji je lista
uređena), ovu funkcionalnost je potrebno uraditi na dva načina iterativno i rekurzivno.

c) (9p) generisanje ukupnih rezultata, osmisliti strukturu u koju će se smestiti igrači i
ukupan broj osvojenih poena na trkama, poeni se dodeljuju po formuli 20-mesto, gde je
mesto pozicija koju je igrač zauzeo na trci. Ispisati trkače i za svakog trkača osvojeni broj
poena u opadajućem redosledu po broju poena.

d) (1p) izlaz iz programa i brisanje svih struktura
**/

typedef struct Trkac{
    int trka;
    char oznaka;
    float rezultat;
    struct Trkac *sledeci;
}TRKAC;

typedef struct Igrac{
    int poeni;
    char oznaka;
    struct Igrac *sledeci;
}IGRAC;

IGRAC *napravi_igraca(int poeni, char oznaka) {
    IGRAC *novi = (IGRAC*)malloc(sizeof(IGRAC));
    novi->poeni = poeni;
    novi->oznaka = oznaka;
    novi->sledeci = NULL;
    return novi;
}

TRKAC *napravi(int trka, char oznaka, float rezultat) {
    TRKAC *novi = (TRKAC*)malloc(sizeof(TRKAC));
    novi->trka = trka;
    novi->oznaka = oznaka;
    novi->rezultat = rezultat;
    novi->sledeci = NULL;
    return novi;
}

TRKAC *dodaj_sortirano(TRKAC *glava, int trka, char oznaka, float rezultat) {

    TRKAC *novi = napravi(trka, oznaka, rezultat);
    if (glava == NULL) {
        glava = novi;
        return glava;
    }

    TRKAC *privremeni = glava;
    if (trka <= privremeni->trka && rezultat > privremeni->rezultat) {
        novi->sledeci = glava;
        glava = novi;
        return glava;
    }

    while (privremeni->sledeci != NULL && ((privremeni->sledeci->trka < trka) ||
                                           (privremeni->sledeci->trka == trka && privremeni->sledeci->rezultat > rezultat))) {
                    privremeni = privremeni->sledeci;
    }

    novi->sledeci = privremeni->sledeci;
    privremeni->sledeci = novi;
    return glava;
}

void meni() {
    printf("1. Ucitaj podatke\n");
    printf("2. Prikazi podatke\n");
    printf("3. Prikazi redni broj igraca na trci (Iterativno)\n");
    printf("4. Prikazi redni broj igraca na trci (Rekurzivno)\n");
    printf("5. Generisi rezultate\n");
    printf("7. Izlaz\n");
}

float konverzija(char *str) {
    float rez;
    int brojac = 0;
    char *token = strtok(str, ".");
    while (token != NULL) {
        if (brojac == 0) rez = atoi(token);
        else if (brojac == 1) rez = rez + atoi(token)/100.0;
        brojac++;
        token = strtok(NULL, ".");
    }
    return rez;
}

void printuj(TRKAC *glava) {
    if (glava == NULL) {printf("\n"); return;}
    printf("%d %c %.2f\n", glava->trka, glava->oznaka, glava->rezultat);
    printuj(glava->sledeci);
}

TRKAC *ucitaj(TRKAC *glava, char *fajl) {
    FILE *fp = fopen(fajl, "r");
    char linija[SIZE];
    while (fgets(linija, sizeof(linija), fp)) {
        char *token = strtok(linija, " ");
        int brojac = 0;

        int trka;
        char oznaka;
        float rezultat;

        while (token != NULL) {

            if (brojac == 0) trka = atoi(token);
            else if (brojac == 1) oznaka = token[0];
            else rezultat = konverzija(token);

            brojac++;
            token = strtok(NULL, " ");
        }
        glava = dodaj_sortirano(glava, trka, oznaka, rezultat);
    }
    fclose(fp);
    return glava;
}

void redni_broj(TRKAC *glava, int trka, char oznaka) {
    int brojac = 1;
    TRKAC *privremeni = glava;

    if (privremeni->trka == trka && privremeni->oznaka == oznaka) {
        printf("\nRedni broj: 1\n\n");
        return;
    }
    brojac++;
    while (privremeni->sledeci != NULL && ((privremeni->sledeci->trka != trka) ||
                                           (privremeni->sledeci->trka == trka && privremeni->sledeci->oznaka != oznaka))) {
        if (privremeni->trka != privremeni->sledeci->trka) brojac = 1;
        privremeni = privremeni->sledeci;
        brojac++;
    }
    printf("\nRedni broj: %d\n\n", brojac);
    return;

}

int redni_broj_rek(TRKAC *glava, int trka, char oznaka, int brojac) {
    if (glava == NULL || (glava->trka == trka && glava->oznaka == oznaka)) {
            return brojac;
            }
    if (glava->trka != glava->sledeci->trka) brojac = 0;
    return redni_broj_rek(glava->sledeci, trka, oznaka, brojac+1);
}

IGRAC *dodaj(IGRAC *glava, int poeni, char oznaka) {
    IGRAC *novi = napravi_igraca(poeni, oznaka);

    if (glava == NULL) {
        glava = novi;
        return glava;
    }
    IGRAC *privremeni = glava;
    if (poeni > privremeni->poeni) {
        novi->sledeci = glava;
        glava = novi;
        return glava;
    }
    while (privremeni->sledeci != NULL && privremeni->sledeci->poeni > poeni) {
        privremeni = privremeni->sledeci;
    }
    novi->sledeci = privremeni->sledeci;
    privremeni->sledeci = novi;
    return glava;
}

IGRAC *ukupni_poeni(IGRAC *p, TRKAC *glava) {
    for (char c = 'a'; c <= 'z'; c++) {
        TRKAC *privremeni = glava;
        int rez = 0;
        while (privremeni != NULL) {

            if (privremeni->oznaka == c) rez += 20 - redni_broj_rek(glava, privremeni->trka, privremeni->oznaka, 1);
            privremeni = privremeni->sledeci;
        }
        if (rez != 0) p = dodaj(p, rez, c);
        rez = 0;
    }
    return p;
}

void printuj_poene(IGRAC *glava) {
    if (glava == NULL) {printf("\n"); return;}
    printf("Oznaka - %c | Poeni - %d\n",glava->oznaka, glava->poeni);
    printuj_poene(glava->sledeci);
}

TRKAC *izbrisi(TRKAC *glava) {
    while (glava != NULL) {
        TRKAC *temp = glava;
        glava = glava->sledeci;
        free(glava);
    }
    return glava;
}

int main()
{
    TRKAC *glava = NULL;
    IGRAC *p = NULL;
    int opcija;
    char naziv_fajla[SIZE];

    while (1) {
        meni();
        printf("\nOdaberite opciju: ");
        scanf("%d", &opcija);
        if (opcija == 7) {
            printf("\nExited!\n");
            glava = izbrisi(glava);
            return 0;
        }
        else if (opcija == 1) {
            printf("\nUnesite naziv fajla: ");
            scanf("%s", naziv_fajla);
            glava = ucitaj(glava, naziv_fajla);
            if (glava == NULL) printf("\nGreska prilikom ucitavanja\n\n");
            else printf("\nPodaci su uspesno ucitani!\n\n");
        }
        else if (opcija == 2) {
            printuj(glava);
        }
        else if (opcija == 3) {
            int broj, oznaka;
            printf("Unesite oznaku trke i oznaku igraca: ");
            scanf("%d %c", &broj, &oznaka);
            redni_broj(glava, broj, oznaka);
        }
        else if (opcija == 4) {
            int broj, oznaka;
            printf("Unesite oznaku trke i oznaku igraca: ");
            scanf("%d %c", &broj, &oznaka);
            printf("\nRedni broj: %d\n\n",redni_broj_rek(glava, broj, oznaka, 1));
        }
        else if (opcija == 5) {
            p = ukupni_poeni(p, glava);
            printuj_poene(p);
        }
        else {
            printf("\nGreska.\n");
            glava = izbrisi(glava);
            return 0;
        }

    }
    return 0;
}