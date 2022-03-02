// Si legga da tastiera un carattere c
// Se c è una lettera minuscola, si visualizzi "minuscola",
// se è maiuscola si visualizzi "maiuscola",
// se è un numero si visualizzi "numero"

#include <stdio.h>

main() {
	char C;

	printf("Inserisci un char: ");
	scanf("%c", &C);

	if(C >= 48 && C <= 57) {
		printf("%c è un NUMERO\n", C);
	}

	if(C >= 65 && C <= 90) {
		printf("%c è una lettera MAIUSCOLA\n", C);
	}

	if(C >= 97 && C <= 122) {
		printf("%c è una lettera MINUSCOLA\n", C);
	}
}