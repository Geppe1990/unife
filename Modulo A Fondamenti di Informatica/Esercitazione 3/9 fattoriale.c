// Scrivere un programma C che, dato un numero intero N, calcoli il fattoriale di 
// tutti i numeri interi minori o uguali a N. Si usi il tipo di ciclo ritenuto più adeguato.

// NOTA: il fattoriale di N è il risultato della moltiplicazione di tutti gli interi 
// compresi fra 1 e N.
// Esempio: 3! (3 fattoriale) = 1 * 2 * 3 = 6

#include <stdio.h>

int main() {
	int N, i, fattoriale = 1;

	printf("Inserisci un numero: ");
	scanf("%d", &N);

	for(i=1; i<=N; i++)
		fattoriale*=i;

	printf("Il fattoriale di %d è %d\n", N, fattoriale);

}