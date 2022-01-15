#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int provera(int *niz, int duzina, int x){
    int flag = 0;

    for (int i = 0; i < duzina ; i++){

        if(niz[i] == x){ flag = 1; break;}
        else flag = 0;

    }

    return flag;
}

void pom(int mat[SIZE][SIZE], int k, int l, int *niz, int duzina){
    int dimenzija = -1;
    int dimenzija2 = -1;
    int koord1 = -1;
    int koord2 = -1;

    for(int x = 1; x <= k; x++){

        for(int y = 1; y <= l; y++){

            if(x == y) continue;

            for(int i = 0; i < k - x +1; i++){

                for(int j = 0; j < l - y +1; j++){

		   int flag = 0;

                    for(int p = i; p < x + i; p++){

                        for(int q = j; q < y + j; q++){

                            if (p == i || p == x + i -1 || q == j || q == y + j -1){
                                if(provera(niz,duzina,mat[p][q]) == 1){
                                    flag = 1;
                                }

                            }
                        }
                    }
                    if(flag == 0){
                        if(x*y > dimenzija*dimenzija2) {
                                dimenzija = x;
                                dimenzija2 = y;
                                koord1 = i;
                                koord2 = j;
                        }
                    }
                }
            }
        }
    }

    printf("teme: (%d,%d) dim:%dX%d", koord1, koord2, dimenzija, dimenzija2);
}

int brojCifara(int n){
    int brojac = 0;

    while(n){

        brojac++;
        n/=10;
    }

    return brojac;
}
int main () {
    int n, k, l;

    scanf("%d %d %d", &n, &k, &l);

    int broj_cifara = brojCifara(n);
    int niz[SIZE];
    for(int i = 0; i < broj_cifara; i++){
        niz[i] = n%10;
        n/=10;
    }

    int mat[SIZE][SIZE];


    for(int i = 0; i < k; i++)
       for(int j = 0; j < l; j++)
            scanf("%d", &mat[i][j]);

    pom(mat,k,l,niz,broj_cifara);

    return 0;
}