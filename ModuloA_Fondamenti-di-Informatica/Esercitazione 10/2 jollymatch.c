// Si scriva una funzione jolly_match che ha come parametri due stringhe, di cui la seconda può contenere il carattere jolly '?'.
// Il valore di ritorno della funzione è 1 se le stringhe "fanno match" e 0 altrimenti.

// Le stringhe "fanno match" se i caratteri nelle stesse posizioni sono uguali oppure se nella seconda c’è il carattere jolly '?'

// Esempio:
// jolly_match("anguria", "a?gur??") restituisce 1
// jolly_match("augurai", "a?gur??") restituisce 1
// jolly_match("augurai", "a?guri?") restituisce 0

// Nel main si leggano da tastiera due stringhe e si stampi tra chioccioline la parola "si" se fanno match, "no" altrimenti

#include <stdio.h>

int jolly_match(char s1[], char s2[]) {
	int i = 0;
	int res = 1;
	while(s1[i] != '\0') {
		if(s1[i] != s2[i] && s2[i] != '?') {
			res = 0;
		}
		
		i++;
	}
	return res;
}

int main() {
	if(jolly_match("anguria", "a?gur??")) {
		printf("\n@si@\n");
	} else printf("\n@no@\n");

	if(jolly_match("augurai", "a?gur??")) {
		printf("\n@si@\n");
	} else printf("\n@no@\n");

	if(jolly_match("augurai", "a?guri?")) {
		printf("\n@si@\n");
	} else printf("\n@no@\n");
}