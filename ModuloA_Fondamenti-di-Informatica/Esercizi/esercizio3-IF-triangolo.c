// Scrivere un programma che legga da tastiera le tre lunghezze dei lati di un triangolo (detti A, B e C) e determini se il triangolo è:
// - Equilatero -> 3 lati uguali
// - Isoscele -> 2 lati uguali
// - Scaleno -> tutti lati diversi
// - Rettangolo

#include <stdio.h>

main() {
	int a, b, c, pitagora;
	printf("Inserisci i 3 lati: ");
	scanf("%d %d %d", &a, &b, &c);

	if(a > b && a > c) {
		pitagora = (a * a) == ((b * b) + (c * c));
	}

	if(b > a && b > c) {
		pitagora = (b * b) == ((a * a) + (c * c));
	}

	if(c > a && c > b) {
		pitagora = (c * c) == ((a * a) + (b * b));
	}


	if(a==b) {
		if(b==c) {
			printf("EQUILATERO\n");
		} else {
			printf("SOSCELE\n");
		}
	} else {
		if(a==c || b == c) {
			printf("ISOSCELE\n");
		} else {
			printf("SCALENO\n");
		}
	}

	if(pitagora) {
		printf("RETTANGOLO");
	}
}