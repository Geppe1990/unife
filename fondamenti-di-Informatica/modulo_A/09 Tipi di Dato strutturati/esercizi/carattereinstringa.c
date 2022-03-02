// Leggi una stringa ed un carattere, verificare se il carattere compare nella stringa

#include <stdio.h>

main() {
	char s[30];
	char c;
	int i;
	int found = 0;

	printf("Inserisci una stringa: ");
	scanf("%s", s);
	printf("Inserisci un carattere: ");
	scanf(" %c", &c);

	for(i=0; s[i] != '\0'; i++) {
		if(s[i] == c) {
			found = 1;
		}
	}

	if(found) {
		printf("Il carattere %c è presente nella stringa %s\n", c, s);
	} else {
		printf("Il carattere %c NON è presente nella stringa %s\n", c, s);
	}
}