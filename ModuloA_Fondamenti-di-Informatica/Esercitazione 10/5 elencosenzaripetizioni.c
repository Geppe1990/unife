// Si scriva un programma in linguaggio C che permette all'utente di inserire delle parole (stringhe) in un opportuno vettore di stringhe (matrice di char) senza ripetizioni.

// Il main dopo aver chiesto all'utente di inserire una parola da tastiera la inserisce in coda al vettore tramite una funzione "inserimento".
// La funzione "inserimento" prende come parametri il vettore di stringhe, la parola da inserire ed eventuali altri parametri:
// - restituisce 0 se la stringa è già presente nel vettore;
// - altrimenti procede ad inserire la nuova parola e restituisce 1.

// Il programma deve continuare a richiedere l'inserimento di nuove parole finché l'utente non inserisce la parola "fine" (che non va inserita nel vettore).
// Al termine dell'inserimento il programma deve stampare a video l'intero vettore di stringhe tramite una procedura.

#include <stdio.h>
#include <string.h>
#define DIM 25

int inserimento(char parole[DIM][DIM], char parola[DIM], int *n) {
	int i;
	int presente = 1;
	for(i=0; i<(*n); i++) {
		if(strcmp(parole[i], parola) == 0) {
			printf("%s è già presente\n", parola);
			presente = 0;
		}
	}

	if(presente) {
		printf("%s non è presente, lo inserisco\n", parola);
		strcpy(parole[(*n)], parola);
		(*n)++;
	}
	return presente;
}

int main() {
	char parola[DIM];
	char parole[DIM][DIM];
	int n = 0;
	int risposta;

	do {
		printf("Inserisci una parola: ");
		scanf("%s", parola);

		if(strcmp(parola, "fine") != 0) 
			risposta = inserimento(parole, parola, &n);
	}while(strcmp(parola, "fine") != 0);


	for(int i=0; i<n; i++) {
		printf("\n%s", parole[i]);
	}
}