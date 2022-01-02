#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rek(int n, double m, double v, int i){
    if(i == n - 1 ){
        if(i % 2 != 0){
            return sqrt(v/pow(m,2));
        }else {
            return sqrt(m/pow(v,2));
        }
    }
    if(i % 2 == 0){
        return sqrt(m/pow(v,2)+ rek(n, m, v, i+1));
    }else {
        return sqrt(v/pow(m,2)+ rek(n, m+1, v-1, i+1));
    }

}


int main() {

        int n;
        scanf("%d", &n);
        printf("%lf", rek(n,1,n,0));

    return 0;
}