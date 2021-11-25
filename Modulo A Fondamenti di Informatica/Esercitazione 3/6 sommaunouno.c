// Scrivere un programma C che calcoli la somma di due numeri interi tramite i 
// cicli iterativi utilizzando solo l’operazione di incremento (operatore ++), 
// supponendo quindi di non avere a disposizione l’operatore di somma.
// Si usi il tipo di ciclo ritenuto più adeguato.

#include <stdio.h>

int main() {
	int x, y, i;
	printf("Inserisci il valore di x: ");
	scanf("%d", &x);
	printf("Inserisci il valore di y: ");
	scanf("%d", &y);
	int somma = x;

	for(i=0; i<y; i++) {
		somma++;
	}

	printf("somma: %d\n", somma);
}