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
	int i;

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

void readLibretto(libretto libretti[], int *N, char filename[DIMFILE]) {
	FILE *fp;
	int i;

	if((fp = fopen(filename, "rb")) == NULL) {
		printf("Errore nell'apertura del file\n");
		exit(1);
	}

	*N = fread(libretti, sizeof(libretto), DIM, fp);

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(0);
	}
}

void readRisultato(libretto risultati[], char filename[DIMFILE]) {
	FILE *fp;
	int i;
	libretto prova[DIM];
	int N_prova = 0;

	if((fp = fopen(filename, "rb")) == NULL) {
		printf("Errore nell'apertura del file\n");
		exit(1);
	}

	N_prova = fread(prova, sizeof(libretto), DIM, fp);

	// si rompe qui
	//for(i=0; i<N_prova; i++) {
		// printf("%s %d\n", prova[i].nome_esame, prova[i].voto);
	//}

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
			// printf("%s è uguale a %s, ambito %s\n", ambiti[i].nome_esame, esame, ambiti[i].ambito_esame);
		}
	}
	return 0;
}

int main() {
	ambito ambiti[DIM];
	libretto libretti[DIM];
	libretto risultati[DIM];
	int N_ambiti;
	int N_libretti;
	int N_risultati = 0;
	int i;
	char ambito[DIMAMBITO] = "fis";

	readAmbito(ambiti, &N_ambiti, "ambito.bin");
	readLibretto(libretti, &N_libretti, "libretto.bin");

	getAmbito(ambiti, N_ambiti, "fisica2");

	for(i=0; i<N_libretti; i++) {
		int index = getAmbito(ambiti, N_ambiti, libretti[i].nome_esame);
		char ambito_esame[DIMAMBITO];
		strcpy(ambito_esame, ambiti[index].ambito_esame);
		
		if((strcmp(ambito, ambito_esame)) == 0) {
			// printf("L'ambito di %s è %s\n", libretti[i].nome_esame, ambito_esame);
			// risultati[N_risultati] = libretti[i];
			strcpy(risultati[N_risultati].nome_esame, libretti[i].nome_esame);
			risultati[N_risultati].voto = libretti[i].voto;
			N_risultati++;
		}
		printf("Risultati: %d\n", N_risultati);
	}

	// for(i=0; i<N_risultati; i++) {
	// 	printf("%s: %d\n", risultati[i].nome_esame, risultati[i].voto);
	// }

	FILE *fp;

	if((fp = fopen("voti.bin", "wb")) == NULL) {
		printf("Errore nell'apertura del file\n");
		exit(1);
	}

	fwrite(risultati, sizeof(libretto), DIM, fp);

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(2);
	}

	readRisultato(risultati, "voti.bin");

	// una stringa inserita da tastiera dell’utente (indicante un ambito di studi), stampi su un terzo file binario solo gli esami (records del secondo file) appartenenti all’ambito specificato dall’utente.

	// for(i=0; i<N_ambiti; i++) {
    //     printf("Ambito: %s\tNome: %s\n", ambiti[i].ambito_esame, ambiti[i].nome_esame);
	// }
	// printf("\n\n");
	// for(i=0; i<N_libretti; i++) {
    //     printf("Nome: %s\tVoto: %d\n", libretti[i].nome_esame, libretti[i].voto);
	// }

}