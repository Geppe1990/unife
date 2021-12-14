// - Si scriva una procedura che calcola quoziente e resto di una divisione intera
// - Si scriva un main program che invochi la procedura per calcolare la divisione 5/2
// - Si mostri con i record di attivazione l'esecuzione del programma

#include <stdio.h>

void divisione(int a, int b, int *q, int *r) {
	*q = a / b;
	*r = a % b;
}

int main() {
	int x, y, q, r;
	x = 5;
	y = 2;
	divisione(x, y, &q, &r);

	printf("Quoziente: %d\n", q);
	printf("Resto: %d\n", r);
}