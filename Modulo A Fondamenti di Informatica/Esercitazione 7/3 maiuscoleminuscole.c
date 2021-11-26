// Scrivere un programma C che chieda all’utente di 
// inserire due stringhe e verifichi se queste coincidono.

// Nel caso coincidano, si trasformino SOLAMENTE nella seconda 
// stringa i caratteri maiuscoli in minuscoli e viceversa e si verifichi nuovamente 
// il valore di uguaglianza, stampandone il risultato.

// Consiglio: sfruttare i codici ASCII dei caratteri 
// (i maiuscoli da 65 a 90, i minuscoli da 97 a 122) per le conversioni da 
// maiuscoli a minuscoli. Usare una somma o una sottrazione con 32 per le conversioni. 
// Per effettuare il confronto tra due stringhe utilizzare la funzione strcmp contenuta
//  nella libreria 'string'.

#include <stdio.h>
#include <string.h>
#define DIM 20
int main() {
	char s1[DIM], s2[DIM];
	int uguali, i;
	printf("Inserisci la prima stringa: ");
	scanf("%s", s1);
	printf("Inserisci la seconda stringa: ");
	scanf("%s", s2);
	if(strcmp(s2, s1) == 0) {
		printf("Le stringhe sono uguali, elaboro\n");
		printf("%s diventa ", s2);
		for(i=0; s2[i] != '\0'; i++) {
			if(s2[i] >= 65 && s2[i] <= 90)
				s2[i] += 32;
			else if(s2[i] >=97 && s2[i] <= 122)
				s2[i] -= 32;
		}

		printf("%s\n", s2);
		if(strcmp(s2, s1) == 0) {
			printf("Sono ancora uguali\n");
		} else
			printf("Non sono più uguali\n");
	} else
		printf("Le stringhe NON sono uguali\n");

}