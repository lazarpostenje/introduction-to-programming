#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 150


void meni(){

    printf("\n\n1 - Ucitaj i ispisi podatke\n");
    printf("2 - Najveci broj indeksa (iterativno)\n");
    printf("3 - Najveci broj indeksa (rekurzivno)\n");
    printf("4 - Broj studenata po poenima\n");
    printf("5 - Izlaz i brisanje struktura\n");

}

typedef struct student{

    char smer[3];
    int broj;
    int godina;
    float test1;
    float klk1;
    float test2;
    float klk2;
    struct student *sledeci;

}STUDENT;

typedef struct desetica{

    int broj;
    int ukupno;
    struct desetica *sledeci;

}DESETICA;

DESETICA *napravi_desetica(int broj, int ukupno){

    DESETICA *novi = (DESETICA*) malloc(sizeof(DESETICA));

    novi->broj = broj;
    novi->ukupno = ukupno;
    novi->sledeci = NULL;

    return novi;

}

float konverzija(char *string){

    float rez = 0;

    int ceo = 1;

    char celi[5]; int k = 0;//indexer
    char deci[5]; int p = 0;//indexer

    for(int i = 0; i < strlen(string); i++){

        if(string[i] == '.') {ceo = 0; continue;}

        if(ceo){

            celi[k++] = string[i];
            celi[k] = '\0';

        } else{

            deci[p++] = string[i];
            deci[p] = '\0';

        }

    }

    rez = atoi(celi) + atoi(deci) / 10.0;

    return rez;

}

STUDENT *napravi(char *smer, int broj, int godina, float test1, float klk1, float test2, float klk2){

    STUDENT *novi = (STUDENT*) malloc(sizeof(STUDENT));

    strcpy(novi->smer, smer);
    novi->broj = broj;
    novi->godina = godina;
    novi->test1 = test1;
    novi->klk1 = klk1;
    novi->test2 = test2;
    novi->klk2 = klk2;
    novi->sledeci = NULL;

    return novi;

}

STUDENT *dodaj(STUDENT *glava, char *smer, int broj, int godina, float test1, float klk1, float test2, float klk2){

    STUDENT *novi = napravi(smer, broj, godina, test1, klk1, test2, klk2);

    if(glava == NULL){

        glava = novi;
        return glava;

    }

    STUDENT *privremeni = glava;

    if( (test1+klk1+test2+klk2) > (privremeni->klk1 + privremeni->klk2 + privremeni->test1 + privremeni->test2) ){

        novi->sledeci = privremeni;
        glava = novi;
        return glava;

    }

    while(privremeni->sledeci != NULL && (privremeni->sledeci->klk1 + privremeni->sledeci->klk2 +
                                          privremeni->sledeci->test1 + privremeni->sledeci->test2) > (test1+klk1+test2+klk2)  ){

        privremeni = privremeni->sledeci;

    }


    novi->sledeci = privremeni->sledeci;
    privremeni->sledeci = novi;
    return glava;

}

void broj_indeksa_iter(STUDENT *glava, char *smer, int godina){

    int indeks = 0;

    STUDENT *privremeni = glava;

    while(privremeni){

        if(privremeni->godina == godina && strcmp(privremeni->smer, smer) == 0){

            if(privremeni->broj > indeks) indeks = privremeni->broj;

        }

        privremeni = privremeni->sledeci;

    }

    printf("Najveci broj indeksa za %d je %d", godina, indeks);

}

void broj_indeksa_rek(STUDENT *glava, char *smer, int godina, int indeks){

    if(glava == NULL) {printf("Najveci broj indeksa za %d je %d", godina, indeks); return;}
    if(glava->godina == godina && strcmp(glava->smer, smer) == 0){
        if(glava->broj > indeks) indeks = glava->broj;
    }
    broj_indeksa_rek(glava->sledeci, smer, godina, indeks);

}

void printuj(STUDENT *glava){

    if(glava == NULL) {printf("\n"); return;}
    printf("%s %d %d %g %g %g %g\n", glava->smer, glava->broj, glava->godina, glava->test1, glava->klk1, glava->test2, glava->klk2);
    printuj(glava->sledeci);

}

