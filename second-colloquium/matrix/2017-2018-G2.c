#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int reverse(int n) {

    int broj = 0;
    int brojac = 0;

    while (n) {

        int cifra = n % 10;

        broj = broj * 10 + cifra;

        n /= 10;

    }

    return broj;

}

int brojCifara(int n) {

    int brojilo = 0;

    while (n) {

        brojilo++;

        n /= 10;

    }

    return brojilo;

}

int main() {

	int n;

	scanf_s("%d", &n);

    int matrica[SIZE][SIZE];

    int reverseN = reverse(n);

    int reverseN2 = reverse(n);

    int pomocniNiz[SIZE];
    int pomocniNiz2[SIZE];

    int dimenzija = brojCifara(n);

    int i = 0;

    int flag = 0;

    while (reverseN) {

        int cifra = reverseN % 10;

        pomocniNiz[i] = cifra;

        i++;
        reverseN /= 10;

    }

    i = 0;

    while (reverseN2) {
    
        int cifra = reverseN2 % 10;

        pomocniNiz2[i] = cifra;

        i++;
        reverseN2 /= 10;
    
    }


    for (int i = 0; i < dimenzija; i++) {

        for (int j = 0; j < dimenzija; j++) {
        
            if (dimenzija % 2 != 0) {

                if (i == dimenzija / 2 || i == dimenzija / 2 + 1) matrica[i][j] = pomocniNiz[j];
                else if (i < dimenzija / 2) {
                
                    matrica[i][j] = 0;//iznad
                
                }
                else {

                    if (flag == 2) flag = 0;

                    if (flag == 0) { 
                        
                        pomocniNiz[j] -= 1; 
                        if (pomocniNiz[j] < 0) pomocniNiz[j] += 10;
                    
                    }
                    
                    

                    matrica[i][j] = pomocniNiz[j];

                    //ispod
                
                }
            
            }
            else if(dimenzija % 2 == 0) {
            
                if (i == dimenzija / 2) matrica[i][j] = pomocniNiz[j];
                else if (i == dimenzija / 2 - 1) matrica[i][j] = pomocniNiz[j];
                else {
                
                    if (i < dimenzija / 2) matrica[i][j] = 0;
                    else {
                    
                        if (flag == 2) flag = 0;

                        if (flag == 0) {

                            pomocniNiz[j] -= 1;
                            if (pomocniNiz[j] < 0) pomocniNiz[j] += 10;

                        }



                        matrica[i][j] = pomocniNiz[j];
                    
                    }
                
                }
            
            }
            
        
        }

        if (dimenzija % 2 == 0) {
        
            if (i > dimenzija / 2) flag++;
        
        }else {

            if (i > dimenzija / 2 + 1) flag++;

        }
    
    }

    flag = 0;


    for (int i = dimenzija - 1; i >= 0; i--) {

        for (int j = 0; j < dimenzija; j++) {

            if (dimenzija % 2 != 0) {

                //neparno

                if (i < dimenzija / 2) {
                
                //ovde pisi

                    if (flag == 2) flag = 0;

                        if (flag == 0) {

                            pomocniNiz2[j] += 1;
                            if (pomocniNiz2[j] >= 10) pomocniNiz2[j] -= 10;

                        }

                        matrica[i][j] = pomocniNiz2[j];
                
                }


            }
            else if (dimenzija % 2 == 0) {

                //parno

                if (i < dimenzija / 2 - 1) {
                
                    //ovde pisi

                    if (flag == 2) flag = 0;

                    if (flag == 0) {

                        pomocniNiz2[j] += 1;
                        if (pomocniNiz2[j] >= 10) pomocniNiz2[j] -= 10;

                    }

                    matrica[i][j] = pomocniNiz2[j];
                
                }

            }

        }

        if (dimenzija % 2 != 0) {
        
            if (i < dimenzija / 2) flag++;
        
        }
        else if (dimenzija % 2 == 0) {
        
            if (i < dimenzija / 2 - 1) flag++;
        
        }

    }

    /*
    for (int i = dimenzija - 1; i >= 0; i--) {

        for (int j = 0; j < dimenzija; j++) {

            printf("%d ", matrica[i][j]);

        }

        printf("\n");

    }
    */

   

    for (int i = 0; i < dimenzija; i++) {

        for (int j = 0; j < dimenzija; j++) {

            printf("%d ", matrica[i][j]);

        }

        printf("\n");

    }
    

	return 0;
}
