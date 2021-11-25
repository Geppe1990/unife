// Scrivere un programma che prende in ingresso da tastiera un numero N.
// Il programma deve poi calcolare la somma di una sequenza di interi 
//dati da tastiera. L'inserimento termina quando la somma è maggiore o uguale a N.
// Il programma deve stampare infine la somma calcolata e la differenza 
// tra questa e il numero N.

// CONSIGLIO: Non è necessario memorizzare tutti i numeri forniti, è sufficiente memorizzare la loro somma.

#include <stdio.h>

int main() {
	int N, somma = 0, n;
	printf("Inserisci N: ");
	scanf("%d", &N);

	do {
		printf("Somma un numero: ");
		scanf("%d", &n);
		somma += n;
	} while(somma < N);

	printf("N: %d\n", N);
	printf("Somma: %d\n", somma);
}