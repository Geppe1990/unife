// In un concorso, i partecipanti. sono sottoposti a 10 prove. I risultati del concorso sono memorizzati in un array di strutture (vedi file allegato) che contiene, per ogni concorrente, i seguenti dati:
// - nome: stringa contenente al massimo 20 caratteri, compreso il terminatore;
// - punteggi: una sequenza di 10 interi (array).

// Si scriva un programma che stampi, per ciascuna prova, chi è il vincitore e con quale punteggio.

// Ad esempio, se i dati di input sono i seguenti:
// Rossi 1 3 4 ...
// Bianchi 2 1 5 ...
// Verdi 4 2 6 ...

// Il programma dovrà visualizzare:
// Prova 1: vincitore Verdi con punti 4
// Prova 2: vincitore Rossi con punti 3
// Prova 3: vincitore Verdi con punti 6
// ...

#include <stdio.h>

typedef struct {
	char nome[20];
	int punteggi[10];
} partecipante;

int main() {
	const int Npartecipanti = 4;
	int i, j;
	partecipante p[] = {
		{"Rossi", 
			{4,5,6,4,7,8,9,6,4,4}},
		{"Neri", 
			{4,6,5,4,3,4,5,6,7,7}},
		{"Bianchi", 
			{7,8,9,6,4,3,5,7,8,6}},
		{"Verdi", 
			{8,7,5,6,7,8,5,4,3,3}}
	};

	for(i=0; i<10; i++) {
		printf("[Esame %d] ", i+1);

		int vincitore = 0;
		for(j=0; j<Npartecipanti; j++) {
			if(p[j].punteggi[i] > p[vincitore].punteggi[i]) {
				vincitore = j;
			}
		}
		printf("Vincitore %s con punti %d\n", p[vincitore].nome, p[vincitore].punteggi[i]);
	}
}