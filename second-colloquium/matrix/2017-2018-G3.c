#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int brojCifara(int n) {

    int brojilo = 0;

    while (n) {

        brojilo++;

        n /= 10;

    }

    return brojilo;

}

int main() {

    int n;

    scanf("%d", &n);

    int matrica[SIZE][SIZE];

    int n1 = n;

    int dimenzija = brojCifara(n);

    int pomocniNiz[dimenzija];

    int pomocniReversovanNiz[dimenzija];

    for(int i = dimenzija - 1; i >= 0; i--){

        pomocniNiz[i] = n % 10;

        n /= 10;

    }

    for(int i = 0; i < dimenzija; i++){

        pomocniReversovanNiz[i] = n1 % 10;

        n1 /= 10;

    }


    for (int i = 0; i < dimenzija; i++) {

        for (int j = 0; j < dimenzija; j++) {

            if (i == j) matrica[i][j] = pomocniReversovanNiz[j];
            else if (j == dimenzija - i - 1) matrica[i][j] = pomocniReversovanNiz[j];
            else {

                if(dimenzija % 2 != 0){

                    if(j > i && j < dimenzija - i - 1){

                        int broj = pomocniReversovanNiz[j] - 1;
                        if(broj < 0) broj += 10;
                        matrica[i][j] = broj;

                    }
                    else if(j > dimenzija - i - 1 && j < i) {

                        int broj = pomocniReversovanNiz[j] - 1;
                        if(broj < 0) broj += 10;
                        matrica[i][j] = broj;

                    }
                    else if(j > dimenzija - i - 1 && j > i) {

                        int broj = pomocniReversovanNiz[j] + 1;
                        if(broj >= 10) broj -= 10;
                        matrica[i][j] = broj;

                    }
                    else if(j < dimenzija - i - 1 && j < i) {

                        int broj = pomocniReversovanNiz[j] + 1;
                        if(broj >= 10) broj -= 10;
                        matrica[i][j] = broj;

                    }

                }else {

                    if(j > i && j < dimenzija - i - 1){

                        int broj = pomocniReversovanNiz[j] + 1;
                        if(broj >= 10) broj -= 10;
                        matrica[i][j] = broj;


                    }
                    else if(j > dimenzija - i - 1 && j < i) {

                        int broj = pomocniReversovanNiz[j] + 1;
                        if(broj >= 10) broj -= 10;
                        matrica[i][j] = broj;

                    }
                    else if(j > dimenzija - i - 1 && j > i) {

                        int broj = pomocniReversovanNiz[j] + 1;
                        if(broj >= 10) broj -= 10;
                        matrica[i][j] = broj;


                    }
                    else if(j < dimenzija - i - 1 && j < i) {

                        int broj = pomocniReversovanNiz[j] - 1;
                        if(broj < 0) broj += 10;
                        matrica[i][j] = broj;

                    }
                }
            }
        }
    }

    for (int i = 0; i < dimenzija; i++) {

        for (int j = 0; j < dimenzija; j++) {

            printf("%d ", matrica[i][j]);

        }

        printf("\n");

    }

    return 0;
}