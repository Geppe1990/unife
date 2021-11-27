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
	char s1[DIM] = "sassofonista";
	char s2[DIM] = "asso";

	printf("Parola da cercare: %s\n", s2);
	
// s -> s1[0] ->
// a -> s1[1] -> s2[0] -> a
// s -> s1[2] -> s2[1] -> s
// s -> s1[3] -> s2[2] -> s
// o -> s1[4] -> s2[3] -> o
// f -> s1[5] ->
// o -> s1[6] ->
// n -> s1[7] ->
// i -> s1[8] ->
// s -> s1[9] ->
// t -> s1[10] ->
// a -> s1[1] ->
	int presente = 1;
	int i = 0;
	int j = 0;
	while(s2[i] != '\0' && presente) {
		if(s1[j] == s2[i]){
			i++;
			j++;
		} else {
			j++;
		}
	}

	if(presente)
		printf("La parola %s è contenuta in %s\n", s2, s1);
	else
		printf("La parola %s non è contenuta in %s\n", s2, s1);
}