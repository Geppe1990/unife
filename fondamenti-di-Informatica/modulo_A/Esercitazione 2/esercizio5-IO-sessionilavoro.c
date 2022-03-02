// Un consulente deve calcolare il numero di ore e minuti spesi lavorando per un cliente.
// Egli ha lavorato in due distinte sessioni di lavoro, per ciascuna delle
// quali ha annotato il numero di ore e il numero di minuti impiegati.
// Si scriva un programma in C che, a partire dalle ore e minuti della prima
// sessione di lavoro e dalle ore e minuti della seconda sessione di
// lavoro, calcoli il numero di ore e minuti complessivi.

// CONSIGLIO: Sfruttare la divisione intera e il resto.

#include <stdio.h>

main() {
	int ore_sess1, minuti_sess1, ore_sess2, minuti_sess2, ore_totali, minuti_totali;
	printf("SESSIONE 1: Inserisci ore e minuti: ");
	scanf("%d %d", &ore_sess1, &minuti_sess1);
	printf("SESSIONE 2: Inserisci ore e minuti: ");
	scanf("%d %d", &ore_sess2, &minuti_sess2);

	minuti_totali = (minuti_sess1+minuti_sess2)%60;
	ore_totali = ore_sess1 + ore_sess2 + (minuti_sess1+minuti_sess2)/60;

	printf("In totale ha lavorato %d ore e %d minuti\n", ore_totali, minuti_totali);

}