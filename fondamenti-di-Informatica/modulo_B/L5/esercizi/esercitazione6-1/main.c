#include <stdio.h>
#include <string.h>
#define DIM 100
#define DIM_NOME 20
#define DIM_TELEFONO 16

typedef struct {
	char nome[DIM_NOME];
	char numero_telefono[DIM_TELEFONO];
} elemento;
typedef elemento rubrica[DIM];

typedef enum {false, true} Boolean;

void stampa(rubrica R, int n) {
	for(int i=0; i<n; i++) {
		printf("%d - %s - %s\n", i, R[i].nome, R[i].numero_telefono);
	}
}

int individua(rubrica R, int n, char nome[DIM_NOME]) {
	int index = -1;

	for(int i=0; i<n; i++) {
		if(strcmp(nome, R[i].nome) == 0)
			index = i;
	}

	return index;
}

void inserimento(rubrica R, int *n) {
	char nome[DIM_NOME];
	char telefono[DIM_TELEFONO];

	printf("Inserisci nome: ");
	scanf("%s", nome);
	printf("Inserisci telefono: ");
	scanf("%s", telefono);

	if(individua(R, *n, nome) == -1) {
		printf("Il nome NON è presente, puoi inserirlo\n");
		printf("%d", *n);

		strcpy(R[*n].nome, nome);
		strcpy(R[*n].numero_telefono, telefono);
		(*n)++;
	} else {
		printf("Il nome è presente, NON puoi inserirlo\n");
	}
}

void cancellazione(rubrica R, int *n) {
	char nome[DIM_NOME];
	printf("Inserisci nome: ");
	scanf("%s", nome);

	int search = individua(R, *n, nome);
	if(search == -1) {
		printf("Il nome NON è presente\n");
	} else {
		for(int i = search; i<(*n); i++) {
			strcpy(R[i].nome, R[i+1].nome);
			strcpy(R[i].numero_telefono, R[i+1].numero_telefono);
		}
		(*n)--;
	}
}

void cerca_numero(rubrica R, int n) {
	char nome[DIM_NOME];
	printf("Inserisci il nome da cercare: ");
	scanf("%s", nome);
	
	int search = individua(R, n, nome);
	if(search == -1) {
		printf("Numero non presente\n");
	} else {
		printf("%s\n", R[search].numero_telefono);
	}
}


void termina(Boolean *exit) {
	*exit = true;
}

int main() {
	Boolean exit = false;
	int length = 8;
	int choice;
	rubrica R = {
		"Cyrus", "3462364389",
		"Frederick","3462364381",
		"Hannibal","3462364382",
		"Draco","3462364383",
		"Lucius","3462364384",
		"Elijah","3462364385",
		"Jason","3462364386",
		"Pamela","3462364387"
	};

	while(exit == false) {
		printf("Cosa vuoi fare? (0 esci): ");
		scanf("%d", &choice);

		if(choice == 1) { inserimento(R, &length); }
		if(choice == 2) { stampa(R, length); }
		if(choice == 3) { cancellazione(R, &length); }
		if(choice == 4) { cerca_numero(R, length); }
		if(choice == 0) { termina(&exit); }
	}
}