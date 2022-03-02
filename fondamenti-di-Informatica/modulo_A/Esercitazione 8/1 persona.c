// Scrivere un programma in linguaggio C che definisca la struttura “persona” composta da:
// - nome (stringa contenente al più 32 caratteri compreso il terminatore);
// - cognome (stringa contenente al più 32 caratteri compreso il terminatore);
// - (indirizzo) via (stringa contenente al più 64 caratteri compreso il terminatore);
// - (indirizzo) numero civico (intero);
// - (indirizzo) città (stringa contenente al più 64 caratteri compreso il terminatore);
// - (indirizzo) provincia (stringa contenente al più 3 caratteri compreso il terminatore);
// - data di nascita (3 variabili intere: giorno, mese, anno).

// Si richiedano all'utente tutti i dati, si inseriscano nella struttura dati 
// appena definita e poi si stampino a video.

#include <stdio.h>

typedef struct {
	char nome[32];
	char cognome[32];
	char via[63];
	int civico;
	char citta[63];
	char provincia[3];
	int giorno;
	int mese;
	int anno;
} persona;

int main() {
	persona studente;
	printf("Inserisci il nome: ");
	scanf("\n%s", studente.nome);
	printf("Inserisci il cognome: ");
	scanf("\n%s", studente.cognome);
	printf("Inserisci la via: ");
	scanf("\n%s", studente.via);
	printf("Inserisci il civico: ");
	scanf("\n%d", &studente.civico);
	printf("Inserisci la città: ");
	scanf("\n%s", studente.citta);
	printf("Inserisci la provincia: ");
	scanf("\n%s", studente.provincia);
	printf("Inserisci il giorno di nascita: ");
	scanf("\n%d", &studente.giorno);
	printf("Inserisci il mese di nascita: ");
	scanf("\n%d", &studente.mese);
	printf("Inserisci l'anno di nascita: ");
	scanf("\n%d", &studente.anno);

	printf("Nome: %s\n", studente.nome);
	printf("Cognome: %s\n", studente.cognome);
	printf("Via: %s\n", studente.via);
	printf("Civico: %d\n", studente.civico);
	printf("Città: %s\n", studente.citta);
	printf("Provincia: %s\n", studente.provincia);
	printf("Data di nascita: %d/%d/%d\n", studente.giorno, studente.mese, studente.anno);
}