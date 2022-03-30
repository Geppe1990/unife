// Realizzare un programma C che, dato come argomento il nome di
// un file (di testo), ne visualizzi il contenuto a pagine (20 righe alla
// volta). Dopo la visualizzazione di ciascun gruppo di righe, chiedere
// all’utente se vuole visualizzare le successive 20 (o le restanti nel
// file se il file ha meno di 20 righe non ancora lette) o fermarsi.

// Se si utilizza un percorso relativo, il file col quale si vuole interagi-
// re (in questo caso leggere) deve trovarsi:

// nella stessa cartella dove si trovano i file .c e .h del progetto
// se si esegue il programma da Visual Studio
// nella stessa cartella che contiene il file eseguibile
// <nome_progetto>.exe (solitamente la sottocartella Debug)
// se si esegue il programma da terminale
// Alternativamente, è possibile utilizzare un percorso assoluto e il
// file può trovarsi in altre posizioni all’interno del file system.

#include <stdio.h>

#define NL 20

int main (int argc, char * argv[]) {
	int n;
	char risposta = 's';
	char stringa;
	FILE *fp;

	if (argc == 2) {
		fp = fopen(argv[1],"rt");

		if (fp == NULL) {
			printf("Errore di apertura");
			return -1;
		}

		while((!feof(fp)) && (risposta == 's')) {
			for(n = 1; (n <= NL) && (!feof(fp));) {
				fscanf(fp, "%c", &stringa);
				printf("%c", stringa);
				
				if (stringa == '\n') {
					n++;
				}
			}

			if (n > NL) {
				printf("Continua (s/n)? ");
				scanf(" %c", &risposta); // Lettura di un carattere quindi ricordarsi di usare ' '
			}
		
		}

	} 
	else {
		printf("Num. argomenti non corretto");
	}

	return 0;
}