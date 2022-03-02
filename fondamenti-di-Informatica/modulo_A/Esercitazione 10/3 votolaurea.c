// Uno studente deve calcolare la media dei suoi esami per la laurea. Per ogni esame si hanno:
// - nome: stringa contenente al massimo 20 caratteri, incluso il terminatore;
// - crediti: intero;
// - voto: intero.
// L’università necessita sia della media aritmetica sia della media pesata. Nella media pesata si considerano i crediti come pesi.

// Esempio
// - Informatica -> 15 crediti, voto 30
// - Inglese -> 6 crediti, voto 20
// Media aritmetica = (30 + 20) / 2 = 25.00
// Media pesata = (30*15 + 20*6) / (15+6) = 27.14

// Si scriva un programma C che:
// - Legge da tastiera un opportuno array di strutture che contiene gli esami sostenuti dallo studente. Gli esami sono al massimo 20. La lettura va effettuata in una opportuna funzione da invocare nel main.
// - Calcola media pesata e media aritmetica tramite una funzione da invocare nel main.
// - Nel main, stampa i risultati.

#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[20];
	int crediti;
	int voto;
} esame;

void calcolaMedia(float *media_pesata, float *media_aritmetica, esame esami[], int length) {
	int i;
	float crediti = 0;
	for(i=0; i<length; i++) {
		*media_aritmetica += esami[i].voto;
		*media_pesata += esami[i].voto * esami[i].crediti;
		crediti += esami[i].crediti;
	}

	*media_pesata /= crediti;
	(*media_aritmetica) /= length;
}

int leggiEsami(esame esami[]) {
	int i = 0;
	char nome[20];
	int continua = 1;
	
	do {
		printf("Inserisci nome del %d esame: ", i);
		scanf("%s", esami[i].nome);
		printf("Inserisci crediti del %d esame: ", i);
		scanf("%d", &esami[i].crediti);
		printf("Inserisci voto del %d esame: ", i);
		scanf("%d", &esami[i].voto);
		printf("Vuoi continuare? (1 SI - 0 NO) ");
		scanf("%d", &continua);
		i++;
	}while (continua);

	return i;
}

void printArray(esame esami[], int length) {
	int i;
		
	for(i=0; i<length; i++) {
		printf("Nome: %s\n", esami[i].nome);
		printf("Crediti: %d\n", esami[i].crediti);
		printf("Voto: %d\n", esami[i].voto);
	}
}

void printMedia(float media_aritmetica, float media_pesata) {
	printf("Media Aritmetica: %.2f\n", media_aritmetica);
	printf("Media Pesata: %.2f\n", media_pesata);
}

int main() {
	esame esami[20];
	float media_pesata = 0;
	float media_aritmetica = 0;
	int length = leggiEsami(esami);

	printArray(esami, length);
	calcolaMedia(&media_pesata, &media_aritmetica, esami, length);
	printMedia(media_aritmetica, media_pesata);
}