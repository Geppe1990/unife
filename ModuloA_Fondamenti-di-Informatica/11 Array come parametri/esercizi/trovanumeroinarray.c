// - Leggi da tastiera un array di interi, tramite una procedura.
// Il numero dei valori da inserire viene scelto dall'utente ed è al massimo 10
// - Legge da tastiera un intero x
// - Cerca l'elemento x nell'array tramite una funzione che fornisce
// 	-- la posizione dell'elemento
// 	-- -1 se l'elemento non è presente nell'array
// - Visualizza sullo schermo
// 	-- la posizione dell'elemento x se presente
// 	-- o "non esiste" se non è presente
#include <stdio.h>
#define MAXSIZE 10

void getNumbers(int *a, int size) {
	int i;	
	for(i=0; i<size; i++) {
		printf("Inserisci il numero %d: ", i);
		scanf("%d", &a[i]);
	}
}

int getSize() {
	int size;
	printf("Quanti valori vuoi inserire? (max 10): ");
	scanf("%d", &size);
	return size;
}

int getSearchNumber() {
	int n;
	printf("Quale numero vuoi cercare? ");
	scanf("%d", &n);

	return n;
}

int search(int *a, int size, int n) {
	int i, result = -1;

	for(i=0; i<size; i++) 
		if(n == a[i])
			result = i;
	
	return result;
}

int main() {
	int a[MAXSIZE], i, size, n, result;
	size = getSize();
	getNumbers(a, size);
	n = getSearchNumber();
	result = search(a, size, n);

	if(result >= 0) {
		printf("Hai cercato l'elemento %d, è presente all'indice %d\n", n, result);
	} else {
		printf("Non esiste");
	}
}
