#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rek(int n, int i,double donji){

   if (i == n){

        return sqrt(2/donji);

   }


   if(i % 2 != 0){

    return sqrt(1/donji+rek(n,i+1,donji-1));
   }
   else{

        return sqrt(2/donji+rek(n,i+1,donji-1));
   }
}

double iterativno(int n){
    double donji = 1;
    double res = sqrt(2/donji);
    for(int i = n-1; i > 0;i--){
        donji++;
        if(i % 2 != 0) res = sqrt(1/donji+res);
        else res = sqrt(2/donji+res);

    }

    return res;
}



int main () {
    int n;
    scanf("%d", &n);
    printf("\n%lf", rek(n,1,n));

    printf("\n%lf", iterativno(n));

    return 0;
}
