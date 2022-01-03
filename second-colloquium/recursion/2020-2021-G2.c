#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rek(int n, int i, int prvi_veci, int drugi_veci, int manji){

    if(i == n - 1) return drugi_veci;

    if(i < n / 2) manji = manji - 1;
    else manji = manji + 1;

    if(i % 2 == 0) return prvi_veci + manji / rek(n, i + 1, prvi_veci, drugi_veci - 1, manji);
    else return drugi_veci + manji / rek(n, i + 1, prvi_veci + 1, drugi_veci, manji);
}

double iter(int n){

    int manji = n / 2;

    double rez;
    int drugi_veci, prvi_veci;

    if(n % 2 == 0){

        drugi_veci = 'A' + n / 2 + 1;
        prvi_veci = 'A' + n / 2 - 1;
        rez = drugi_veci;

    } else {

        drugi_veci = 'A' + n / 2 + 1;
        prvi_veci = 'A' + n / 2 - 1;
        rez = prvi_veci;
    }

    for(int i = n - 2; i >= 0; i--){

        if(n % 2 != 0){

            if(i % 2 != 0) {
                rez = drugi_veci + manji / rez;
                drugi_veci++;
            } else {
                rez = prvi_veci + manji / rez;
                prvi_veci--;
            }
            if(i > n / 2) manji--;
            else if(i < n / 2) manji++;

        } else {

            if(i % 2 != 0){
                rez = drugi_veci + manji / rez;
                drugi_veci++;
            } else {
                rez = prvi_veci + manji / rez;
                prvi_veci--;
            }

            if(i > n / 2 - 1) manji--;
            else manji++;
        }
    }

    return rez;
}

int main() {

    int n;

    scanf("%d", &n);

    printf("%lf\n", rek(n, 0, 'A', 'A' + n, n / 2 + 1));

    printf("%lf", iter(n));
    return 0;
}
