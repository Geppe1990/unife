// Si scriva un programma C che legga da tastiera una sequenza di 10 numeri interi 
// e, al termine, stampi a video il numero dei numeri letti che sono
// maggiori di zero,
// minori di zero,
// uguali a 0.

#include <stdio.h>

int main() {
	int N = 10, i, num, positivi = 0, negativi = 0, zero = 0;

	for(i=0; i<N; i++) {
		printf("Inserisci il numero %d: ", i);
		scanf("%d", &num);

		if(num > 0)
			positivi++;
		else if(num < 0)
			negativi++;
		else
			zero++;
	}

	printf("Hai inserito %d uguali a 0\n", zero);
	printf("Hai inserito %d maggiori di 0\n", positivi);
	printf("Hai inserito %d minori di 0\n", negativi);

}