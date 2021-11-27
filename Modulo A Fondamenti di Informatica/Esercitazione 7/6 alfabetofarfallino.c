// Scrivere un programma che legga una parola introdotta da tastiera. 
// La parola può contenere complessivamente al più 100 caratteri.

// Il programma deve svolgere le seguenti operazioni:
// - Visualizzare la parola inserita e la sua lunghezza;
// - Costruire una nuova parola in cui tutte le vocali siano sostituite con 3 caratteri: 
// la vocale + carattere ‘f’ + la vocale;
// - Il programma deve memorizzare la nuova parola in una opportuna variabile;
// - Visualizzare la nuova parola e la sua lunghezza.

// Esempio:
// “ciao” -> “cifiafaofo”
// “casa” -> “cafasafa”

#include <stdio.h>
#include <string.h>
#define DIM 101

int isVocale(int n) {
	if(
		n == 65 || n == 69 || n == 73 || n == 79 || n == 85 ||
		n == 97 || n == 101 || n == 105 || n == 111 || n == 117
	)
		return 1;
	else
		return 0;	
}

int main() {
	char s1[DIM];
	char s2[DIM];
	int l = 0, i, j = 0;
	printf("Inserisci una stringa: ");
	scanf("%s", s1);

	for(i=0; s1[i] != '\0'; i++)
		l++;
	printf("Hai inserito la stringa %s\n", s1);
	printf("La stringa ha %d caratteri\n", l);

	for(i=0; i < l; i++) {
		if(isVocale(s1[i])) {
			s2[j] = s1[i];
			s2[j+1] = 'f';
			s2[j+2] = s1[i];
			j+=3;
		} else {
			s2[j] = s1[i];
			j++;
		}
		s2[j] = '\0';
	}
	printf("%s\n", s2);
}