#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define SIZE 40

/**

3 8 3 6 7 3
2 9 2 5 5 6
1 9 3 1 6 8
7 6 1 6 6 9

**/

int proveri(int x, int duzina, int *niz){

    int flag = 0;

    for(int i = 0; i < duzina; i++){

        if(niz[i] == x) flag = 1;

    }

    if(flag) return 1;

    return 0;

}

void pom(int mat[SIZE][SIZE], int *niz, int k, int l, int duzina){

    int dimenzija = -1;
    int koord1 = -1;
    int koord2 = -1;

    for(int x = 2; x <= k; x++){

        for(int i = 0; i < k - x + 1; i++){

            for(int j = 0; j < l - x + 1; j++){

                int flag = 0;

                for(int p = i; p < i + x; p++){

                    for(int q = j; q < j + x; q++){

                        if(proveri(mat[p][q], duzina, niz) == 0) flag = 1;

                    }

                }

                if(flag == 0) {

                    if(x > dimenzija) {

                        dimenzija = x;
                        koord1 = i;
                        koord2 = j;

                    }

                }

            }

        }

    }

    printf("teme: (%d,%d) dim:%dX%d", koord1, koord2, dimenzija, dimenzija);

}

int brojCifara(int n){

    int brojac = 0;

    while(n){

        brojac++;
        n /= 10;

    }

    return brojac;
}

int main() {

    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);

    int niz[SIZE];
    int broj_cifara = brojCifara(n);

    for(int i = 0; i < broj_cifara; i++){
        niz[i] = n % 10;
        n /= 10;
    }

    int mat[SIZE][SIZE];

    for(int i = 0; i < k; i++)
        for(int j = 0; j < l; j++)
            scanf("%d", &mat[i][j]);

    pom(mat, niz, k, l, broj_cifara);


    return 0;
}
