/**
1 3 1 4 3 1
2 1 3 4 9 7
1 4 2 4 2 1
2 7 7 1 1 1
2 3 4 5 1 2
**/

#define SIZE 20

int proveri(int n, int *niz) {

    for (int i = 0; niz[i]; i++) {
        if (niz[i] == n) return 1;
    }
    return 0;
}

void ispisi(int mat[SIZE][SIZE], int n, int m, int *niz){
    int najduza_vrste = 0, najduza_kolone = 0, vrsta1 = -1, kolona1 = -1, vrsta2 = -1, kolona2 = -1;
    int tip = 0;
    int guci = -1, armani = -1;
    int brojac = 0;
    /// Po vrstama
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                if (proveri(mat[i][j], niz)) {
                    if (brojac == 0) {
                        guci = i;
                        armani = j;
                    }
                    brojac++;
                }
                else {
                    if (brojac > najduza_vrste) {
                        najduza_vrste = brojac;
                        vrsta1 = guci,
                        kolona1 = armani;
                    }
                    brojac = 0;
                }
            }
        }
        else {
            for (int j = m-1; j >= 0; j--) {
                if (proveri(mat[i][j], niz)) {
                    if (brojac == 0) {
                        guci = i;
                        armani = j;
                    }
                    brojac++;
                }
                else {
                    if (brojac > najduza_vrste) {
                        najduza_vrste = brojac;
                        vrsta1 = guci,
                        kolona1 = armani;
                    }
                    brojac = 0;
                }
            }
        }
    }
    brojac = 0;
    /// Po kolonama
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++) {
                if (proveri(mat[i][j], niz)) {
                    if (brojac == 0) {
                        guci = i;
                        armani = j;
                    }
                    brojac++;
                }
                else {
                    if (brojac > najduza_kolone) {
                        najduza_kolone = brojac;
                        vrsta2 = guci,
                        kolona2 = armani;
                    }
                    brojac = 0;
                }
            }
        }
        else {
            for (int i = n-1; i >= 0; i--) {
                if (proveri(mat[i][j], niz)) {
                    if (brojac == 0) {
                        guci = i;
                        armani = j;
                    }
                    brojac++;
                }
                else {
                    if (brojac > najduza_kolone) {
                        vrsta2 = guci,
                        kolona2 = armani;
                        najduza_kolone = brojac;
                    }
                    brojac = 0;
                }
            }
        }
    }
    if (najduza_kolone > najduza_vrste) {
        printf("(%d, %d) duzina %d, po kolonama ", vrsta2, kolona2, najduza_kolone);
    }
    else printf("(%d, %d) duzina %d, po vrstama ", vrsta1, kolona1, najduza_vrste);

}

int broj_cifara(int x) {
    int brojac = 0;
    while (x) {
        brojac++;
        x /= 10;
    }
    return brojac;
}

int main()
{
    int n, m, x, mat[SIZE][SIZE];
    scanf("%d %d %d", &n, &m, &x);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);
    }

    int niz[SIZE];
    int br = broj_cifara(x);
    for (int i = 0; i < br; i++) {
        niz[i] = x % 10;
        x /= 10;
    }
    ispisi(mat, n, m, niz);
    return 0;
}