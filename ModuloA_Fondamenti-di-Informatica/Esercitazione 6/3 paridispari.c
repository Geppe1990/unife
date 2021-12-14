// Si scriva un programma C che:
// - Legga da tastiera 10 elementi interi e li inserisca in un array opportuno
// - Stampi il numero di elementi pari e e quello di elementi dispari presenti nel vettore.

#include <stdio.h>
#define DIM 10

int main() {
	int v[DIM];
	int pari = 0, dispari = 0, i;

	for(i=0; i<DIM; i++) {
		printf("Inserisci il numero %d: ", i);
		scanf("%d", &v[i]);
		if(v[i] % 2 == 0)
			pari++;
		else
			dispari++;
	}
	printf("Sono presenti %d numeri pari e %d numeri dispari\n", pari, dispari);
}