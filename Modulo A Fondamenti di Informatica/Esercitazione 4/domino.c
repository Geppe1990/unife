// Scrivere un programma che visualizzi tutte le tessere del domino, 
// ciascuna esattamente una volta.

// Ciascuna tessera contiene due numeri, ciascuno dei numeri è un intero da 0 a 6. 
// Si noti che le tessere sono tutte diverse fra loro: non ci sono due 
// tessere uguali (nemmeno ruotando le tessere). 
// Ad esempio, non si dovrà stampare sia la tessera [3|4] sia la [4|3], 
// perché ruotando la prima si ottiene la seconda; va invece mostrata la tessera [4|4] 
// (solo una volta, ovviamente).
// 0|0 1|0 NO! 2|0 NO!	3|0 NO! 4|0 NO! 5|0 NO! 6|0 NO! 
// 0|1 1|1 	2|1 NO! 3|1 NO! 4|1 NO! 5|1 NO! 6|1 NO! 
// 0|2 1|2 	2|2 	3|2 NO! 4|2 NO! 5|2 NO! 6|2 NO! 
// 0|3 1|3 	2|3 	3|3 	4|3 NO! 5|3 NO! 6|3 NO! 
// 0|4 1|4 	2|4 	3|4 	4|4 	5|4 NO! 6|4 NO! 
// 0|5 1|5 	2|5 	3|5 	4|5 	5|5 NO! 6|5 NO! 
// 0|6 1|6 	2|6 	3|6 	4|6 	5|6 	6|6

#include <stdio.h>

int main() {
	int i,j;
	for(i=0; i<=6; i++) {
		for(j=i; j<=6; j++) {
			printf("%d|%d\n", i, j);
		}
	}
}