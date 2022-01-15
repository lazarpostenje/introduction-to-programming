#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

void pom(int mat[SIZE][SIZE], int d, int n, int m){

    int brojac = 0;
    char output[SIZE] = "";

    for(int i = 0; i < d - n + 1; i++){

        for(int j = 0; j < d - m + 1; j++){

            int kec = 0;
            int nula = 0;
            int izadji = 0;

            for(int p = i; p < i + n; p++){

                for(int q = j; q < j + m; q++){

                    if(mat[p][q] == 1) kec = 1;
                    else nula = 1;

                    if(kec && nula) izadji = 1;

                }

                if(izadji) break;

            }

            if(izadji == 0){

                char ch[2];

                brojac++;
                strcat(output, " (");
                itoa(i, ch, 10);
                strcat(output, ch);
                itoa(j, ch, 10);
                strcat(output, ",");
                strcat(output, ch);
                strcat(output, ")");

            }

        }

    }

    printf("%d,%s", brojac, output);

}

int main(){

    int d, n, m;

    scanf("%d %d %d", &d, &n, &m);

    int mat[SIZE][SIZE];

    printf("\n");

    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
            scanf("%d", &mat[i][j]);

    pom(mat, d, n, m);

    return 0;
}