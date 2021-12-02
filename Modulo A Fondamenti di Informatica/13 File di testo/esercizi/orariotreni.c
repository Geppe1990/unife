// L’orario di un treno `e memorizzato in un file di testo treni.txt. Per ciascuna
// tratta, il file contiene le seguenti informazioni:
//  stazione di partenza: stringa contenente al massimo 20 caratteri, senza
// spazi
//  stazione di arrivo: stringa contenente al massimo 20 caratteri, senza
// spazi
//  durata in minuti del viaggio: intero.
// Il file `e ordinato in ordine alfabetico per stazione di partenza.
// Sapendo che il treno parte alle ore 9.00 dalla stazione di Ferrara e che l’intero
// viaggio dura meno di un’ora, si visualizzino le stazioni nell’ordine in cui il treno
// vi sosta ed il corrispondente orario.
// Ad esempio, se il file treni.txt contiene le seguenti informazioni:

// Bondeno Zerbinate 9
// Ferrara Vigarano 9
// Vigarano Bondeno 13
// Zerbinate Sermide 10

// significa che il treno parte da Ferrara alle 9.00, poi arriva a Vigarano 9 minuti
// dopo (9.09), poi a Bondeno dopo altri 13 minuti (9.22), poi a Zerbinate dopo
// altri 9 minuti, infine a Sermide dopo ulteriori 10 minuti. Il programma dovr`a
// quindi visualizzare

// Ferrara 9.00
// Vigarano 9.09
// Bondeno 9.22
// Zerbinate 9.31
// Sermide 9.41

// 1

// Si utilizzi il seguente algoritmo:
// 1. Nel main, si invochi una procedura o funzione di lettura (da implementare
// al punto 2) ed una di elaborazione (punto 3).
// 2. Si realizzi la procedura o funzione di lettura, che legge il file treni.txt
// e ne porta il contenuto in un apposito array di strutture, poi visualizza il
// contenuto dell’array.
// 3. La procedura o funzione di elaborazione dovr`a prendere in ingresso l’array
// del punto 2 (ed, eventualmente, altri parametri) e visualizzare l’orario del
// treno (come spiegato in precedenza). Per fare questo, deve invocare una
// procedura o funzione di ricerca (da realizzare al punto 4).
// 4. Implementare la procedura o funzione di ricerca. Questa prender`a come
// parametri
//  una stringa s, che rappresenta il nome di una stazione
//  l’array creato al punto 2
// ed, eventualmente, altri parametri. La procedura o funzione dovr`a cercare
// nell’array una tratta che parte dalla stazione con nome s. La ricerca dovr`a
// comunicare alla procedura o funzione che l’ha invocata
//  se nell’array `e presente una tratta che inizia dalla stazione s
//  la tratta che parte dalla stazione con nome s.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char partenza[20];
	char arrivo[20];
	int durata;
} stazione;

int ricerca(stazione stazioni[], int length, char s[20], char s2[20], int *minuti) {
	int i = 0, presente = -1;
	*minuti = 0;

	char stazione[20] = "Ferrara";

	while(i<length) {
		int trovato = 0, j = 0;
		while(j<length && trovato == 0) {
			if((strcmp(stazione, stazioni[j].partenza)) == 0) {
				strcpy(stazione, stazioni[j].arrivo);
				if(strcmp(s, stazioni[j].partenza) == 0) {
					strcpy(s2, stazioni[j].arrivo);
					return 0;
				}
				trovato = 1;
				*minuti += stazioni[j].durata;

			}
			j++;
		}
		i++;
	}

	return presente;
}

int lettura(stazione stazioni[]) {
	int length = 0;
	FILE *fp;

	if((fp = fopen("treni.txt", "rt")) == NULL) {
		printf("Errore in apertura\n");
		exit(1);
	}

	while(fscanf(fp, "%s %s %d", stazioni[length].partenza, stazioni[length].arrivo, &stazioni[length].durata) != EOF) {
		length++;
	}

	if(fclose(fp) != 0) {
		printf("Errore in chiusura\n");
		exit(2);
	}

	int ora = 9, minuti = 0;
	int i = 0, j = 0;

	char stazione[20] = "Ferrara";

	while(i<length) {
		int trovato = 0;
		int j = 0;
		while(j<length && trovato == 0) {
			if((strcmp(stazione, stazioni[j].partenza)) == 0) {
				printf("%s %d:%d\n", stazione, ora, minuti);
				strcpy(stazione, stazioni[j].arrivo);
				trovato = 1;
				minuti += stazioni[j].durata;
			}
			j++;
		}
		i++;
		if(i == length) {
			printf("%s %d:%d\n", stazione, ora, minuti);
		}
	}
	return length;
}

void elaborazione(stazione stazioni[], int length) {
	char partenza[20];
	char arrivo[20];
	printf("Inserisci il nome della stazione da cercare: ");
	scanf("%s", partenza);
	int ora = 9;
	int minuti;
	int cercastazione = ricerca(stazioni, length, partenza, arrivo, &minuti);

	if(cercastazione != -1) {
		printf("%s - %s\n", partenza, arrivo);
		printf("Parte alle: %d:%d\n", ora, minuti);
	} else {
		printf("Nessun treno parte da %partenza\n", partenza);
	}
}

int main() {
	stazione stazioni[100];
	int length = lettura(stazioni);
	elaborazione(stazioni, length);
}