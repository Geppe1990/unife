// Si scriva un programma C che:

// - Legga una sequenza di 10 interi e la memorizzi in un array;
// - Chieda all'utente attraverso una funzione con l'interfaccia int ordine() 
// se vuole che la sequenza venga stampata nello stesso ordine di inserimento 
// o in ordine inverso, che legga la risposta 
// seguente: (char 's' per 'stesso', 'i' per 'inverso'); 
// qualora l'utente inserisca un carattere diverso da 's' e 'i', 
// la funzione deve chiedere nuovamente di inserire la risposta.
// - Stampi l'array nell'ordine richiesto. Il programma deve stampare a video 
// la sequenza fra simboli @ (chiocciola/a commerciale) come indicato nella figura 
// riportata di seguito. 
//I numeri all'interno della sequenza devono essere separati da uno, o più, spazi.

#include <stdio.h>
#define DIM 10

int ordine() {
	char scelta;
	int i;

	while(1) {
		printf("Stesso ordine di inserimento[s] o in ordine inverso[i]: ");
		scanf("\n%c", &scelta);

		if(scelta == 's')
			return 1;	
		else if(scelta == 'i')
			return 0;
		else
			printf("Scelta errata\n");
	}
}

void printReverseArray(int a[]) {
	int i;
	for(i=DIM-1; i>=0; i--)
		printf("%d ", a[i]);
}

void printArray(int a[], int ord) {
	int i;
	if(ord)
		for(i=0; i<DIM; i++)
			printf("%d ", a[i]);
	else
		printReverseArray(a);
}

int main() {
	int a[DIM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printArray(a, ordine());
}