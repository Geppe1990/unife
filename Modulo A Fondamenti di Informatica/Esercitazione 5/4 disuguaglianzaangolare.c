// Codificare in C la funzione int disuguaglianza triangolare(int a, int b, int c) 
// che restituisce:

// 1 se vale la disuguaglianza triangolare a <= b + c
// 0 altrimenti.

// Si progetti un programma che legge da tastiera tre lati di un triangolo, 
// poi applichi la funzione disuguaglianza triangolare per verificare se è possibile 
// costruire un triangolo di quelle dimensioni.

// N.B.: un triangolo sarà costruibile solamente se ogni suo lato è minore (o uguale) 
// della somma degli altri due.

#include <stdio.h>

int disuguaglianzatriangolare(int a, int b, int c) {
	int result = 0;
	
	if(a <= b + c && b <= a + c && c <= a + b)
		result = 1;

	return result;
}

int main() {
	int a, b, c;
	printf("Inserisci il lato a: ");
	scanf("%d", &a);
	printf("Inserisci il lato b: ");
	scanf("%d", &b);
	printf("Inserisci il lato c: ");
	scanf("%d", &c);
	int r = disuguaglianzatriangolare(a, b, c);

	if(r)
		printf("E' possibile costruire il triangolo\n");
	else
		printf("Non è possibile costruire il triangolo\n");
}