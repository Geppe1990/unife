// Si scriva un programma C che:
// - Legga da tastiera DIM elementi interi e li inserisca in un array;
// - Stampi a video, per ogni elemento del vettore, quante volte esso compare 
// all'interno del vettore

#include <stdio.h>
#define DIM 10

int main() {

	int i, j; /*INDICI*/
	int numeri[DIM], utilizzato[DIM]; /*ARRAY*/
	int count = 0;

	printf("Inserisci DIM elementi interi:\n");

	/*INIZIALIZZO L'ARRAY*/
	for (i = 0; i < DIM; i++) {

		printf("Elemento %d: ", i + 1);
		scanf("%d", &numeri[i]);
	}

	/*INIZIALIZZO L'ARRAY DEI NUMERI UTILIZZATI*/
	for (i = 0; i < DIM; i++) {

		utilizzato[i] = 0;
	}

	/*SCANSIONO TUTTO L'ARRAY*/
	for (i = 0; i < DIM; i++) {

		/*SE IL K-ESIMO NUMERO NON L'HO UTILIZZATO CONTO QUANTE VOLTE E' PRESENTE*/
		if (utilizzato[i] == 0) {

			for (j = i; j < DIM; j++) {
				if (numeri[j] == numeri[i]) {

					count++;
					utilizzato[j] = 1;
				}
			}

			printf("Elemento %d compare %d volte\n", numeri[i], count);
		}
		count = 0;
	}
}