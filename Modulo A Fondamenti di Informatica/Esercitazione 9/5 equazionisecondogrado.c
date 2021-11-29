// Si scriva un programma in linguaggio C che, dati 3 valori a, b e c, fornisce le soluzioni dell’equazione di secondo grado:

// ax^2 + bx + c = 0

// Nel main, il programma deve:
// - leggere da tastiera i coefficienti a, b e c;
// - invocare una funzione "radici";
// - infine stampare i risultati.

// La funzione radici deve comunicare al main:
// - se le radici sono reali o no;
// - il valore delle radici (nel caso queste siano reali).

// Consiglio: una possibile interfaccia per la funzione radici è:
// int radici(float a, float b, float c, float* rad1, float* rad2);

#include <stdio.h>
#include <math.h>

int radici(float a, float b, float c, float* rad1, float* rad2) {
	int delta = pow(b, 2) - (4*a*c);

	if (delta >= 0) {
		(*rad1) = ((-b) + (float)sqrt((double)delta)) / (2 * a);
		(*rad2) = ((-b) - (float)sqrt((double)delta)) / (2 * a);
		return 1;
	}
	return 0;

}

int main() {
	float a, b, c;
	float x1, x2;
	printf("Inserisci A: ");
	scanf("%f", &a);
	printf("Inserisci B: ");
	scanf("%f", &b);
	printf("Inserisci C: ");
	scanf("%f", &c);

	if (radici(a, b, c, &x1, &x2))
		printf("%.0f x^2 + %.0f x + %.0f = 0 ha come soluzioni x1 = %.2f x2 = %.2f\n", a, b, c, x1, x2);
	else
		printf("%.0f x^2 + %.0f x + %.0f = 0 non ha soluzioni reali\n",a, b, c);
}