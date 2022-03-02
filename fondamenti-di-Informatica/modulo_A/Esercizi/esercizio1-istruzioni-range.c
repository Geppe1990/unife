// Leggere da tastiera due numeri e stampare tutti i numeri interi compresi nell'intervallo

#include <stdio.h>

main() {
	int inf, sup;

	printf("Inserisci limite inferiore: ");
	scanf("%d", &inf);
	printf("Inserisci limite superiore: ");
	scanf("%d", &sup);

	while(inf <= sup) {
		printf("%d ", inf);
		inf++;
	}
	printf("\n");

}