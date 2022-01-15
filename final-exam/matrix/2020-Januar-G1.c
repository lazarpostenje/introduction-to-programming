#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void pom(int mat[SIZE][SIZE], int n){

    int dimenzija = 0;

    int koord1 = -1, koord2 = -1;//i j

    for(int x = 2; x <= n; x++){

        for(int i = 0; i < n - x + 1; i++){

            for(int j = 0; j < n - x + 1; j++){

                int kec = 0;
                int nula = 0;
                int izadji = 0;

                for(int p = i; p < x + i; p++){

                    for(int q = j; q < x + j; q++){

                        if(mat[p][q] == 1) kec = 1;
                        else nula = 1;

                        if(kec && nula) izadji = 1;

                    }

                    if(izadji) break;

                }

                if(izadji == 0) {

                    if(x > dimenzija) {

                        dimenzija = x;
                        koord1 = i;
                        koord2 = j;

                    }

                }

            }

        }

    }

    if(koord1 == -1) {printf("Ne postoji"); return;}

    printf("dimenzija:%dx%d, gornji levi ugao: %d,%d", dimenzija,dimenzija, koord1, koord2);

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