#include <stdio.h>

main()
{
	int base, altezza, area, perimetro;
	printf("Inserisci la base: ");
	scanf("%d", &base);
	printf("Inserisci l'altezza: ");
	scanf("%d", &altezza);
	area = base * altezza;
	perimetro = (base * 2) + (altezza + 2);
	printf("L'area è %d e il perimetro è %d\n", area, perimetro);
}