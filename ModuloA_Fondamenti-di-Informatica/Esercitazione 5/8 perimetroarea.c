// Codificare in C la funzione int perimetro(int a, int b, int c) che, 
// dati i lati a, b, c di un triangolo, ne calcola il perimetro.

// Codificare in C la funzione float area(int a, int b, int c) che 
// restituisce l’area di un triangolo i cui lati misurano a, b, c. 
// A tal scopo si usi la formula di Erone (in allegato) dove p è la metà del perimetro.

// Si faccia uso di funzioni dove possibile.
// Definire un possibile main che prende in ingresso i tre lati di un 
// triangolo e stampa perimetro ed area.

#include <stdio.h>
#include <math.h>

int perimetro(int a, int b, int c) {
	return a + b + c;
}

float area(int a, int b, int c) {
	float p = (float)perimetro(a, b, c)/2;
	float area = sqrt(p * (p - a) * (p - b) * (p - c));
	return area;
}

int main() {
	int a, b, c, p;
	float ar;
	printf("Inserisci il lato A: ");
	scanf("%d", &a);
	printf("Inserisci il lato B: ");
	scanf("%d", &b);
	printf("Inserisci il lato C: ");
	scanf("%d", &c);
	p = perimetro(a, b, c);
	ar = area(a, b, c);
	printf("Perimetro: %dm\n", p);
	if(ar >= 0)
		printf("Area: %fm2\n", ar);
	else
		printf("Area non calcolabile\n");
}