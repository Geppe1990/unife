#include <stdio.h>

main()
{
	int si, no, nonso, totale;
	printf("Domanda 1");
	scanf("%d", &si);
	printf("Domanda 2");
	scanf("%d", &no);
	printf("Domanda 3");
	scanf("%d", &nonso);

	totale = si + no + nonso;

	printf("Percentuale di si: %d\n", si);
	printf("Percentuale di no: %d\n", si);
	printf("Percentuale di non so: %d\n", nonso);
}