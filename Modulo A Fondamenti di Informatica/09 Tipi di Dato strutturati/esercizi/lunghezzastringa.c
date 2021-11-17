// Leggere da tastiera una stringa e dire qual è la sua lunghezza
#include <stdio.h>

main() {
	char s[100];
	int i;

	printf("Inserisci una stringa: ");
	scanf("%s", s);

	for(i=0; s[i] != '\0'; i++) {
		printf("%c", s[i]);
	}

	printf("\nLa stringa è lunga %d caratteri\n", i);
}