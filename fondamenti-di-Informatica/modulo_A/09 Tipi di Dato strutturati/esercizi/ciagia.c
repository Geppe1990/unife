// fascia -> fasce
// valigia -> valigie

// Se prima di cia o di gia c'è una vocale la i viene mantenuta, 
// se ci fosse una consonante no

#include <stdio.h>

int is_vocale(char c) {
	int risultato = 0, i;
	char vocali[] = "aeiou";

	for(i=0; vocali[i] != '\0'; i++) {
		if(vocali[i] == c) {
			risultato = 1;
		}
	}

	return risultato;
}

main() {
	char s1[] = "fascia";
	int i, vocale = 0;

	for(i=0; s1[i] != '\0'; i++) {
		if(s1[i] == 'c' || s1[i] == 'g') {
			if(s1[i+1] == 'i' && s1[i+2] == 'a') {
				vocale = is_vocale(s1[i-1]);

				if(vocale) {
					s1[i+2] = 'e';
				} else {
					s1[i+1] = 'e';
					s1[i+2] = '\0';
				}
			}
		}
	}
	printf("%s\n", s1);
}