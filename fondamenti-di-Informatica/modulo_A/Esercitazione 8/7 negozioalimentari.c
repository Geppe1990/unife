// Un negozio di alimentari ha un archivio (realizzato tramite un array di strutture, vedi file allegato) in cui vengono memorizzati i prodotti presenti in magazzino. 

// const int Nprodotti = 11
// prodotto magazzino[] = {
// {"Biscotti", 25, 2022},
// {"Marmellata", 5, 2017}, 
// {"Nutella", 30, 2028},
// {"Burro", 4, 2015}, 
// {"Grissini", 9, 2024}, 
// {"Miele", 14, 2014}, 
// {"Latte", 46, 1998}, 
// {"Yogurt", 2, 1991}, 
// {"Mozzarella", 7, 2014},
// {"Pasta", 56, 2006}, 
// {"Sottilette", 48, 2021}
// }; 

// Per ogni prodotto in magazzino, si dispone dei seguenti dati:
// - La descrizione (stringa max 20 caratteri compreso il terminatore).
// - La quantità disponibile in magazzino (intero).
// - L’anno di scadenza (intero).

// Il programma deve memorizzare in un secondo array di strutture tutti i prodotti che sono da cancellare dall’archivio perché scaduti.
// Al termine si stampi a video il vettore dei prodotti scaduti.

#include <stdio.h>

typedef struct {
	char descrizione[20];
	int quantita;
	int scadenza;
} prodotto;

int main() {
	int i;
	int j=0;
	const int Nprodotti = 11;
	prodotto scaduti[Nprodotti];
	prodotto magazzino[] = {
		{"Biscotti", 25, 2022},
		{"Marmellata", 5, 2017}, 
		{"Nutella", 30, 2028},
		{"Burro", 4, 2015}, 
		{"Grissini", 9, 2024}, 
		{"Miele", 14, 2014}, 
		{"Latte", 46, 1998}, 
		{"Yogurt", 2, 1991}, 
		{"Mozzarella", 7, 2014},
		{"Pasta", 56, 2006}, 
		{"Sottilette", 48, 2021}
	}; 

	for(i=0; i<Nprodotti; i++) {
		if(magazzino[i].scadenza < 2021) {
			scaduti[j] = magazzino[i];
			j++;
		}
	}

	printf("Stampo i prodotti scaduti\n");
	for(i=0; i<j; i++) {
		printf("%s, %d confezioni, scadute nel %d\n", scaduti[i].descrizione, scaduti[i].quantita, scaduti[i].scadenza);
	}
}