// Svolgere l'esercizio SENZA utilizzare le funzioni messe a 
// disposizione dalla libreria "string".

// Si scriva un programma C che legga da tastiera una stringa, 
// se ne calcoli la lunghezza (int) e la si stampi a video fra 
// simboli @ (chiocciola/a commerciale).
// Successivamente si memorizzi la stringa ottenuta in input in 
// un'altra stringa ma invertita e poi si stampi a video il risultato 
// fra simboli @ (chiocciola/a commerciale) come indicato nella figura riportata di seguito.

#include <stdio.h>
#define DIM 10

int main() {
	char s[DIM], q[DIM];
	int l = 0, i;
	
	printf("Inserisci una stringa: ");
	scanf("%s", s);

	while(s[l] != '\0')
		l++;

	printf("La stringa è lunga @%d@ caratteri\n", l);

	for(i=0; i<=l; i++)
		q[i] = s[l-i-1];

	printf("%s\n", s);
	printf("%s\n", q);
}