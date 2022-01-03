#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define SIZE 50

int reverse(int n){

    int broj = 0;

    while(n){

        int cifra = n % 10;

        broj = broj * 10 + cifra;

        n /= 10;

    }

    return broj;

}

int brojCifara(int n){

    int brojac  = 0;

    while(n){

        brojac++;

        n /= 10;

    }

    return brojac;

}

int main() {

    int n;

    scanf("%d", &n);

    int pomocniNiz[SIZE];

    int inverzniN = reverse(n);

    for(int i = 0; i < brojCifara(n); i++){

        pomocniNiz[i] = inverzniN % 10;

        inverzniN /= 10;

    }

    int matrica[SIZE][SIZE];

    int dimenzija = brojCifara(n);

    for(int i = 0; i < dimenzija; i++){

        for(int j  = 0; j < dimenzija; j++){

            if(i == 0) matrica[i][j] = pomocniNiz[j];
            else {

                if(i % 2 != 0) {

                    pomocniNiz[j] = pomocniNiz[j] - 1;

                    if(pomocniNiz[j] < 0) pomocniNiz[j] += 10;

                    matrica[i][j] = pomocniNiz[j];

                } else {

                    pomocniNiz[j] = pomocniNiz[j] - 2;

                    if(pomocniNiz[j] < 0) pomocniNiz[j] += 10;

                    matrica[i][j] = pomocniNiz[j];

                }
            }

        }

    }

    for(int i = 0; i < dimenzija; i++){

        for(int j  = 0; j < dimenzija; j++){

            printf("%d ", matrica[i][j]);

        }

        printf("\n");

    }





    return 0;

}