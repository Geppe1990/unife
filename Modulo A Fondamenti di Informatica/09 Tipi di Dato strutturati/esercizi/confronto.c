// - Inserisci da tastiera 2 stringhe
// - Mostra quale viene prima

#include <stdio.h>
#define DIM 10

int main() {
	char s1[DIM], s2[DIM];
	int ris, i = 0;
	//ris -> negativa se s1 precede s2
	//ris -> positiva se s2 precede s1
	//ris -> nulla se s1 uguale a s2

	printf("Inserisci il primo nome: ");
	scanf("%s", s1);
	printf("Inserisci il secondo nome: ");
	scanf("%s", s2);

	while(s1[i] != '\0' & s2[i] != '\0' && s1[i] == s2[i]) {
		i++;
	}
	
	ris = s1[i] - s2[i];

	if(ris < 0)
		printf("%s precede %s\n", s1, s2);
	else if(ris == 0)
		printf("%s è uguale a %s\n", s1, s2);
	else
		printf("%s precede %s\n", s2, s1);

	return 0;
}