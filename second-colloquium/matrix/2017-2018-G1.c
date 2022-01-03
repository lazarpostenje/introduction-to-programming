#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int brojCifara(int n) {

	int brojilo = 0;

	while (n) {
	
		brojilo++;

		n /= 10;
	
	}

	return brojilo;

}

int reverse(int n) {

	int broj = 0;

	while (n) {
	
		int cifra = n % 10;

		broj = broj * 10 + cifra;

		n /= 10;
	
	}

	return broj;

}

int main() {

	int n;
	scanf_s("%d", &n);
	int matrica[SIZE][SIZE];

	int dimenzije = brojCifara(n);

	int pomocniNiz[SIZE];
	int pomocniNiz2[SIZE];

	int reverseN = reverse(n);
	int reverseN2 = reverse(n);

	int i = 0;
	int i2 = 0;

	int flag = 0;
	int flag2 = 0;

	while (reverseN) {
	
		int cifra = reverseN % 10;

		pomocniNiz[i] = cifra;

		i++;
		reverseN /= 10;
	
	}

	while (reverseN2) {

		int cifra = reverseN2 % 10;

		pomocniNiz2[i2] = cifra;

		i2++;
		reverseN2 /= 10;

	}

	for (int i = 0; i < dimenzije; i++) {
		for (int j = 0; j < dimenzije; j++) {

			if (j == dimenzije - i - 1) matrica[i][j] = pomocniNiz[i];
			else if (j > dimenzije - i - 1) {

				if (j == dimenzije - i && i != 0) matrica[i][j] = pomocniNiz[i];
				else {

					if (flag == 2) {

						flag = 0;

					}
					if (flag == 0) { 
						pomocniNiz[i] += 1; 

						if (pomocniNiz[i] >= 10) pomocniNiz[i] -= 10; 

					}
					matrica[i][j] = pomocniNiz[i];
					flag++;
				}
			}
			else matrica[i][j] = 0;
		}
		flag = 0;
	}

	for (int i = 0; i < dimenzije; i++) {
		for (int j = dimenzije - 1; j >= 0; j--) {

			if (j < dimenzije - i - 1) {

				if (flag2 == 2) {

					flag2 = 0;

				}
				if (flag2 == 0) {
					pomocniNiz2[i] -= 1;

					if (pomocniNiz2[i] < 0) pomocniNiz2[i] += 10;
				}
				matrica[i][j] = pomocniNiz2[i];
				flag2++;
			}
		}
		flag2 = 0;
	}

	for (int i = 0; i < dimenzije; i++) {
		for (int j = 0; j < dimenzije; j++) {

			printf("%d ", matrica[i][j]);

		}
		printf("\n");
	}

	return 0;
}