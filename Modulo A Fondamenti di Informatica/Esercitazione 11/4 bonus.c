// In un base militare sotterranea, in un luogo non meglio identificato della terra, lavora un gruppo di scienziati. Gli scienziati ogni giorno hanno un gran da fare in quanto le mansioni nella base di certo non mancano. La pianificazione delle mansioni di ogni giornata è memorizzata in un file binario planning.bin che contiene massimo 100 elementi. Per ogni mansione nel file planning.bin è riportato: 
// - fascia oraria: valore intero che può assumere i valori da 1 a 24 e rappresenta la fascia oraria della giornata in cui la mansione deve essere svolta; 
// - incaricato: stringa senza spazi contenente al più 20 caratteri (compreso il terminatore), contiene il nome dello scienziato che deve svolgere la mansione; 
// - mansione: stringa senza spazi contenente al più 30 caratteri (compreso il terminatore), contiene il nome della mansione che lo scienziato deve svolgere. 
// Ogni mansione affinché sia considerata completata deve essere svolta almeno un certo numero di volte durante l’arco della giornata dallo stesso scienziato o da scienziati diversi. Un file di testo tasks.txt contiene le informazioni riguardo le mansioni che sono massimo 100. Per ogni mansione nel file tasks.txt è riportato: 
// - mansione: stringa senza spazi contenente al più 30 caratteri (compreso il terminatore), contiene il nome della mansione; 
// - stanza: stringa senza spazi contenente al più 20 caratteri (compreso il terminatore), contiene il nome della stanza dove la mansione deve essere eseguita; 
// - ripetizioni: valore intero che indica il numero minimo di volte che la mansione deve essere svolta per considerarsi completata al termine della giornata. 
// Si scriva un programma in linguaggio C che dati i file tasks.txt e planning.bin calcoli, nel caso siano presenti, quali sono le mansioni che non vengono completate alla fine della giornata e le stampi a video. Per ciascuna mansione non completata si stampi il numero di volte in cui è stata effettivamente eseguita e il numero di esecuzioni atteso per completarla. 
// Si organizzi opportunamente il programma in procedure e funzioni. 
// Parte 2 

//TODO: CONTINUA DA QUI
// Un giorno all’interno del laboratorio iniziano a verificarsi dei fatti insoliti, gli scienziati non impiegano molto tempo a capire che tra di loro si nasconde un impostore il cui unico scopo è uccidere gli scienziati della base per bloccare le ricerche. 
// L’impostore uccide gli scienziati quando si trova all’interno di una stanza con loro (se ci sono più scienziati contemporaneamente verranno tutti assassinati). Gli spostamenti dell’impostore all’interno del laboratorio sono memorizzati in un file impostor.bin che contiene massimo 100 spostamenti.
// Ogni record del file impostor.bin è composto da: 
// - fascia oraria: valore intero che può assumere i valori da 1 a 24 e rappresenta la fascia oraria della giornata; 
// - stanza: stringa senza spazi contenente al più 20 caratteri (compreso il terminatore), contiene il nome della stanza dove si trova l’impostore. 
// Si scriva un programma in linguaggio C che dati i file tasks.txt, planning.bin e impostor.bin trovi, nel caso siano presenti, quali sono gli scienziati che vengono assassinati durante la giornata e stampi a video i loro nomi. Per ciascuno scienziato assassinato si stampi anche la fascia oraria in cui viene commesso l’omicidio. 
// Si organizzi opportunamente il programma in procedure e funzioni.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

typedef struct {
	int fascia_oraria;
	char incaricato[20];
	char mansione[30];
} pianificazione;

typedef struct {
	char mansione[30];
	char stanza[20];
	int ripetizioni;
} mansione;

typedef struct {
	int fascia_oraria;
	char stanza[20];
} spostamenti;

void readPianificazioni(pianificazione pianificazioni[], int *N) {
	FILE *fp;
	
	if((fp = fopen("planning.bin", "rb")) == NULL) {
		printf("Errore nell'apertura del file\n");
		exit(1);
	}

	*N = fread(pianificazioni, sizeof(pianificazione), DIM, fp);

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(2);
	}
}

