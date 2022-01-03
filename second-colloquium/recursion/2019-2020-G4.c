#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rek(int n,double m, double v, int ite) {
    if(ite == n-1){
        if(ite %2 != 0 ){
            return m+pow(v,(ite%n/2)+1);
        }else {
            return pow(v,(ite%n/2)+1)+m;
        }
    }
    if(ite%2 == 0){
        return pow(v,ite%(n/2)+1)+m/rek(n, m+1,v-1,ite+1);
    }
    else {
        return m+pow(v,ite%(n/2)+1)/rek(n,m+1,v-1,ite+1);
    }

}

double iter(int n, double m, double v){

    double res = pow(v,n%(n/2)+1)+m;


    for (int i = n-1;i>=0;i--){
        if(i % 2 != 0){
            res = m+pow(v,i%(n/2)+1) /res;
        }else {
            res = pow(v,i%(n/2)+1)+m /res;
        }
        m--;
        v++;
    }

        return res;
}
int main() {

        int n;
        scanf("%d", &n);
        printf("%lf", iter(n,n,n));

    return 0;
}