// Nel file di testo anagrafe.txt contenuto nella domanda fuori da questo modulo sono presenti personaggi storici ed attuali (Nome Cognome eta).

// Nome e Cognome sono stringhe lunghe al massimo 20 caratteri (compreso terminatore).

// Si legga l’anagrafe testuale e, una persona alla volta, si salvi il contenuto nel file binario anagrafe.bin
// Si legga l’anagrafe binaria (ovvero anagrafe.bin) e, una persona alla volta, si salvi il contenuto nel file di testo copia_anagrafe.txt

#include <stdio.h>
#include <stdlib.h>
#define DIM 100

typedef struct {
	char nome[20];
	char cognome[20];
	int eta;
} persona;

void readText(FILE *fp, int *N, persona persone[]) {
	if((fp=fopen("anagrafe.txt", "rt")) == NULL) {
		printf("Errore nell'apertura del file 1\n");
		exit(1);
	}

	while(fscanf(fp, "%s %s %d", persone[*N].nome, persone[*N]. cognome, &persone[*N].eta) != EOF) 
		(*N)++;


	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(2);
	}
}

void writeBin(FILE *fp, int N, persona persone[]) {
	if((fp = fopen("anagrafe.bin", "wb")) == NULL) {
		printf("Errore nell'apertura del file 2\n");
		exit(1);
	}

	fwrite(persone, sizeof(persona), DIM, fp);

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(2);
	}
}

void readBin(FILE *fp, int N, persona persone[]) {
	int i;
	if((fp = fopen("anagrafe.bin", "rb")) == NULL) {
		printf("Errore nell'apertura del file 3\n");
		exit(1);
	}

	fread(persone, sizeof(persona), DIM, fp);

	// printf("[LEGGO DA FILE BINARIO]\n");
	// for(i=0; i<N; i++) {
	// 	printf("%s %s %d\n", persone[i].nome, persone[i].cognome, persone[i].eta);
	// }

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(2);
	}
}

void writeText(FILE *fp, int N, persona persone[]) {
	int i;
	if((fp = fopen("copia_anagrafe.txt", "w")) == NULL) {
		printf("Errore nell'apertura del file 4\n");
		exit(1);
	}

	for(i=0; i<N; i++) {
		fprintf(fp, "%s %s %d\n", persone[i].nome, persone[i].cognome, persone[i].eta);
	}

	if((fclose(fp)) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(2);
	}
}

void printText(FILE *fp, persona persone[]) {
	int i = 0;
	if((fp=fopen("copia_anagrafe.txt", "rt")) == NULL) {
		printf("Errore nell'apertura del file 1\n");
		exit(1);
	}

	while(fscanf(fp, "%s %s %d", persone[i].nome, persone[i]. cognome, &persone[i].eta) != EOF) {
		printf("%s %s ha %d anni\n", persone[i].nome, persone[i]. cognome, persone[i].eta);
		i++;
	}

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(2);
	}
}

int main() {
	FILE *fp;
	int N = 0;
	int i;
	persona persone[DIM];
	persona persone_copia[DIM];

	readText(fp, &N, persone);
	writeBin(fp, N, persone);
	readBin(fp, N, persone);
	writeText(fp, N, persone);
	printText(fp, persone_copia);
}