void readSpostamenti(spostamenti spostamento[], int *N) {
	FILE *fp;
	
	if((fp = fopen("impostor.bin", "rb")) == NULL) {
		printf("Errore nell'apertura del file\n");
		exit(1);
	}

	*N = fread(spostamento, sizeof(pianificazione), DIM, fp);

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(2);
	}
}

void printPianificazioni(pianificazione pianificazioni[], int N) {
	int i;
	for(i=0; i<N; i++) {
		printf("Fascia oraria: %d\n",pianificazioni[i].fascia_oraria);
		printf("Incaricato: %s\n",pianificazioni[i].incaricato);
		printf("Mansione: %s\n",pianificazioni[i].mansione);
		printf("\n\n");
	}
}

void printMansioni(mansione mansioni[], int N) {
	int i;
	for(i=0; i<N; i++) {
		printf("Mansione: %s\n", mansioni[i].mansione);
		printf("Stanza: %s\n", mansioni[i].stanza);
		printf("Ripetizioni: %d\n", mansioni[i].ripetizioni);
		printf("\n\n");
	}
}

void printSpostamenti(spostamenti spostamento[], int N) {
	int i;
	for(i=0; i<N; i++) {
		printf("Fascia oraria: %d\n",spostamento[i].fascia_oraria);
		printf("Stanza: %s\n",spostamento[i].stanza);
		printf("\n\n");
	}
}

void readMansioni(mansione mansioni[], int *N) {
	FILE *fp;
	int i;

	if((fp = fopen("tasks.txt", "rt")) == NULL) {
		printf("Errore nell'apertura del file\n");
		exit(1);
	}

	while(fscanf(fp, "%s %s %d", mansioni[*N].mansione, mansioni[*N].stanza, &mansioni[*N].ripetizioni) != EOF) {
		(*N)++;
	}

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(2);
	}
}

void mansioniNonSvolte(mansione M[], int N1, pianificazione P[], int N2) {
	int i, j;
	for(i=0; i<N1; i++) {
		int t = 0;

		for(j=0; j<N2; j++) {
			if((strcmp(P[j].mansione, M[i].mansione)) == 0) {
				t++;
			}
		}
		if(t < M[i].ripetizioni) {
			printf("[%s] svolta [%d] volte, doveva essere eseguita [%d] volte\n",M[i].mansione, t, M[i].ripetizioni);
		}
	}
	printf("\n\n");
}

int main() {
	pianificazione pianificazioni[DIM];
	mansione mansioni[DIM];
	spostamenti spostamento[DIM];
	char decessi[DIM];
	int N_pianificazioni;
	int N_mansioni = 0;
	int N_spostamenti;
	int N_decessi = 0;
	int i, j, z, x;

	readPianificazioni(pianificazioni, &N_pianificazioni);
	readMansioni(mansioni, &N_mansioni);
	//printPianificazioni(pianificazioni, N_pianificazioni); // DEBUG -> .fascia_oraria .incaricato .mansione
	//printMansioni(mansioni, N_mansioni); // DEBUG -> .mansione .stanza .ripetizioni

	mansioniNonSvolte(mansioni, N_mansioni, pianificazioni, N_pianificazioni);

	/*
		PARTE 2
	*/
	readSpostamenti(spostamento, &N_spostamenti);
	//printSpostamenti(spostamento, N_spostamenti); // DEBUG -> .fascia_oraria .stanza

	for(z=0; z<N_spostamenti; z++) {
		printf("Il killer alle %d si trova in %s\n", spostamento[z].fascia_oraria, spostamento[z].stanza);
		for(i=0; i<N_pianificazioni; i++) {
			for(j=0; j<N_mansioni; j++) {
				if(
					(pianificazioni[i].fascia_oraria == spostamento[z].fascia_oraria) &&
					strcmp(mansioni[j].stanza, spostamento[z].stanza) == 0
				) {
					// CONTROLLA SE IL TIZIO è GIà MORTO
					printf("%s è stato ucciso alle %d in %s mentre eseguiva %s\n",
						pianificazioni[i].incaricato,
						pianificazioni[i].fascia_oraria,
						mansioni[j].stanza,
						mansioni[j].mansione
					);
				}
			}
		}
	}
}