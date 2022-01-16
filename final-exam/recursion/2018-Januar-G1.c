#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define SIZE 40

int fib(int n){

    int prvi = 0, drugi = 1, sledeci;

    if(n == 1 || n == 2) return 1;

    for(int i = 1; i < n; i++){

        sledeci = prvi + drugi;
        prvi = drugi;
        drugi = sledeci;

    }

    return sledeci;

}

double rek(int n, int i){

    if(n == 1) return fib(i+1);
    return fib(i + 1) + n * 2 * pow(10, i) / rek(n-1, i+1);

}

double iter(int n){

    double rez = fib(n);

    int placeholder = n;

    n--;

    int gornji = 4;

    for(int i = 1; i < placeholder; i++){

        rez = fib(n) + gornji * pow(10, n - 1) / rez;

        gornji += 2;
        n--;
    }

    return rez;

}

int main() {

    int n;

    scanf("%d", &n);

    printf("%lf\n", rek(n, 0));
    printf("%lf\n", iter(n));

    return 0;
}
