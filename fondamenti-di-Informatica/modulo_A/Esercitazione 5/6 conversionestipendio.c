// Si progetti un programma che converta lo stipendio di un dipendente di 
// un'azienda in sterline o in yen.
// Si creino le seguenti funzioni:
// - Funzione di conversione euro/sterlina: float EuroSterlina che effettua la 
// conversione (1 euro = 0,91 sterlina)
// - Funzione di conversione euro/yen: float EuroYen che effettua la conversione 
// (1 euro = 124,09)

// Si scriva poi un main() che prenda in ingresso un intero e chieda all'utente se 
// vuole convertirlo in sterline o in yen e chiami la funzione di conversione 
// adeguata (EuroSterlina per la conversione in sterline, EuroYen per la conversione in yen).
// Si stampi infine lo stipendio convertito.

// CONSIGLI:
// Per evitare i warning nelle conversioni di tipo, si puo` usare il type casting.
// Chi volesse stampare solo 2 decimali di un float, può utilizzare %.2f nella stringa 
// formato della printf.

// Chi lo desidera, può aggiungere altre funzioni. Per esempio, invece di leggere lo 
// stipendio nel main con una scanf, si può definire una Funzione di 
// inserimento dati: int Inserimento() che prende da tastiera un intero, 
// lo stipendio e lo fornisce come valore di ritorno.

#include <stdio.h>

float Conversione(int a, float tasso) {
	float conv;
	conv = (float)a * tasso;
	return conv;
}

float EuroSterlina(int a) {
	float tasso = 0.91;

	return Conversione(a, tasso);
}

float EuroYen(int a) {
	float tasso = 124.09; 

	return Conversione(a, tasso);
}

int Inserimento() {
	int stipendio;
	printf("Inserisci lo stipendio: ");
	scanf("%d", &stipendio);

	return stipendio;
}

int main() {
	int a = Inserimento();
	int scelta = 0;

	printf("Il tuo stipendio è di %d euro\n", a);
	printf("Converti in [1] Sterline, [0] YEN: ");
	scanf("%d", &scelta);

	if(scelta)
		printf("Il tuo stipendio è di %.4f sterline\n", EuroSterlina(a));
	else
		printf("Il tuo stipendio è di %.4f YEN\n", EuroYen(a));
}