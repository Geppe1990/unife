// Si scriva un programma C che legge da tastiera un numero x e calcola tramite una funzione "quadratoperfetto" se x è un quadrato perfetto; nel caso che lo sia, il main deve stamparne anche la radice quadrata.

// La funzione:
// int quadratoperfetto(int x, int* rad)

// dato un numero x, fornisce:
// - tramite il valore di ritorno, 1 se x è un quadrato perfetto, 0 altrimenti;
// - qualora x sia un quadrato perfetto, la sua radice quadrata (rad).

// Consiglio: si può utilizzare la funzione sqrt della libreria math.
// Quadrati perfetti: 1 4 9 16 25 36 49 64 81 100 121 144

#include <stdio.h>
#include <math.h>

int quadratoperfetto(int x, int* rad) {
	int aux = (int)sqrt((double)x);
	if(pow(aux, 2) == x) {
		*rad = aux;
		return 1;
	}
	return 0;
}

int main() {
	int x, rad;
	x= 1;
	
	if(quadratoperfetto(x, &rad)) {
		printf("%d è un quadrato perfetto\n", x);
		printf("La sua radice è %d\n", rad);
	} else {
		printf("%d non è un quadrato perfetto\n", x);
	}
}