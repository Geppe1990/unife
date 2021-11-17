// fascia -> fasce
// valigia -> valigie

// Se prima di cia o di gia c'è una vocale la i viene mantenuta, 
// se ci fosse una consonante no

#include <stdio.h>

void is_vocale() {
	int risultato = 0, i;
	char vocali[] = "aeiou";

	for(i=0; vocali[i] != '\0'; i++) {
		printf("i: %d - %c\n",i, vocali[i]);
	}
}

main() {
	is_vocale();
}