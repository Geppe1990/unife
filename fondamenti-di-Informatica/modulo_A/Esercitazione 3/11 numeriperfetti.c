// Scrivere un programma in linguaggio C che stampi a video i numeri perfetti tra 1 e 10000.
// Un numero si dice perfetto se è uguale alla somma dei suoi divisori.

// Esempio: 
// 28 = 1 + 2 + 4 + 7 + 14
// 6 = 1 + 2 + 3

#include <stdio.h>

int main() {
	int i, j, limit = 10000;

	for(i=1; i<=limit; i++) {
		int perfetto = 0;
		for(j=1; j<=i; j++) {
			if(i%j == 0 && i!=j) {
				perfetto += j;
			}
		}
		if(perfetto == i) {
			printf("%d è perfetto\n", i);
		}
	}
}