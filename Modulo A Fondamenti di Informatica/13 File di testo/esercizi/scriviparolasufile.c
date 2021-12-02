// Si scriva su un file di testo di nome prova.txt quello che l'utente inserisce da tastiera parola per parola, finchè non inserisce la parola "FINE"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30

int main() {
	FILE *fp;
	char parola[30];

	fp = fopen("prova.txt", "wt");

	if(fp == NULL) {
		printf("Impossibile aprire il file prova.txt\n");
		exit(1);
	}

	do {
		fscanf(stdin, "%s", parola);
		if(strcmp(parola, "FINE") != 0)
			fprintf(fp, "%s\n", parola);
	} while(strcmp(parola, "FINE") != 0);

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file prova.txt\n");
		exit(2);
	}
}
