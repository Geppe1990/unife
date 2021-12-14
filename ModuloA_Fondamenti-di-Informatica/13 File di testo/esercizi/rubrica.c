// Un file di testo rubrica.txt contiene una rubrica del telefono, in cui per ogni persona sono memorizzati di seguito

// - nome (stringa di max 20 caratteri senza spazi, incluso terminatore)
// - indirizzo (stringa di max 30 caratteri incluso terminatore)
// - numero (stringa di max 15 caratteri incluso terminatore)

// Si scriva un programma C che legge da tastiera un nome, cerca la persona corrispondente nel file rubrica.txt e visualizza sullo schermo i dati della persona se trovata.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[20];
	char numero[15];
	char indirizzo[30];
} persona;

int main() {
	FILE *fp;
	char filename[] = "rubrica.txt";
	char filereadtype[] = "rt";
	persona persone[100];
	int length=0;
	int i;
	char nome[20];
	int trovato = 0;

	printf("Inserisci un nome: ");
	scanf("%s", nome);

	if((fp = fopen(filename, filereadtype)) == NULL) {
		printf("ERRORE NELL'APERTURA DEL FILE\n");
		exit(1);
	}

	while(fscanf(fp, "%s %s %s", persone[length].nome, persone[length].indirizzo, persone[length].numero) != EOF) {
		length++;
	}

	for(i=0; i<length; i++){
		if(strcmp(nome, persone[i].nome) == 0) {
			printf("Nome: %s\n", persone[i].nome);
			printf("Indirizzo: %s\n", persone[i].indirizzo);
			printf("Numero: %s\n", persone[i].numero);
			trovato = 1;
		}
	}

	if(!trovato){
		printf("Non ho trovato nessuno di nome %s\n", nome);
	}

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(2);
	}
}