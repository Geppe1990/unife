// Leggere da tastiera base ed esponente e calcolare la potenza

#include <stdio.h>

main() {
	int base, esponente, risultato, i;
	base = 2;
	esponente = 5;
	risultato = 1;
	i = 0;
	
	while(i < esponente) {
		risultato = risultato * base;
		i++;
	}
	printf("%d\n", risultato);
}