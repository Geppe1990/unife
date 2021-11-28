// Si scriva un programma C che definisca un tipo di dato Studente:
// Ogni studente è caratterizzato da:
// - matricola (intero);
// - nome (stringa contenente al più 20 caratteri compreso il terminatore);
// - cognome (stringa contenente al più 20 caratteri compreso il terminatore).

// Il programma acquisisca i dati di al massimo 100 studenti salvandone le informazioni in un vettore di strutture.
// L’inserimento termina quando si inserisce una matricola uguale a 0.

// Stampi i nomi e i cognomi di tutti gli studenti inseriti.
// Chieda all'utente il nome e cognome di uno studente, lo cerchi nel vettore e ne stampi la matricola.

#include <stdio.h>
#include <string.h>

typedef struct {
	int matricola;
	char nome[20];
	char cognome[20];
} studente;

int main() {
	studente studenti[100];
	int length = 0;
	int exit = 0;
	int i;
	char search_nome[20];
	char search_cognome[20];
	int trovato = 0;

	while(exit == 0) {
		printf("\n[%d] studente\n", length);
		printf("Inserisci la matricola: ");
		scanf("%d", &studenti[length].matricola);
	
		if(studenti[length].matricola == 0)
			exit = 1;
		else {
			printf("Inserisci il nome: ");
			scanf("%s", studenti[length].nome);
			printf("Inserisci il cognome: ");
			scanf("%s", studenti[length].cognome);
			length++;
		}
	}

	printf("\n");
	
	for(i=0; i<length; i++) {
		printf("\n----------\n");
		printf("MATRICOLA: %d\n", studenti[i].matricola);
		printf("NOME: %s\n", studenti[i].nome);
		printf("COGNOME: %s\n", studenti[i].cognome);
		printf("----------\n");
	}

	printf("Inserisci il nome da cercare: ");
	scanf("%s", search_nome);
	printf("Inserisci il cognome da cercare: ");
	scanf("%s", search_cognome);

	for(i=0; i<length; i++) {
		int find_nome = strcmp(studenti[i].nome, search_nome);
		int find_cognome = strcmp(studenti[i].cognome, search_cognome);
		
		if(find_nome == 0 && find_cognome == 0) {
			trovato = 1;
			printf("La matricola di %s %s è %d\n", studenti[i].nome, studenti[i].cognome, studenti[i].matricola);
		}
	}

	if(trovato == 0) {
		printf("Utente non trovato\n");
	}
}