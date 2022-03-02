// Si scriva un programma che, letti due file binari “ambito.bin” e “libretto.bin” (descritti successivamente e forniti come allegato) e una stringa inserita da tastiera dell’utente (indicante un ambito di studi), stampi su un terzo file binario solo gli esami (records del secondo file) appartenenti all’ambito specificato dall’utente.
// Infine si legga e stampi a video il contenuto del file per verificare che la scrittura sia avvenuta correttamente.

// Il file binario “ambito.bin” è composto da record nel formato
// <nome_esame> <ambito_esame>
// mentre “libretto.bin” contiene record nel formato
// <nome_esame> <voto>

// <nome_esame> ha lunghezza massima 20 caratteri (più il terminatore).
// <ambito_esame> ha lunghezza massima 3 caratteri (più il terminatore).
// L’ordine degli esami nei 2 file corrisponde (vedi esempio immagine).

// Si suddivida opportunamente il programma in procedure / funzioni (in particolare si suggerisce una procedura che, dato in ingresso come primo parametro un array di strutture con i campi nome_esame e ambito e come secondo parametro il nome di un esame, restituisca l’ambito corrispondente).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100
#define DIMFILE 20
#define DIMESAME 21
#define DIMAMBITO 4

typedef struct {
	char nome_esame[DIMESAME];
	char ambito_esame[DIMAMBITO];
} ambito;

typedef struct {
	char nome_esame[DIMESAME];
	int voto;
} libretto;

void readAmbito(ambito ambiti[], int *N, char filename[DIMFILE]) {
	FILE *fp;

	if((fp = fopen(filename, "rb")) == NULL) {
		printf("Errore nell'apertura del file\n");
		exit(1);
	}

	*N = fread(ambiti, sizeof(ambito), DIM, fp);

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(0);
	}
}

void readLibretto(libretto libretti[], int *N, int DIM_RISULTATI, char filename[DIMFILE]) {
	FILE *fp;

	if((fp = fopen(filename, "rb")) == NULL) {
		printf("Errore nell'apertura del file\n");
		exit(1);
	}

	*N = fread(libretti, sizeof(libretto), DIM_RISULTATI, fp);

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(0);
	}
}

int getAmbito(ambito ambiti[], int N, char esame[DIMESAME]) {
	int i;
	for(i=0; i<N; i++) {
		if(strcmp(ambiti[i].nome_esame, esame) == 0) {
			return i;
		}
	}
	return 0;
}

void writeLibretto(libretto risultati[], char filename[DIMFILE]) {
	FILE *fp;

	if((fp = fopen(filename, "wb")) == NULL) {
		printf("Errore nell'apertura del file\n");
		exit(1);
	}

	fwrite(risultati, sizeof(libretto), DIM, fp);

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(2);
	}
}

void printLibretto(libretto elm[], int N) {
	int i;
	for(i=0; i<N; i++){
		printf("Nome: %s\tVoto: %d\n", elm[i].nome_esame, elm[i].voto);
	}
}

void getEsami(
	libretto libretti[], 
	int N_libretti,
	ambito ambiti[],
	int N_ambiti,
	libretto risultati[],
	int *N_risultati,
	char ambito[DIMAMBITO]
) {
	int i;
	for(i=0; i<N_libretti; i++) {
		int index = getAmbito(ambiti, N_ambiti, libretti[i].nome_esame);
		char ambito_esame[DIMAMBITO];
		strcpy(ambito_esame, ambiti[index].ambito_esame);

		if((strcmp(ambito, ambito_esame)) == 0) {
			printf("L'ambito di %s è %s\n", libretti[i].nome_esame, ambito_esame);
			risultati[*N_risultati] = libretti[i];
			(*N_risultati)++;
		}
	}
}

int main() {
	ambito ambiti[DIM];
	libretto libretti[DIM];
	libretto risultati[DIM];
	libretto test[DIM];
	int N_ambiti;
	int N_libretti;
	int N_risultati = 0;
	int N_test;
	char ambito[DIMAMBITO] = "fis";

	readAmbito(ambiti, &N_ambiti, "ambito.bin");
	readLibretto(libretti, &N_libretti, DIM, "libretto.bin");
	getEsami(libretti, N_libretti, ambiti, N_ambiti, risultati, &N_risultati, ambito);
	writeLibretto(risultati, "voti.bin");
	readLibretto(test, &N_test, N_risultati, "voti.bin");
	printLibretto(test, N_test);
}
