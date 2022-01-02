#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>



double rek(int n, int i, double desni){

    if(i == n) return sqrt(i * desni);

    if(desni == 0) desni = 3;

    return sqrt(i * desni + rek(n, i + 1, desni - 1));

}

double iter(int n, double desni){

    int levi = n;
    double rez = sqrt(levi);

    for(int i = n - 1; i >= 1; i--){

        levi--;
        desni++;

        if(desni > 3) desni = 1;

        rez = sqrt(levi * desni + rez);

    }

    return rez;

}

int main() {

    int n;

    scanf("%d", &n);

    printf("%lf", rek(n, 1, n / 2));

    printf("\n%lf", iter(n,1));


    return 0;

}
