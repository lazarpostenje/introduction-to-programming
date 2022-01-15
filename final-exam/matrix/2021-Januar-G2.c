#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

/**
1 3 1 4 3 1
2 1 3 4 9 7
1 4 2 4 2 1
2 7 7 1 1 1
2 3 4 5 1 2

i < 6 - 4 + 1

**/

void pom(int mat[SIZE][SIZE], int n, int m){

    for(int x = 2; x <= n; x++){

        for(int i = 0; i < n - x + 1; i++){

            for(int j = 0; j < m - x + 1; j++){

                int limiter= 1;

                int parni = 0, neparni = 0;

                int izlaz = 0;

                for(int p = i; p < x + i; p++){

                    int brojac = 0;

                    for(int q = j; q < x + j; q++){

                        if (brojac == limiter) break;

                        if(mat[p][q] % 2 == 0) parni++;
                        else neparni++;

                        brojac++;

                    }

                    limiter++;

                }

               if(parni >= neparni){

                    printf("(%d,%d) - %d\n", i + x - 1, j, x);

               }

            }

        }

    }

}

int main(){

    int n, m;

    scanf("%d %d", &n, &m);

    int mat[SIZE][SIZE];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);

    pom(mat, n, m);

    return 0;

}