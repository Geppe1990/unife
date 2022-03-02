// Un bambino compra delle caramelle da dividere equamente con i suoi compagni e vuole calcolare quante 
// caramelle spettano a ciascuno di essi, quante ne rimarranno e quanto ha speso per ogni suo compagno 
// conoscendo il prezzo di ogni caramella.

// Progettare un programma in linguaggio C che legge da tastiera:
// - il numero caramelle;
// - il prezzo unitario delle caramelle;
// - il numero di bambini;
// e stampa a video:
// - il numero di caramelle che spettano a ciascun bambino;
// - il numero di caramelle che rimangono;
// - la spesa per ciascun bambino.


#include <stdio.h>

main() {
	int caramelle, prezzo, bambini;
	int caramella_bambino, caramelle_rimaste, prezzo_bambino;

	printf("Inserisci il numero di caramelle: ");
	scanf("%d", &caramelle);
	printf("Inserisci il prezzo delle caramelle: ");
	scanf("%d", &prezzo);
	printf("Inserisci il numero di bambini: ");
	scanf("%d", &bambini);

	caramella_bambino = caramelle / bambini;
	caramelle_rimaste = caramelle % bambini;
	prezzo_bambino = caramella_bambino * prezzo;

	printf("Numero di caramelle che spettano a ciascun bambino: %d\n", caramella_bambino);
	printf("Numero di caramelle che rimangono: %d\n", caramelle_rimaste);
	printf("Spesa per ciascun bambino: %d\n", prezzo_bambino);
}