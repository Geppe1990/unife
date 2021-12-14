// Progettare e codificare in linguaggio C un programma che:
// - chiede all'utente di inserire un numero intero
// - stampa a video se il numero inserito dall'utente è: positivo, negativo o uguale a zero.

#include <stdio.h>

main() {
	int num;
	printf("Inserisci un numero: ");
	scanf("%d", &num);

	if(num == 0) {
		printf("Il numero è UGUALE a zero, %d\n", num);
	} else {
		if(num > 0) {
			printf("Il numero è MAGGIORE di zero, %d\n", num);
		} else {
			printf("Il numero è MINORE di zero, %d\n", num);
		}
	}
}