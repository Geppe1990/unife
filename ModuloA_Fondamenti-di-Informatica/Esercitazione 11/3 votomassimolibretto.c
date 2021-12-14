// Si scriva un programma che legga un file binario: “libretto2.bin”  in cui sono presenti gli esami sostenuti e il relativo voto e produca in uscita un file di testo "libretto.txt" contenente la copia dei dati letti dal file binario e in ultima riga l'esame con il voto più alto. 
// Si divida opportunamente il programma in procedure / funzioni.

// Il file “libretto.txt” deve avere la stesa struttura del file “libretto2.bin” composta da una stringa di al più 20 caratteri più il terminatore e un numero intero.

#include <stdio.h>
#include <stdlib.h>
#define DIM 100

typedef struct {
	char nome[21];
	int voto;
} esame;

void readBinary(esame esami[], int *N) {
	FILE *fp;
	int i;

	if((fp = fopen("libretto2.bin", "rb")) == NULL) {
		printf("Errore nell'apertura del file\n");
		exit(1);
	}

	*N = fread(esami, sizeof(esame), DIM, fp);

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(2);
	}
}

void writeText(esame esami[], int N) {
	FILE *fp;
	int i;
	int max_voto = esami[0].voto;
	int max_index = 0;

	if((fp = fopen("libretto.txt", "wt")) == NULL) {
		printf("Errore nell'apertura del file\n");
		exit(1);
	}

	for(i=0; i<N; i++) {
		fprintf(fp, "%s %d\n", esami[i].nome, esami[i].voto);
		if(esami[i].voto > max_voto) {
			max_index = i;
			max_voto = esami[i].voto;
		}
	}

	fprintf(fp, "L'esame migliore è stato %s con voto %d\n", esami[max_index].nome, esami[max_index].voto);

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(2);
	}
}

int main() {
	esame esami[DIM];
	int N;
	int i;

	readBinary(esami, &N);
	writeText(esami, N);

	for(i=0; i<N; i++) {
		printf("Nome: %s\tVoto: %d\n", esami[i].nome, esami[i].voto);
	}
}
