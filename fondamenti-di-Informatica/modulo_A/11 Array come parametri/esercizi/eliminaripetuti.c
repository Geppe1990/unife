// Dato un array di interi, si scriva una procedura che elimina eventuali elementi ripetuti
// Si scriva poi un programma (organizzato in funzioni) che:
// 	- legge da tastiera un array di interi, di lunghezza scelta dall'utente (max 10)
// 	- elimina eventuali elementi ripetuti
// 	- visualizza l'array privo di elementi ripetuti

#include <stdio.h>

void eliminaRipetizioni(int *a, int *size) {
	int i, j;
	for(i=0; i<*size; i++) {
		for(j=0; j<*size; j++) {
			if(i != j) {
				if(a[i] == a[j]) {
					a[j] = a[*size-1];
					*size = *size-1;
				}
			}
		}
	}
}

void getData(int *a, int size) {
	for(int i=0; i<size; i++) {
		printf("Inserisci l'elemento %d: ", i);
		scanf("%d", &a[i]);
	}
}

void getSize(int *size) {
	printf("Quanti valori vuoi inserire? ");
	scanf("%d", size);
}

void printArray(int *a, int size) {
	for(int i=0; i<size; i++) {
		printf("%d\n", a[i]);
	}
}

int main() {
	int a[10], size;
	getSize(&size);
	getData(a, size);
	eliminaRipetizioni(a, &size);
	printArray(a, size);
}