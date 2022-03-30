#include <stdio.h>
#define N 15
typedef int vettore[N];

int minimo(vettore vet) {
	int i;
	int min = vet[0];
	
	for(i = 1; i<N; i++) {
		if(vet[i] < min) { /* istruzione dominante */
			min = vet[i];
		}
	}

	return min;
}

int massimo(vettore vet) {
	int i;
	int max = vet[0];
	
	for(i = 1; i<N; i++) {
		if(vet[i] > max) { /* istruzione dominante */
			max = vet[i];
		}
	}

	return max;
}

void main(void) {
	int i;
	vettore a;
	printf("Scrivi %d numeri interi\n", N);

	for(i=0; i<N; i++) {
		scanf("%d", &a[i]);
	}

	printf("Il minimo vale %d e il massimo è %d\n", minimo(a), massimo(a));
}