// Si scriva un programma in C che legge N numeri interi da tastiera e 
// li memorizza in un vettore di ingresso.
// Il numero N viene inserito dall'utente ed è strettamente minore di 20.

// Il programma deve generare un vettore di uscita che "compatta" i numeri 
// contenuti nel vettore di ingresso.
// In particolare:
// - Ogni numero che compare ripetuto nel vettore di ingresso deve comparire 
// una sola volta nel vettore di uscita.
// - Ogni numero uguale a zero presente nel vettore di ingresso non deve comparire 
// nel vettore di uscita.

// Al termine, il programma deve stampare a video il contenuto del vettore di uscita.

#include <stdio.h>
#define DIM 19

int main() {
	int l = 9;
	int A[DIM] = {1, 18, 3, 0, 24, 3, 6, 6, 6};
	int B[DIM];
	int i, j;
	int l2 = 0;

	/*
		PRENDO I DATI IN INPUT
	*/
	// printf("Quanti numeri vuoi inserire? ");
	// scanf("%d", &l);
	// printf("Inserisci %d numeri: ", l);
	// for(i=0; i<l; i++) {
	// 	scanf("%d", &A[i]);
	// }

	/*
		COMPATTO L'ARRAY
	*/
	printf("Array originale: ");
	for(i=0; i<l; i++) {
		
		printf("%d ", A[i]);
		int occorrenze = 0;
		for(j=0; j<l2; j++) {
			if(i != j && A[i] == B[j]) {
				occorrenze++;
			}
		}
		if(A[i] != 0 && occorrenze == 0) {
			B[l2] = A[i];
			l2++;
		}
	}
	printf("\n");

	/*
		STAMPO L'ARRAY COMPATTATO
	*/
	printf("Array compattato: ");
	for(i=0; i<l2; i++) {
		printf("%d ", B[i]);
	}
	printf("\n");
}