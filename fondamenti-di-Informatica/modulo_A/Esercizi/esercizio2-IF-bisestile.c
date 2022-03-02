// Progettare un programma che prende in ingresso il valore di un anno (es.: 1492, 2003…) 
// e stabilisce se tale anno è bisestile o meno.

// Si ricorda che un anno è bisestile se è divisibile per 4 e, qualora sia l'anno di 
// inizio di un secolo, solo se è divisibile anche per 400.

#include <stdio.h>

main() {
	int anno;
	printf("Inserisci un anno: ");
	scanf("%d", &anno);

	if(anno % 100 == 0) {
		if(anno % 4 == 0 && anno % 400 == 0) {
			printf("BISESTILE\n");
		} else {
			printf("NON BISESTILE\n");
		}
	} else {
		if(anno % 4 == 0) {
			printf("BISESTILE\n");
		} else {
			printf("NON BISESTILE\n");
		}
	}
}