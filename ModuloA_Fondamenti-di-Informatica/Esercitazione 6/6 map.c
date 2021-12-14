// Si scriva una funzione con interfaccia
// float soglia(float x, float inf, float sup)
// che fornisce
// - il valore di x, se x è compreso fra inf e sup
// - il valore inf, se x e` minore di inf
// - il valore sup, se x e` maggiore di sup

// Si scriva poi un programma C che
// - legge da tastiera un array A di 10 float
// - legge da tastiera due numeri inf e sup
// - costruisce un secondo array B, in cui ogni elemento e` 
// ottenuto applicando la funzione soglia al corrispondente elemento dell'array A
// - visualizza sullo schermo l'array B

#include <stdio.h>
#define DIM 10

float soglia(float x, float inf, float sup) {
	float risultato;
	if(sup >= x && x >= inf) {
		risultato = x;
	} else if(x < inf) {
		risultato = inf;
	} else if(x > sup) {
		risultato = sup;
	}
	return risultato;
}

int main() {
	float A[DIM];
	float B[DIM];
	float sup, inf;
	int i;

	for(i=0; i<DIM; i++) {
		printf("Inserisci elemento: ");
		scanf("%f", &A[i]);
	}

	printf("Inserisci sup: ");
	scanf("%f", &sup);
	printf("Inserisci inf: ");
	scanf("%f", &inf);

	for(i=0; i<DIM; i++) {
		B[i] = soglia(A[i], inf, sup);
	}

	for(i=0; i<DIM; i++) {
		printf("%.2f ", B[i]);
	}
}