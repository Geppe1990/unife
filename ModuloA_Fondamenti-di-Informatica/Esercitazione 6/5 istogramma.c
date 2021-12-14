// Si scriva un programma che richieda in ingresso l'andamento annuale del 
// valore delle azioni (12 valori interi, uno per ogni mese) e inserisca i valori in un 
// vettore.
// Si stampi a video un istogramma orizzontale.

#include <stdio.h>
#define DIM 12

int main() {
	int a[DIM], i, j;

	for(i=0; i<DIM; i++) {
		printf("Inserisci valore %d: ", i);
		scanf("%d", &a[i]);
	}

	for(i=0; i<DIM; i++) {
		printf("%d ", i+1);
		for(j=1; j<=a[i]; j++) {
			printf("* ");
		}
		printf("(%d)", a[i]);
		printf("\n");
	}
}