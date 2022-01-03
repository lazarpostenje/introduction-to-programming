#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int main() {

    int n;
    scanf_s("%d", &n);
    int matrica[SIZE][SIZE];
    int rezultat[SIZE][SIZE];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            scanf_s("%d", &matrica[i][j]);
            
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (j == 0) rezultat[i][j] = matrica[i][j + 1];
            else if (j == n - 1) rezultat[i][j] = matrica[i][j - 1];
            else {
            
                rezultat[i][j] = matrica[i][j + 1] + matrica[i][j - 1];
            
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            printf("%d ", rezultat[i][j]);

        }
        printf("\n");
    }

    return 0;
}