#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp;
	char nomefile[50];
	char c;

	printf("Quale file apro? ");
	scanf("%s", nomefile);
	if((fp = fopen(nomefile, "rt")) == NULL) {
		printf("Errore nell'apertura di %s\n", nomefile);
		exit(1);
	}

	while(fscanf(fp, "%c", &c) == 1) {
	// while(!feof(fp)) { //Si potrebbe fare anche così, ma nel metodo sopra si ferma subito
	// se fscanf ritorna 0 (nessun elemento)
	// fscanf(fp, "%c", &c);
		printf("%c", c);
	}

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file\n");
		exit(2);
	}
}