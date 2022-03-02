// Progettare e codificare in linguaggio C un programma che:
// - chiede all'utente di immettere da tastiera tre numeri interi (int)
// - stampa il massimo tra i 3 numeri.

#include <stdio.h>

main() {
	int a, b, c;

	printf("Inserisci 3 numeri: ");
	scanf("%d %d %d", &a, &b, &c);

	if(a > b) {
		if(a > c) {
			printf("A è il maggiore: %d\n", a);
		} else {
			printf("C è il maggiore: %d\n", c);
		}
	} else {
		if(b > c) {
			printf("B è il maggiore: %d\n", b);
		} else {
			printf("C è il maggiore: %d\n", c);
		}
	}
}