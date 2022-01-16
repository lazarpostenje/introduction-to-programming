#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define SIZE 40

int cudanBroj(int n){

    int rez = n;

    for(int i = 1; i < n; i++){

        rez += i;

    }

    return rez;

}

double rek(int n, int i, int donji, int kopija, int cudan_broj){

    if(i % 3 == 0) {

        donji = n;
        if(i != 0) {n -= 3; donji -= 3;}

    } else if(i % 3 == 1){

        donji = n * 10 + n - 1;

    } else if(i % 3 == 2){

        donji = n * 100 + (n - 1) * 10 + n - 2;

    }



    if(kopija == 1) return sqrt(1.0 * cudan_broj / donji);

    return sqrt(1.0 * cudan_broj / (1.0 * donji) + rek(n, i + 1, donji, kopija - 1, cudan_broj - kopija + 1));

}

double iter(int n){

    double rez = 0;

    if(n % 2 == 0) rez = n / 321.0;
    else rez = n / 1.0;

    int gornji = n;
    int donji = 1;
    int cifra_donji = 1;
    if(n % 2 != 0) cifra_donji++;

    for(int i = 1; i < n; i++){
        gornji += i;

        if(n % 2 == 0){

            if(3 - i % 3 == 3)  { if(i != 0) cifra_donji += 3; donji = 100 * (cifra_donji + 2) + 10 * (cifra_donji + 1) + cifra_donji;   }
            else if(3 - i % 3 == 2) donji = 10 * (cifra_donji + 2) + cifra_donji + 1;
            else if(3 - i % 3 == 1) donji = cifra_donji + 2;

        } else {

            if(4 - i % 3 == 3)  { if(i != 1) cifra_donji += 3; donji = 100 * (cifra_donji + 2) + 10 * (cifra_donji + 1) + cifra_donji;   }
            else if(4 - i % 3 == 2) donji = 10 * (cifra_donji + 2) + cifra_donji + 1;
            else if(4 - i % 3 == 4) donji = cifra_donji + 2;

        }

        rez = sqrt(rez) + 1.0 * gornji / donji;

    }
    return sqrt(rez);
}

int main() {

    int n;

    scanf("%d", &n);

    int cudan_broj = cudanBroj(n);

    printf("%lf\n", rek(n, 0, n, n, cudan_broj));
    printf("%lf\n", iter(n));

    return 0;
}
