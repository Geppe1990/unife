// Scrivere un programma C che chieda all’utente di inserire una stringa 
// (di sole lettere minuscole) e che conti quante volte appare ciascuna delle 
// lettere all’interno della stringa inserita.

// Per salvare i risultati del conteggio si crei un vettore di interi in cui la 
// posizione 0 corrisponde alla lettera ‘a’ e l’ultima posizione alla lettera ‘z’.
// Stampi a video il vettore creato (sfruttare i codici ASCII).

// Esempio di stampa:

// a b c d e f g h i ...
// [ 3 1 5 0 0 0 1 0 2 ... ]

#include <stdio.h>
#define DIM 30

int main() {
	char s[DIM];
	int s2[DIM];
	int i, j;
	printf("Inserisci stringa: ");
	scanf("%s", s);

	printf("Stringa (solo minuscole): %s\n", s);

	for(i=97; i<=122; i++){
		s2[i-97] = 0;
		for(j=0; s[j] != '\0'; j++) {
			if((char)i == s[j]) {
				s2[i-97] += 1;
			}
		}
	}
	
	for(i=0; i<=25; i++){
		printf(" %d ", s2[i]);
	}

	printf("\n");
	for(i=97; i<=122; i++){
		printf(" %c ", i);
	}
	printf("\n");

}