// - Data una stringa di caratteri, copiala in un altro array di caratteri (di lunghezza non inferiore)
// - ipotetizzando che la stringa sia ben formata, ovvero terminante con il carattere '\0
// - Scandire la stringa elemento per elemento, fino a trovare il terminatore '\0'
// - Nel fare ciò, copiare l'elemento nella posizione corrispondente dell'altro array
#include <stdio.h>

main() {
	char s[] = "Nel mezzo del cammin di";
	char s2[40];
	int i;
	
	for(i=0; s[i] != '\0'; i++) {
		s2[i] = s[i];
	}
	
	s2[i] = '\0';
	printf("%s\n", s2);
}