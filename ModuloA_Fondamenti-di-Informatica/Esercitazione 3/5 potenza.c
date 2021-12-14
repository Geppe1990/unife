// Dati due numeri interi N e M con M >=0, codificare in linguaggio C un programma 
// che calcoli la potenza N^M. Risolvere il problema 𝐬𝐞𝐧𝐳𝐚 utilizzare le funzioni messe 
// a disposizione dal linguaggio C per calcolare l'elevamento a potenza (pow).

// VARIANTE: supporre che M possa assumere valori negativi.

#include <stdio.h>

float getpow(int N, int M) {
	float pot;
	int i;
	pot = 1;

	if(M<0)
		M *= -1;

	for(i=1; i<=M; i++) {
		pot *= N;
	}

	if(M<0)
		pot = 1/pot;

	return pot;
}

int main() {
	int M, N;
	float potenza;
	N=3;
	M=-3;
	potenza = getpow(N, M);
	printf("%d^%d=%f\n", N, M, potenza);
}