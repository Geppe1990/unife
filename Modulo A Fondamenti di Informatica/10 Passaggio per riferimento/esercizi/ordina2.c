// - Si scriva una procedura ordina2 con due parametri a e b
// - Se a>b scambia il valore di a e di b, usando la procedura scambia

#include <stdio.h>

void scambia(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void scambia2(int *a, int *b) {
	if(*a > *b) {
		scambia(a, b);
	}
}

int main() {
	int x, y;
	x = 2;
	y = 1;
	scambia2(&x, &y);
	printf("x: %d\n", x);
	printf("y: %d\n", y);
}