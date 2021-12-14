// Scrivere un programma C che prende in ingresso un numero intero N compreso tra 0 e 30.
// Il programma deve poi stampare a video:
// - Tutti i numeri 𝐩𝐚𝐫𝐢 maggiori di 0 e minori strettamente di N
// - Tutti i numeri 𝐝𝐢𝐬𝐩𝐚𝐫𝐢 maggiori strettamente di N e minori di 30

#include <stdio.h>

int main() {
	int N, LIM = 30, i;
	printf("Inserisci N: ");
	scanf("%d", &N);

	printf("Numeri pari maggiori di 0 e minori di %d: ", N);
	for(i=1; i<N; i++) {
		if(i % 2 == 0)
			printf("%d ", i);
	}
	printf("\n");
	printf("Numeri pari maggiori di N e minori di 30: ");
	for(i=N+1; i<LIM; i++) {
		if(i % 2 != 0)
			printf("%d ", i);
	}
	printf("\n");
}