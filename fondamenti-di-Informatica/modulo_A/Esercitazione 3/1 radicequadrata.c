// Scrivere un programma C che calcoli la radice quadrata (intera) di un naturale N
//, ð¬ðð§ð³ð usare le funzioni del linguaggio C per calcolare la radice quadrata.

// Esempio: N=7
// 0*0 < N ? SÃ¬ â continuo
// 1*1 < N ? SÃ¬ â continuo
// 2*2 < N ? SÃ¬ â continuo
// 3*3 < N ? No â termino
// la radice quadrata intera di 7 Ã¨ 2.

#include <stdio.h>

int main() {
	int N, i = 0, radice;
	printf("Inserisci un numero: ");
	scanf("%d", &N);

	while(i*i <= N) {
		radice = i;
		i++;
	}
	
	printf("La radice quadrata intera di %d Ã¨ %d\n", N, radice);
}