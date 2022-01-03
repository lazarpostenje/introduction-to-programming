#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define SIZE 500


int main() {

    int n;

    scanf("%d", &n);

    int matrica[SIZE][SIZE];
    int novaMatrica[SIZE][SIZE];

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            scanf("%d", &matrica[i][j]);

        }

    }

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            int desna_kolona = 0, leva_kolona = 0;
            int gornja_vrsta = 0, donja_vrsta = 0;

            if(j + 1 >= 0 && j + 1 < n) desna_kolona = 1;
            if(j - 1 >= 0 && j - 1 < n) leva_kolona = 1;

            if(i + 1 >= 0 && i + 1 < n) donja_vrsta = 1;
            if(i - 1 >= 0 && i - 1 < n) gornja_vrsta = 1;

            //max iz vrsta
            //min iz kolona

            int min = INT_MAX;
            int max = INT_MIN;

            for(int k = 0; k < n; k++){

                //kolone

                if(desna_kolona){

                    if(matrica[k][j + 1] < min) min = matrica[k][j + 1];

                }
                if(leva_kolona){

                    if(matrica[k][j - 1] < min) min = matrica[k][j - 1];

                }

            }

            for(int k = 0; k < n; k++){

                if(gornja_vrsta){

                    if(matrica[i - 1][k] > max) max = matrica[i - 1][k];

                }
                if(donja_vrsta){

                    if(matrica[i + 1][k] > max) max = matrica[i + 1][k];

                }

            }

            novaMatrica[i][j] = abs(min - max);

        }

    }

       for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){


            printf("%d ", novaMatrica[i][j]);


        }

        printf("\n");

    }


    return 0;
}