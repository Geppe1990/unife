// Scrivere un programma in linguaggio C che legga due parole da tastiera.
// Le parole possono contenere al più 100 caratteri ciascuna.
// Si verifichi se la seconda parola è contenuta nella prima.

// es:
// Inserisci parola: sassofonista
// Parola da cercare: asso
// La parola asso è contenuta in sassofonista
// OPPURE
// Parola da cercare: sana
// La parola sana non è contenuta in sassofonista
#include <stdio.h>
#define DIM 100

int main() {
	char s1[DIM];
	char s2[DIM];
	printf("Inserisci parola: ");
	scanf("%s", s1);
	printf("Parola da cercare: ");
	scanf("\n%s", s2);
	
	int presente;
	int i = 0;
	int j = 0;
	while(s2[j] != '\0' && s1[i] != '\0') {
		presente = 0;
		if(s1[i] == s2[j]){
			presente = 1;
			i++;
			j++;
		} else {
			presente = 0;
			j=0;
			i++;
		}
	}

	if(presente)
		printf("La parola %s è contenuta in %s\n", s2, s1);
	else
		printf("La parola %s non è contenuta in %s\n", s2, s1);
}