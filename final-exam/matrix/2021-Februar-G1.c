#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 100

int main(){

    int n;

    scanf("%d", &n);

    int mat[SIZE][SIZE];
    int novaMat[SIZE][SIZE];

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            scanf("%d", &mat[i][j]);

        }
    }

    int brojac = 0;
    int max;

    while(brojac <= n / 2 - 1){

        max = INT_MIN;

        for(int i = brojac; i < n - brojac; i++){

            for(int j = brojac; j < n - brojac; j++){

                if(i == brojac || (i != n - brojac - 1 && j == n - brojac - 1)){

                    if(mat[i][j] > max) max = mat[i][j];

                }
            }
        }

        for(int i = n - brojac - 1; i >= brojac; i--){

            for(int j = n - brojac - 1; j >= brojac; j--){

                if(i == n - brojac - 1 || (j == brojac && i != brojac)){

                    if(mat[i][j] > max) max = mat[i][j];

                }
            }
        }

        for(int i = brojac; i < n - brojac; i++){

            for(int j = brojac; j < n - brojac; j++){

                if(i == brojac || (i != n - brojac - 1 && j == n - brojac - 1)){

                    novaMat[i][j] = max;

                }
            }
        }

        for(int i = n - brojac - 1; i >= brojac; i--){

            for(int j = n - brojac - 1; j >= brojac; j--){

                if(i == n - brojac - 1 || (j == brojac && i != brojac)){

                    novaMat[i][j] = max;

                }
            }
        }

        brojac++;
    }

    printf("\n");

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            printf("%d ", novaMat[i][j]);

        }

        printf("\n");

    }

    return 0;
}