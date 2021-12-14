// Si legga da tastiera un array di 10 elementi di tipo int.
// Si legga da tastiera un intero x.
// Si cerchi se esiste l'elemento x nell'array: 
// se è presente si visualizzino tutti gli indici in cui 
// l'elemento compare, altrimenti si informi l'utente che l'elemento non è presente.

#include <stdio.h>
#define DIM 10
int main() {
	int a[DIM], i, x, presente = 0;

	for(i=0; i<DIM; i++) {
		printf("Inserisci il valore %d: ", i);
		scanf("%d", &a[i]);
	}

	printf("Inserisci x: ");
	scanf("%d", &x);

	printf("X compare ai seguenti indici: ");
	for(i=0; i<DIM; i++) {
		if(a[i] == x) {
			presente = 1;
			printf("%d ", i);
		}
	}
	if(!presente) {
		printf("Elemento non presente\n");
	}

}