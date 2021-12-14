// Scrivere un programma in C che chieda all’utente di inserire 
// due stringhe e poi esegua le seguenti operazioni (senza utilizzare la libreria 'string'):

// - Confronti le due stringhe e stampi a video se le due stringhe coincidono o meno;
// - Stampi a video la lunghezza delle due stringhe;
// - Concateni la seconda stringa alla prima stringa e stampi a video il risultato;
// - Copi la stringa ottenuta dalla concatenazione in una nuova stringa e la stampi a video.

// N.B. Non usare mai spazi quando si utilizza la scanf per leggere una stringa. 
// Nella lettura della stringa gli spazi sono considerati separatori.

#include <stdio.h>
#define DIM 20

int main() {
	char a[DIM], b[DIM], c[DIM];
	int i, j, coincidono = 1, l1 = 0, l2 = 0;
	printf("Inserisci la prima stringa: ");
	scanf("%s", a);
	printf("Inserisci la seconda stringa: ");
	scanf("%s", b);
	
	printf("%s\n", a);
	printf("%s\n", b);

	for(i=0; a[i] != '\0' && b[i] != '\0'; i++)
		if(a[i] != b[i])
			coincidono = 0;

	if(coincidono)
		printf("Le stringhe coincidono\n");
	else
		printf("Le stringhe NON coincidono\n");

	while(a[l1] != '\0')
		l1++;

	while(b[l2] != '\0')
		l2++;

	i = 0;
	while(b[i] != '\0') {
		if(a[i] == '\0') {
			for(j=0; b[j] != '\0'; j++) {
				a[i] = b[j];
				i++;
			}
		}
		i++;
	}

	for(i=0; a[i] != '\0'; i++) {
		c[i] = a[i];
	}

	printf("La prima stringa è lunga %d\n", l1);
	printf("La seconda stringa è lunga %d\n", l2);
	printf("Prima stringa concatenata alla seconda:\n%s\n\n", a);
	printf("La nuova stringa :\n%s", c);
}