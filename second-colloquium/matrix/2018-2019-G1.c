#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 50

int main() {

    int n;
    scanf("%d", &n);
    int matrica[n][n];
    int transponat[n][n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &matrica[i][j]);

    for(int i = 0; i < n; i++){

        int max = INT_MIN;
        int maxPonavaljanjeElement = INT_MIN;
        int j = 0;

        for(j = 0; j < n; j++)// nalazenje max vrednosti elementa
            if(matrica[i][j] % 2 != 0 && matrica[i][j] > max) max = matrica[i][j];

        if(max == INT_MIN) continue;

        int mapa[max + 1]; // pravimo mapu

        for(int k = 0; k < max + 1; k++)// popunjavamo mapu sa nulama
            mapa[k] = 0;

        for(int l = 0; l < n; l++) //popunjavamo mapu
            if(matrica[i][l] % 2 != 0) mapa[matrica[i][l]]++;

        for(int m = 0;  m < max + 1; m++)
            maxPonavaljanjeElement = mapa[max];

        printf("Red %d: %d %d \n", i + 1, max, maxPonavaljanjeElement);
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            transponat[j][i] = matrica[i][j];

    for(int i = 0; i < n; i++){

        int min = INT_MAX;
        int minPonavaljanjeElement = INT_MAX;
        int j = 0;

        for(j = 0; j < n; j++)// nalazenje min vrednosti elementa
            if(transponat[i][j] % 2 == 0 && transponat[i][j] < min && transponat[i][j] != 0) min = transponat[i][j];

        if(min == INT_MAX) continue;

        int mapa[min + 1]; // pravimo mapu

        for(int k = 0; k < min + 1; k++)// popunjavamo mapu sa nulama
            mapa[k] = 0;

        for(int l = 0; l < n; l++) //popunjavamo mapu
            if(transponat[i][l] % 2 == 0) mapa[transponat[i][l]]++;

        for(int m = 0;  m < min + 1; m++)
            minPonavaljanjeElement = mapa[min];

        printf("Kolona %d: %d %d \n", i + 1, min, minPonavaljanjeElement);
    }
    return 0;
}