
// Progettare e codificare in linguaggio C una procedura che dati tre interi (a, b, c) calcoli contemporaneamente il massimo (max) e il minimo (min). La procedura dovrà avere la seguente interfaccia:
// void minmax(int a, int b, int c, int* min, int* max);

// Scrivere poi un programma che utilizza tale procedura. Il programma, all'interno della funzione main, dovrà leggere da tastiera tre numeri interi, calcolare il massimo e il minimo invocando la procedura descritta sopra e stampare il risultato a video fra simboli @ (chiocciola/a commerciale) come riportato nell'immagine allegata.

#include <stdio.h>

void minmax(int a, int b, int c, int* min, int* max) {
	*min = a;
	*max = a;

	if(b > *max)
		*max = b;

	if(c > *max)
		*max = c;

	if(b < *min)
		*min = b;

	if(c < *min)
		*min = c;

}

int main() {
	int a, b, c, min, max;
	printf("Inserisci A: ");
	scanf("%d", &a);
	printf("Inserisci B: ");
	scanf("%d", &b);
	printf("Inserisci C: ");
	scanf("%d", &c);
	minmax(a,b,c, &min, &max);
	printf("Il minimo è %d\n", min);
	printf("Il massimo è %d\n", max);
}