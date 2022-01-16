#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#define SIZE 50

/**


**/

int fib(int n) {
    int prvi = 0, drugi = 1, sledeci;
    if (n == 1 || n == 2) return 1;
    for (int i = 1; i < n; i++) {
        sledeci = prvi + drugi;
        prvi = drugi;
        drugi = sledeci;
    }
    return sledeci;
}

double rek(int n, int i) {
    if (n == 0) return 0;
    return sqrt(fib(i+1)/(2*n*pow(10, n-1)) + rek(n-1, i+1));
}

double iter(int n) {
    int gornji = n;
    int donji = 2;

    double rez = 1.0*fib(gornji)/donji;
    gornji--; donji+=2;

    for (int i = 1; i < n; i++) {

        rez = sqrt(rez) + fib(gornji)/(donji * pow(10, i));
        printf("%d %d %lf\n", fib(gornji), donji ,donji * pow(10, i));
        gornji--;
        donji += 2;
    }

    return sqrt(rez);
}

int main(){

    int n;
    scanf("%d", &n);
    printf("%lf\n", rek(n, 0));
    printf("%lf\n", iter(n));
}