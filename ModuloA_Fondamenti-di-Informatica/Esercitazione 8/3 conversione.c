// Scrivere un programma C che definisca la struttura “misuraUK” composta da 
// quattro interi (miglia, yarde, piedi, pollici), 
// e una struttura “misuraUE” composta da tre interi (km, metri, mm).

// Si richieda poi una misura inglese e si stampi a video la corrispondente misura europea.
// Ricordate che:
// - 1 miglio = 1760 yarde
// - 1 yarda = 3 piedi
// - 1 piede = 12 pollici
// - 1 pollice = 25,4 mm

// CONSIGLIO: Convertire prima la misura inglese tutta in millimetri dopodiché, 
// per ottenere la misura nella rappresentazione europea, convertire i millimetri in km, 
// metri, mm.

#include <stdio.h>

typedef struct {
	int miglia, yarde, piedi, pollici;
} misuraUK;

typedef struct {
	int km, metri, mm;
} misuraUE;

int main() {
	misuraUK uk;
	misuraUE eu;
	float mm;
	printf("Inserisci miglia: ");
	scanf("%d", &uk.miglia);
	printf("Inserisci yarde: ");
	scanf("%d", &uk.yarde);
	printf("Inserisci piedi: ");
	scanf("%d", &uk.piedi);
	printf("Inserisci pollici: ");
	scanf("%d", &uk.pollici);


	mm = uk.pollici*25.4;
	mm += uk.piedi*12*25.4;
	mm += uk.yarde*3*12*25.4;
	mm += uk.miglia*1760*3*12*25.4;

	eu.km = mm/1000000;
	mm = (int)mm%1000000;
	eu.metri = mm/1000;
	mm = (int)mm%1000;
	eu.mm = mm;

	printf("%d km\n", eu.km);
	printf("%d metri\n", eu.metri);
	printf("%d mm\n", eu.mm);
}