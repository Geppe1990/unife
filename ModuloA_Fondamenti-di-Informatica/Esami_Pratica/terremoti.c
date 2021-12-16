// Il file di testo terremoti.txt contiene i dati sugli ultimi terremoti registrati da una stazione sismica. I terremoti registrati nel file sono al massimo 100. Per ogni terremoto sono riportati:

// - latitudine e longitudine: due float
// - profondità in km: float
// - magnitudine: float
// - luogo: stringa contenente al più 60 caratteri, senza spazi

// Si scriva un programma in linguaggio C che visualizza a video tutti i luoghi di terremoti con magnitudine superiore a 5, organizzando il programma come segue:
// 1. nel main, si invochi una funzione di lettura (da sviluppare al punto 2), una di stampa (punto 3), e una di visualizzazione dei terremoti ad alta magnitudine (punto 4).

// Si codifichino e si usino le seguenti funzioni/procedure:
// 2. int lettura(...); deve leggere il file e portarne il contenuto in un opportuno array di strutture
// 3. void stampa(...); deve mostrare a video il contenuto dell'array di strutture letto al punto 2
// 4. void visualizza(...); è la funzione di visualizzazione dei terremoti ad alta magnitudine e deve visualizzare
//  - un carattere chiocciola '@'
//  - tutti i luoghi dove sono avvenuti terremoti con magnitudine superiore a 5 (seaprati da uno spazio)
//  - un carattere chiocciola '@'
 
// Per le funzioni si rispettino strettamente le interfacce indicate nel testo, al posto dei puntini (...) è possibile inserire i parametri ritenuti più adeguati.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

typedef struct {
	float latitudine;
	float longitudine;
	float profondita;
	float magnitudine;
	char luogo[60];
} terremoto;

int lettura(terremoto t[]) {
	FILE *fp;
	int n = 0;
	if((fp = fopen("terremoti.txt", "rt")) == NULL) {
		printf("Errore nell'apertura del file di testo\n");
		exit(1);
	}

	while(fscanf(fp, "%f %f %f %f %s", &t[n].latitudine, &t[n].longitudine, &t[n].profondita, &t[n].magnitudine, t[n].luogo) != EOF) {
		n++;
	}

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file di testo\n");
		exit(2);
	}

	return n;
}

void stampa(terremoto t[], int N) {
	int i;

	printf("indice\tlatitudine\tlongitudine\tprofondita\tmagnitudine\tluogo\n");
	for(i=0; i<N; i++) {
		printf("%d\t%f\t%f\t%f\t%f\t%s\n", i, t[i].latitudine, t[i].longitudine, t[i].profondita, t[i].magnitudine, t[i].luogo);
	}
}

void visualizza(terremoto t[], int N, terremoto t2[], int *N2) {
	int i;
	int j;
	int presente;
	printf("@ ");
	for(i=0; i<N; i++) {
		if(t[i].magnitudine > 5) {
			presente = 0;

			for(j=0; j<*N2; j++) {
				if((strcmp(t2[j].luogo, t[i].luogo)) == 0) {
					presente = 1;
				}
			}

			if(!presente) {
				printf("%s ", t[i].luogo);
				t2[*N2] = t[i];
				(*N2)++;
			}
		}
	}

	printf("@");
}

int main() {
	terremoto terremoti[DIM];
	terremoto terremoti_stampati[DIM];
	int N = lettura(terremoti);
	int N2 = 0;
	stampa(terremoti, N);
	visualizza(terremoti, N, terremoti_stampati, &N2);
}