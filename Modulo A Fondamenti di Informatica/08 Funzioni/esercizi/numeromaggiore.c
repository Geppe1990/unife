// Si leggano da tastiera due numeri a e b
// Si stampi il maggiore dei due attraverso una funzione

#include <stdio.h>

int calcmax(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}

main() {
	int a,b, max;

	printf("Inserisci a e b: ");
	scanf("%d%d", &a, &b);

	max = calcmax(a, b);

	printf("Il numero maggiore tra %d e %d è %d\n", a, b, max);
}