// Creare una funzione con interfaccia:
// float square(float x)
// che restituisce il quadrato del parametro x.

// Creare un’altra funzione, con interfaccia:
// float cube(float x)
// che restituisce il cubo del valore x.

// Progettare quindi e codificare un programma che legge un float da tastiera e 
// visualizza il suo quadrato ed il suo cubo. 
// Per calcolare il quadrato ed il cubo si devono utilizzare le due funzioni sopra definite.
#include <stdio.h>

float square(float x) {
	return x * x;
}

float cube(float x) {
	return x * x * x;
}

int main() {
	float sq, cu, x;
	printf("Inserisci un numero: ");
	scanf("%f", &x);
	sq = square(x);
	cu = cube(x);
	printf("Il quadrato di %f è %f\n", x, sq);
	printf("Il cubo di %f è %f\n", x, cu);
}