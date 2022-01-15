#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/**
Za zadatu matricu velicine n*n i vrednost k, obrnuti svaki prsten matrice u
smeru kazaljke na satu za k puta.
Ulaz: Ulaz:
6 8 Izlaz:                    4 2 Izlaz:
3 2 6 4 5 8    4 2 3 4 9 0    8 1 7 5   7 8 8 1
7 4 3 2 7 1    3 2 9 4 9 0    8 7 4 6   0 4 4 7
0 5 6 9 2 3    2 7 6 9 2 7    7 4 4 9   1 4 7 5
0 7 9 4 9 4    9 2 9 4 2 3    0 1 3 7   3 7 9 6
9 2 2 9 4 9    4 3 4 5 7 2
4 3 2 4 3 2    3 1 8 5 4 6
**/

#define SIZE 20

void siftuj(int *niz, int k, int n) {
    while (k) {
        for (int i = n-1; i > 0; i--) {
            int temp = niz[i];
            niz[i] = niz[i-1];
            niz[i-1] = temp;
        }
        k--;
    }
}

int main() {

    int n, k, mat[SIZE][SIZE], niz[SIZE];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
    }

    int brojac = 0;

    while (brojac <= n/2 - 1) {
        /// Prva polovina
        int dim = 0;
        for (int i = brojac; i < n-brojac; i++) {
            for (int j = brojac; j < n-brojac; j++)
                if (i == brojac || (j == n-1-brojac && i != n-1-brojac)) {
                    niz[dim++] = mat[i][j];
                }
        }
        /// Druga polovina
        for (int i = n-1-brojac; i >= brojac; i--) {
            for (int j = n-1-brojac; j >= brojac; j--)
                if (i == n-1-brojac || (j == brojac && i != brojac)) {
                    niz[dim++] = mat[i][j];
                }
        }

        siftuj(niz, k, dim);
        dim = 0;
        /// Prva polovina
        for (int i = brojac; i < n-brojac; i++) {
            for (int j = brojac; j < n-brojac; j++)
                if (i == brojac || (j == n-1-brojac && i != n-1-brojac)) {
                    mat[i][j] = niz[dim++];
                }
        }
        /// Druga polovina
        for (int i = n-1-brojac; i >= brojac; i--) {
            for (int j = n-1-brojac; j >= brojac; j--)
                if (i == n-1-brojac || (j == brojac && i != brojac)) {
                    mat[i][j] = niz[dim++];
                }
        }

        brojac++;
    }
    printf("\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}
