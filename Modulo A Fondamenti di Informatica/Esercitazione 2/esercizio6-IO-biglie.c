// In un barattolo ci sono N biglie, ciascuna delle quali può essere di colore rosso o azzurro.
// Sappiamo che le biglie rosse sono sempre il doppio di quelle azzurre.
// Leggere da tastiera il numero intero N di biglie contenute nel barattolo, dove N
// è un multiplo di 3 (non vanno eseguiti controlli sul numero inserito).
// Stampare a video il numero di biglie rosse e di biglie azzurre calcolate in funzione di N.


#include <stdio.h>

main() {
	int biglie, rosse, blu;

	printf("Inserisci N biglie: ");
	scanf("%d", &biglie);

	blu = biglie / 3;
	rosse = blu * 2;
	printf("Sono presenti %d biglie rosse\n", rosse);
	printf("Sono presenti %d biglie blu\n", blu);
}
