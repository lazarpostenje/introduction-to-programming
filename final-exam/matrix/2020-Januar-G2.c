#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

void pom(int mat[SIZE][SIZE], int n){

    int dimenzija1 = -1;
    int dimenzija2 = -1;
    int koord1 = -1;
    int koord2 = -1;

    for(int x = 1; x <= n; x++){

        for(int y = 1; y <= n; y++){

            if(x == y) continue;

            for(int i = 0; i < n - x + 1; i++){

                for(int j = 0; j < n - y + 1; j++){

                    int parni = 0, neparni = 0, izadji = 0;

                    for(int p = i; p < i + x; p++){

                        for(int q = j; q < j + y; q++){

                            if(mat[p][q] % 2 == 0) parni = 1;
                            else neparni = 1;

                            if(parni && neparni) izadji = 1;
                        }

                        if(izadji) break;

                    }
                    //
                    if(izadji == 0) {

                        if(x * y > dimenzija1 * dimenzija2){

                            dimenzija1 = x;
                            dimenzija2 = y;
                            koord1 = i;
                            koord2 = j;

                        }

                    }

                }

            }

        }

    }

    printf("dimenzija:%dX%d, gornji levi ugao:%d,%d", dimenzija1, dimenzija2, koord1, koord2);

}

int main(){

    int n;

    scanf("%d", &n);

    int mat[SIZE][SIZE];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    pom(mat, n);

    return 0;
}