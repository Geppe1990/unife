// Si scriva un programma C che:
// - legge da tastiera, tramite una funzione int input(int array[]), un intero N (al massimo 100) e un array di N interi, e restituisce N;
// - calcola la somma degli elementi dell'array, tramite una funzione int somma(int array[], int n);
// - calcola la media degli elementi dell'array, tramite una funzione float media(int array[], int n);
// - calcola il numero degli elementi pari dell'array, tramite una funzione int conta_pari(int array[], int n);
// - infine, mostri a video i risultati ottenuti.

#include <stdio.h>

int input(int array[]) {
	int N, i;
	printf("Inserisci N: ");
	scanf("%d", &N);

	for(i=0; i<N; i++) {
		printf("Inserisci valore: ");
		scanf("%d", &array[i]);
	}

	return N;
}

int somma(int array[], int n) {
	int s=0, i;

	for(i=0; i<n; i++) {
		s += array[i];
	}

	return s;
}

float media(int array[], int n) {
	return (float)somma(array, n)/n;
}

int conta_pari(int array[], int n) {
	int p=0, i;

	for(i=0; i<n; i++) {
		if(array[i] % 2 == 0) {
			p++;
		}
	}

	return p;	
}

int main() {
	int arr[100];
	int N = input(arr);
	int i;
	
	int som = somma(arr, N);
	printf("La somma è %d\n", som);
	float med = media(arr, N);
	printf("La media è %f\n", med);
	int par = conta_pari(arr, N);
	printf("Ci sono %d numeri pari\n", par);
}