// In un sondaggio ci sono tre possibili risposte: "sì", "no", "non so".
// Progettare un programma in linguaggio C che legge da tastiera tre
// interi, che corrispondono al numero di volte in cui è stata data
// ciascuna delle tre risposte, e stampa a video le relative percentuali.
// Più precisamente:
// - Legge il numero di "sì", "no", "non so"
// - Stampa il numero totale di risposte ottenute
// - Stampa le percentuali di "sì", "no", "non so"

#include <stdio.h>

main() {
	int si, no, nonso, totale, perc_si, perc_no, perc_nonso;
	printf("Inserisci le 3 percentuali: ");
	scanf("%d %d %d", &si, &no, &nonso);
	totale = si+no+nonso;
	perc_si = (100*si)/totale;
	perc_no = (100*no)/totale;
	perc_nonso = (100*nonso)/totale;

	printf("Percentuale SI: %d\n", perc_si);
	printf("Percentuale NO: %d\n", perc_no);
	printf("Percentuale NON SO: %d\n", perc_nonso);
}