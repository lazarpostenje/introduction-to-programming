#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#define SIZE 100

int provera(int n, int koordinata){

    if(koordinata < n && koordinata >= 0) return 1;

    return 0;

}

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

            novaMatrica[i][j] = -1;

        }

    }


    int k = n - 1;
    int l = 0;
    int j = 0;


    for(int i = 0; i < n; i++){
        novaMatrica[k][l] = matrica[i][j];
        novaMatrica[i][j] = matrica[k][l];
        j++;k--;l++;

    }

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            if(novaMatrica[i][j] == -1){

                int dole = 0, gore = 0, levo = 0, desno = 0;
                int max = 0;

                if(provera(n, i + 1)) dole = 1;
                if(provera(n, i - 1)) gore = 1;
                if(provera(n, j + 1)) desno = 1;
                if(provera(n, j - 1)) levo = 1;

                if(dole && matrica[i + 1][j] % 2 == 0 && matrica[i + 1][j] > max) max = matrica[i + 1][j];
                if(gore && matrica[i - 1][j] % 2 == 0 && matrica[i - 1][j] > max) max = matrica[i - 1][j];
                if(desno && matrica[i][j + 1] % 2 == 0 && matrica[i][j + 1] > max) max = matrica[i][j + 1];
                if(levo && matrica[i][j - 1] % 2 == 0 && matrica[i][j - 1] > max) max = matrica[i][j - 1];

                novaMatrica[i][j] = max;

            }

        }

    }


    printf("\n");




    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            printf("%d ", novaMatrica[i][j]);

        }

        printf("\n");

    }

    return 0;
}