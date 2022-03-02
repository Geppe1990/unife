// Scrivere un programma C che definisca la struttura “punto” 
// composta dalle sue coordinate x e y (float) in un piano cartesiano.
// Si richieda all’utente di inserire le coordinate di 4 punti (A, B, C, D).
// Si calcoli e si stampi a video il perimetro della figura (racchiuso tra @) 
// che ha per lati i segmenti: AB, BC, CD, DA.

// CONSIGLIO: Per calcolare la radice quadrata utilizzare la funzione double sqrt(double x) 
// della libreria math.
// Per verificare come utilizzare correttamente la funzione sqrt consultare 
// l'help di Visual Studio Community.

#include <stdio.h>
#include <math.h>

typedef struct {
	float x;
	float y;
} punto;

int main() {
	punto A, B, C, D;
	float d1, d2, d3, d4;
	float perimetro = 0;

	printf("Inserire il primo punto (X,Y): ");
	scanf("%f,%f", &A.x, &A.y);
	printf("Inserire il secondo punto (X,Y): ");
	scanf("%f,%f", &B.x, &B.y);
	printf("Inserire il terzo punto (X,Y): ");
	scanf("%f,%f", &C.x, &C.y);
	printf("Inserire il quarto punto (X,Y): ");
	scanf("%f,%f", &D.x, &D.y);

    d1 = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    d2 = sqrt((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y));
    d3 = sqrt((C.x - D.x) * (C.x - D.x) + (C.y - D.y) * (C.y - D.y));
    d4 = sqrt((D.x - A.x) * (D.x - A.x) + (D.y - A.y) * (D.y - A.y));

    perimetro = d1 + d2 + d3 + d4;

    /* stampa il perimetro */
    printf("Perimetro = %.2f\n", perimetro);
}