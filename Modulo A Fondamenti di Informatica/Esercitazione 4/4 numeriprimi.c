// Leggere un numero N da tastiera.
// Stampare tutti i numeri primi minori o uguali ad N.
// Un numero maggiore di 1 è primo se è divisibile solo per 1 e per se stesso
// 2, 3, 5, 7, 11, 13, 17, 19, 23
#include <stdio.h>

int main() {
	int N = 25, i, j, primo;

	for(i=1; i<=N; i++) {
		primo = 1;
		for(j=1; j<=N; j++)
			if(j!=1 && j!=i && i%j == 0)
				primo = 0;

		if(primo)
			printf("%d ", i);
	}

}