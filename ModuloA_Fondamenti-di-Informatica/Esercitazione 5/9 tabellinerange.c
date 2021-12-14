// Si scriva una funzione range(int start, int stop, int step) 
// che stampi una sequenza ordinata di numeri interi a partire 
// dall'intero "start" (compreso) fino all'intero "stop" (non compreso) 
// con un passo dato dal parametro "step".


// Esempio:
// range(1,10,2) -> 1 3 5 7 9


// All'interno del main richiamare la funzione range per stampare i 
// risultati delle tabelline dall'1 ad un numero N letto da tastiera.

#include <stdio.h>

void range(int start, int stop, int step) {
	for(int i=start; i<stop; i+=step)
		printf("%d\n", i);
}

int main() {
	int n, i;
	printf("Inserisci numero: ");
	scanf("%d", &n);
	printf("Stampo tabelline da 1 a %d\n", n);

	for (int i = 1; i <= n; i++)
	{
		printf("Tabellina del %d\n", i);
		range(i, i * 10 + 1, i);
		printf("\n");
	}
}