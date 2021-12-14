// - Scrivere un programma che legge una struttura frazione tramite una procedura 
// e la stampa tramite un'altra procedura

#include <stdio.h>

typedef struct {
	int numeratore;
	int denominatore;
} frazione;

void getData(frazione *f) {
	printf("Inserisci la frazione: ");
	scanf("%d/%d", &f->numeratore, &f->denominatore);
}

void printData(frazione f) {
	printf("La frazione inserita è: %d/%d\n", f.numeratore, f.denominatore);
}

void printDataComePuntatore(frazione *f) {
	printf("La frazione inserita è: %d/%d\n", f->numeratore, f->denominatore);
}

int main() {
	frazione f;
	getData(&f);
	printData(f);
	printDataComePuntatore(&f);
}