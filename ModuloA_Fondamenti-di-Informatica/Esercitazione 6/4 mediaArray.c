// Si scriva un programma C che:
// - Legga da tastiera 10 elementi interi e li inserisca in un array opportuno
// - Calcoli la media aritmetica degli elementi dell'array;
// - Chieda all'utente se vuole che vengano stampati i valori 
// dell'array minori o uguali, oppure maggiori, della media;
// - Legga la risposta (char: '<' per 'minore o uguale', '>' per 'maggiore');
// - Stampi a video gli elementi desiderati

#include <stdio.h>
#define DIM 10

int main() {
	int v[10] = {1,2,3,4,5,6,7,8,9,10}, i;
	float media = 0;
	char scelta;

	for(i=0; i<DIM; i++) {
		media += v[i];
	}
	media /= DIM;
	printf("%.2f\n", media);
	printf("Vuoi vedere i valori dell'array minori o uguali[<], oppure maggiori[>], della media? ");
	scanf("%c", &scelta);

	for(i=0; i<DIM; i++) {
		if(scelta == '<' && v[i] <= media) {
			printf("%d ", v[i]);
		} else if(scelta == '>' && v[i] > media){
			printf("%d ", v[i]);
		}
	}
}