STUDENT *ucitaj(STUDENT *glava, char *fajl){

    FILE *fp = fopen(fajl, "r");

    char linija[SIZE];

    while(fgets(linija, sizeof(linija), fp)){

        linija[strlen(linija) - 1] = '\0';

        char smer[3]; int broj; int godina; float test1; float klk1; float test2; float klk2;

        char *token = strtok(linija, ",");
        int brojac = 0;

        while(token != NULL){

            if(brojac == 0) strcpy(smer, token);
            else if(brojac == 1) broj = atoi(token);
            else if(brojac == 2) godina = atoi(token);
            else if(brojac == 3) test1 = konverzija(token);
            else if(brojac == 4) klk1 = konverzija(token);
            else if(brojac == 5) test2 = konverzija(token);
            else if(brojac == 6) klk2 = konverzija(token);

            brojac++;
            token = strtok(NULL, ",");

        }

        glava = dodaj(glava, smer, broj, godina, test1, klk1, test2, klk2);

    }

    return glava;

}

float max_poena(STUDENT *glava){

    STUDENT *privremeni = glava;

    float max = 0;

    while(privremeni){

        if( (privremeni->klk1 + privremeni->klk2 + privremeni->test1 + privremeni->test2) > max ) max = privremeni->klk1 + privremeni->klk2 + privremeni->test1 + privremeni->test2;

        privremeni = privremeni->sledeci;

    }

    return max;

}

DESETICA *dodaj_desetica(DESETICA *glava, int broj, int ukupno){

    DESETICA *novi = napravi_desetica(broj, ukupno);

    novi->sledeci = glava;
    glava = novi;
    return glava;

}

void printuj_desetica(DESETICA *glava){

    if(glava == NULL){printf("\n"); return;}

    if(glava->broj == 0) printf(" %d - %d - %d\n", glava->broj, glava->broj + 10, glava->ukupno);
    else printf("%d - %d - %d\n", glava->broj, glava->broj + 9, glava->ukupno);

    printuj_desetica(glava->sledeci);

}

DESETICA *generisi(STUDENT *glava, DESETICA *vugla, float max){

    int najvecaDesetica = max / 10;

    if( (int)max % 10 == 0) najvecaDesetica--;

    for(int i = 0; i <= najvecaDesetica; i++){

        STUDENT *privremeni = glava;

        int min = i * 10;
        int max = (i + 1) * 10;
        if(i != 0) min += 1;

        int ukupno = 0;

        while(privremeni){

            int poeni = privremeni->test1 + privremeni->test2 + privremeni->klk1 + privremeni->klk2;

            if(poeni >= min && poeni <= max){

                ukupno++;

            }

            privremeni = privremeni->sledeci;

        }

        vugla = dodaj_desetica(vugla, min, ukupno);

    }

    return vugla;

}

STUDENT *obrisi_student(STUDENT *glava){

    while(glava != NULL){

        STUDENT *temp = glava;
        glava = glava->sledeci;
        free(temp);

    }

    return glava;

}

DESETICA *obrisi_desetica(DESETICA *glava){

    while(glava != NULL){

        DESETICA *temp = glava;
        glava = glava->sledeci;
        free(temp);

    }

    return glava;

}

int main()
{

    STUDENT *glava = NULL;
    DESETICA *vugla = NULL;
    int opcija;
    char fajl[SIZE];

    while(1){

        meni();

        scanf("%d", &opcija);

        if(opcija == 5){

            glava = obrisi_student;
            vugla = obrisi_desetica;

            return 0;

        } else if(opcija == 1){

            printf("Unesite ime fajla: ");
            scanf("%s", fajl);

            glava = ucitaj(glava, fajl);

            printuj(glava);

        } else if(opcija == 2){

            printf("Unesite oznaku smera i godinu upisa: ");

            char smer[3];
            int godina;

            scanf("%s %d", smer, &godina);

            broj_indeksa_iter(glava, smer, godina);

        } else if(opcija == 3){

            printf("Unesite oznaku smera i godinu upisa: ");

            char smer[3];
            int godina;

            scanf("%s %d", smer, &godina);

            broj_indeksa_rek(glava, smer, godina, 0);

        } else if(opcija == 4){

            vugla = generisi(glava, vugla, max_poena(glava));
            printuj_desetica(vugla);

        }


    }

    return 0;
}
