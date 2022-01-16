#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define SIZE 40

int main() {

    int n;
    int mat[SIZE][SIZE];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            if(j - i - 1 > n / 2 - 1) mat[i][j] = -1;
            if(i - j - 1 > n / 2 - 1) mat[i][j] = -1;

            if(n % 2 == 0){

                if(i + j + 1< n / 2) mat[i][j] = -1;

            }
            else if(i + j < n / 2) mat[i][j] = -1;


            if(i + j + 1 > n / 2 + n) mat[i][j] = -1;
        }

    }

    for(int j = 0; j < n; j++){

        int min = 9;
        int max = 0;

        for(int i = 0; i < n; i++){

            if(mat[i][j] > -1 && mat[i][j] > max) max = mat[i][j];
            if(mat[i][j] > -1 && mat[i][j] < min) min = mat[i][j];

        }

        for(int i = 0; i < n; i++){

            if(mat[i][j] == -1 && i <= n / 2) mat[i][j] = max;
            else if(mat[i][j] == -1 && i > n / 2 ) mat[i][j] = min;

        }

    }

    putchar('\n');

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            printf("%d ", mat[i][j]);

        }

        putchar('\n');

    }

    return 0;
}
