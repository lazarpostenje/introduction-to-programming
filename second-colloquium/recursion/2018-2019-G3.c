#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int fibonacci(int pozicija){
    if(pozicija == 1 || pozicija == 2) return 1;
    int prvi = 0, drugi = 1;
    int sledeci = prvi + drugi;
    for(int i = 1; i <= pozicija; i++){
        prvi = drugi;
        drugi = sledeci;
        sledeci = prvi + drugi;
    }
    return prvi;
}

double rek(int n, int x){
    if(n == 1) return 1;
    return sqrt(n * n + fibonacci(x) * rek(n - 1, x + 1));
}
double iter(int n, int x){
    double rez = 1;
    int brojilo = 2;
    for(int i = n - 2; i >= 0; i--){
        rez = sqrt(brojilo * brojilo + fibonacci(x) * rez);
        brojilo++;
        x--;
    }
    return rez;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lf", rek(n, 2));
    printf("\n%lf", iter(n, n));
    return 0;
}
