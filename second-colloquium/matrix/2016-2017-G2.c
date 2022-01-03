#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int reverse(int n) {

    int broj = 0;

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

    int reverseN = reverse(n);

    int pomocniNiz[SIZE];

    int i = 0;

    while (reverseN) {
    
        int cifra = reverseN % 10;

        pomocniNiz[i] = cifra;

        i++;
        reverseN /= 10;
    
    }

    int matrica[SIZE][SIZE];


    for (int i = brojCifara(n) - 1; i >= 0; i--) {
    
        for (int j = 0; j < brojCifara(n); j++) {
        
            if (i == brojCifara(n) - 1) {
            
                matrica[i][j] = pomocniNiz[j];
            
            }
            else {
            
                if (i % 2 == 0) {
                
                    pomocniNiz[j] += 1;

                    if (pomocniNiz[j] >= 10) pomocniNiz[j] -= 10;

                    matrica[i][j] = pomocniNiz[j];
                
                }
                else {
                
                    pomocniNiz[j] += 2;

                    if (pomocniNiz[j] >= 10) pomocniNiz[j] -= 10;

                    matrica[i][j] = pomocniNiz[j];
                
                }
            
            }
        
        }
    
    }


    for (int i = 0; i < brojCifara(n); i++) {

        for (int j = 0; j < brojCifara(n); j++) {

            printf("%d ", matrica[i][j]);

        }

        printf("\n");

    }

    
    return 0;
}