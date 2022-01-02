#include <stdio.h>
#include <stdlib.h>

double rek(int n, int i, int manji, int veci) {
    if (i == n - 1) {
        if (i % 2 == 0) return sqrt(pow(veci, i % (n / 2) + 1) / manji);
        else return sqrt(manji / pow(veci, i % (n / 2) + 1));
    }
    if (i % 2 == 0) return sqrt(pow(veci, i % (n / 2) + 1) / manji + rek(n, i + 1, manji - 1, veci - 1));
    if (i % 2 == 1) return sqrt(manji / pow(veci, i % (n / 2) + 1) + rek(n, i + 1, manji - 1, veci - 1));
}

double iter(int n, int veci, int manji) {
    double rez;
    int i = n - 1;
    if (n % 2 == 0) {
        rez = manji / pow(veci, i % (n / 2) + 1);
    }
    else {
        rez = pow(veci, i % (n / 2) + 1) / manji;
    }
    for (int k = n - 2; k >= 0; k--) {
        manji++;
        veci++;
        if (k % 2 == 0) {
            rez = pow(veci, k % (n / 2) + 1) / manji + sqrt(rez);
        }
        else {
            rez = manji / pow(veci, k % (n / 2) + 1) + sqrt(rez);
        }
    }
    return sqrt(rez);
}

int main() {

    int n;
    scanf("%d", &n);
    printf("%lf", rek(n, 0, n, 2 * n - 1));
    printf("\n%lf", iter(n, n, 1));
    return 0;
}
