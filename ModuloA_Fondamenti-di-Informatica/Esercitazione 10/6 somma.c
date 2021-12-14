// Scrivere un programma in C per calcolare la somma tra due matrici.

// Il programma deve inizialmente leggere da tastiera le due matrici, tramite una funzione da invocare due volte (una per ogni matrice).
// La funzione di lettura deve chiedere all’utente le dimensioni di una matrice (numero di righe e colonne) e deve poi fargli inserire i valori. Si supponga che le matrici abbiano dimensione massima 20 x 20.
// Se non sono verificate le condizioni per la somma il programma deve stampare un messaggio di errore.
// Se invece sono verificate, il programma calcola la somma (tramite una funzione) e la stampa a video (tramite una funzione).

/*			2 0	   4 -2	   6 -2 
	A+B		1 5	+ -2  2 = -1  7
			0 3	   0 -1	   0  2
*/

#include <stdio.h>
#include <string.h>

void somma(int A[][20], int B[][20], int C[][20], int *AN1, int *AN2) {
	int i, j;
	for(i=0; i<*AN1; i++)
		for(j=0; j<*AN2; j++)
			C[i][j] = A[i][j] + B[i][j];
}

void lettura(int m[20][20], int *n1, int *n2) {
	printf("N righe: ");
	scanf("%d", n1);
	printf("N colonne: ");
	scanf("%d", n2);
	int i, j;

	for(i=0; i<*n1; i++) {
		for(j=0; j<*n2; j++) {
			printf("Riga: %d, colonna: %d: ", i, j);
			scanf("%d", &m[i][j]);
		}
	}
}

void stampa(int C[][20], int *AN1, int *AN2) {
	int i, j;
	for(i=0; i<*AN1; i++) {
		for(j=0; j<*AN2; j++) {
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int A[20][20];
	int B[20][20];
	int C[20][20];
	int AN1 = 0;
	int AN2 = 0;
	int BN1 = 0;
	int BN2 = 0;
	int i, j;
	lettura(A, &AN1, &AN2);
	lettura(B, &BN1, &BN2);
	
	printf("\n");
	if(AN1 == BN1 && AN2 == BN2) {
		somma(A, B, C, &AN1, &AN2);
		stampa(C, &AN1, &AN2);
	}
}