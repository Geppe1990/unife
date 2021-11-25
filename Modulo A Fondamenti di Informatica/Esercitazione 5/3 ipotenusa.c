// Codificare in C la funzione float ipotenusa(int a, int b) che, 
// dati i cateti a e b di un triangolo rettangolo, restituisce il valore dell’ipotenusa.

// Per calcolare la radice quadrata si utilizzi la funzione di libreria sqrt(x) 
// definita nella libreria math.h
// Definire un possibile main che legga da tastiera i valori dei due cateti di 
// un triangolo rettangolo e stampi il valore dell’ipotenusa.

// CONSIGLIO: per creare un eseguibile da linea di comando con la libreria math.h
//  utilizzare lo script seguente:
// gcc -g -lm <nomeFile.c> -o <nomeEseguibile>

#include <stdio.h>
#include <math.h>

float ipotenusa(int a, int b) {
	return sqrt(pow(a, 2) + pow(b, 2));
}


int main() {
	int a = 8;
	int b = 3;
	float c = ipotenusa(a, b);
	printf("L'ipotenusa è %f\n", c);
}