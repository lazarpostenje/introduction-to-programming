#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rek(int n, int i, double manji, double veci, double gornji){
    if(i == n - 1){

        if(i % 2 != 0) return manji;
        else return veci;

    }

    if(i % 2 == 0){
        return veci+gornji/rek(n,i+1,manji+1,veci,gornji-2);
    }else {
        return manji+gornji/rek(n,i+1,manji,veci-1,gornji-2);
    }

}

double iter(int n, double manji, double veci, double gornji){
    gornji = 4;
    double res;
    veci = n/2+1;
    manji = n/2;
    if(n % 2 == 0) res = manji;
    else res = veci;

    for(int i = n - 2; i >= 0; i--){

        if(i % 2 == 0) {
        res = veci+gornji/res;
        manji--;
        }
        else{
        res = manji+gornji/res;
        veci++;
        }
        gornji += 2;
    }

    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lf\n", rek(n,0,0,n,2*n));
    printf("%lf", iter(n,n/2,n/2+1,2*n));

    return 0;
}
