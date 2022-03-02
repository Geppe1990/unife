// Scrivere un programma C che calcoli la radice quadrata (intera) di un naturale N
//, 𝐬𝐞𝐧𝐳𝐚 usare le funzioni del linguaggio C per calcolare la radice quadrata.

// Esempio: N=7
// 0*0 < N ? Sì → continuo
// 1*1 < N ? Sì → continuo
// 2*2 < N ? Sì → continuo
// 3*3 < N ? No → termino
// la radice quadrata intera di 7 è 2.

#include <stdio.h>

int main() {
	int N, i = 0, radice;
	printf("Inserisci un numero: ");
	scanf("%d", &N);

	while(i*i <= N) {
		radice = i;
		i++;
	}
	
	printf("La radice quadrata intera di %d è %d\n", N, radice);
}