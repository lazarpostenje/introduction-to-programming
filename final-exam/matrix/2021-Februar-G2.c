#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/**
3 4 3 4 7
2 4 2 5 5
1 3 1 8 6
1 2 3 9 5

i < 6 - 4 + 1

**/

void pretrazi_sam(int *niz, int n, int m, int *izlaz) {
    int brojac = 0, max = 0;
    int prethodni = -1, index = 0;
    for (int i = 0; i < m*n; i++) {
         if (niz[i] > prethodni) brojac++;
         else{
            if (max < brojac) {
                max = brojac;
                index = i;
            }
            brojac = 1;
         }

        prethodni = niz[i];
    }
    izlaz[0] = max;
    izlaz[1] = index;
}

void pom(int mat[SIZE][SIZE], int n, int m) {
    int niz[SIZE], k = 0;
    /// JOT
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (int i = n-1; i >= 0; i--) {
                niz[k++] = mat[i][j];
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                niz[k++] = mat[i][j];
            }
        }

    }
    int izlaz[2];
    pretrazi_sam(niz, n, m, izlaz);
    int mini_brojac = 0;
    
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (int i = n-1; i >= 0; i--) {
                if (mini_brojac == (izlaz[1] - izlaz[0])) printf("(%d,%d), duljina %d", i, j, izlaz[0]);
               mini_brojac++;
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                if (mini_brojac == (izlaz[1] - izlaz[0])) printf("(%d,%d), duljina %d", i, j, izlaz[0]);
                mini_brojac++;
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

}