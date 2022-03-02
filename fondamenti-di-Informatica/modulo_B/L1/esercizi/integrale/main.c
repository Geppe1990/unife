#include<stdio.h>
#include<math.h>
#include"integrale.h"

int main() {
	float a,b;

	printf("Inserire gli estremi dell'intervallo [a,b]: ");
	scanf("%f,%f", &a, &b);

	printf("\n\n** metodo dei rettangoli **\n\n");

	printf("integrale della funzione x^2: ");
	printf("%f\n",rettangoli(quadra, a, b, 100));

	printf("integrale della funzione x^3: ");
	printf("%f\n",rettangoli(cubo, a, b, 100));
	
	return 0;
}