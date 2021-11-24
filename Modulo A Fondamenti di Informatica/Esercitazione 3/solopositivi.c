// Scrivere un programma in linguaggio C che prenda in ingresso 
// una sequenza di numeri interi positivi e negativi, terminata da zero. 
// Quando l'utente inserisce lo zero il programma deve stampare a video la somma 
// di tutti i numeri positivi (int) e la loro media (float).

// CONSIGLIO: Non è necessario memorizzare tutti i numeri positivi, 
// è sufficiente memorizzare la loro somma.

#include <stdio.h>

int main() {
	int positivi = 0, n, i = 0, j = 0;
	float media = 0;

	do {
		printf("Inserisci un numero: ");
		scanf("%d", &n);

		if(n > 0) {
			positivi += n;
			i++;
		}
		if(n != 0)
			j++;
	} while(n != 0);

	media = (float)positivi / i;

	printf("In totale hai inserito %d numeri\n", j);
	printf("Hai inserito %d numeri positivi\n", i);
	printf("La somma dei positivi è: %d\n", positivi);
	printf("La loro media è: %f\n", media);
}