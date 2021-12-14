#include <stdio.h>

main()
{
	int a, b, somma;
	printf("Inserisci il primo numero: ");
	scanf("%d", &a);
	printf("Inserisci il secondo numero: ");
	scanf("%d", &b);
	somma = a + b;
	printf("La somma tra %d e %d è %d\n", a, b, somma);
}