#include <stdio.h>
#include <stdlib.h>
#define SIZE 50



int main() {

    int n;
    scanf_s("%d", &n);
    int matrica[SIZE][SIZE];
    int transponat[SIZE][SIZE];
    int min = 10;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &matrica[i][j]);
            transponat[j][i] = matrica[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (matrica[i][k] < min) min = matrica[i][k];
                if (transponat[j][k] < min) min = transponat[j][k];
            }
            printf("%d", min); min = 10;
        }
        printf("\n");
    }

    return 0;
}