#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int prostBroj(int pozicija){

    int brojilo = 0, i = 2, deljiv = 0;

    while(1){

        for(int j = 2; j < i; j++){

            if(i % j == 0) deljiv = 1;

        }

        if(deljiv == 0) brojilo++;

        deljiv = 0;

        if(pozicija == brojilo) return i;

        i++;

    }
}

double rek(int n, int i, int x, int slovo){

    if(i == n) return slovo;

    if(i % 2 == 0) return slovo - prostBroj(x) / rek(n, i + 1, x + 1, slovo - 1);
    else return slovo + prostBroj(x) / rek(n, i + 1, x + 1, slovo - 1);

}

double iter(int n, int x, int slovo){

    double rez = slovo;

    for(int i = n - 1; i >= 1; i--){

        slovo++;

        if(i % 2 == 0) rez = slovo - prostBroj(x) / rez;
        else rez = slovo + prostBroj(x) / rez;

        x--;
    }

    return rez;
}

int main() {

    int n;

    scanf("%d", &n);

    printf("%lf", rek(n, 1, 1, 'A' + n - 1));

    printf("\n%lf", iter(n, n - 1, 'A'));

    return 0;

}
