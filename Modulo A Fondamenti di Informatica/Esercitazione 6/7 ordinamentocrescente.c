// Si scriva un programma C che:
// - Legga da tastiera 10 elementi interi e li inserisca in un vettore di 
// dimensione opportuna;
// - Verifichi se la sequenza è ordinata in ordine strettamente crescente e 
// stampi a video il risultato

#include <stdio.h>
#define DIM 10

int main() {
	int A[DIM] = {-2, 0, 2, 5, 8, 9, 13, 18, 50, 50};
	int i;
	int ordinato = 1;
	
	for(i=1; i<DIM && ordinato == 1; i++) {
		if(A[i] <= A[i-1]){
			ordinato = 0;
		}
	}

	if(ordinato)
		printf("Il vettore è ordinato in senso strettamente crescente\n");
	else
		printf("Il vettore NON è ordinato in senso strettamente crescente\n");
}