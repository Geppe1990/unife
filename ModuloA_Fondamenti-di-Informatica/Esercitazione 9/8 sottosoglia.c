// 1. Si scriva una procedura che, prendendo come parametri:
// - un array di numeri (interi)
// - una soglia (intero)
// - eventuali altri parametri
// ponga a 0 i valori inferiori alla soglia.

// 2. Si scriva un programma che:
// - legge da input, tramite una procedura o funzione, una sequenza di n interi terminata dal numero -1 e la memorizza in un array. Il valore -1 non va inserito nell’array. Il valore n è al massimo 100;
// - legge da tastiera il valore della soglia;
// - invoca la procedura al punto 1 passando l'array letto in input;
// - stampa a video, tramite una procedura, l'array modificato.

#include <stdio.h>
#define N 100

void azzerasoglia(int a[], int soglia, int L) {
	int i;
	for(i=0; i<L; i++) {
		if(a[i] < soglia) {
			a[i] = 0;
		}
	}
}

void popolaInteri(int interi[], int *L) {
	int n=0;
	do {
		printf("Inserisci un numero: ");
		scanf("%d", &n);
		if(n != -1) {
			interi[*L] = n;
			(*L)++;
		}
	}while(n != -1);
}

void printArray(int interi[], int *L) {
	int i;
	printf("Stampo l'array\n");
	for(i=0; i<*L; i++) {
		printf("%d ", interi[i]);
	}
	printf("\n");
}

int insertSoglia() {
	int soglia;
	printf("Inserisci la soglia: ");
	scanf("%d", &soglia);
	printf("La soglia è: %d\n", soglia);

	return soglia;
}

int main() {
	int interi[N];
	int L=0;
	int soglia = insertSoglia();

	popolaInteri(interi, &L);
	printArray(interi, &L);
	azzerasoglia(interi, soglia, L);
	printArray(interi, &L);
}