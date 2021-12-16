#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fun.h"

int lettura(idrante idr[]) {
	int n = 0, i;
	FILE *fp;

	if((fp=fopen("idranti.bin", "rb")) == NULL) {
		printf("Errore nell'apertura del file");
		exit(1);
	}

	n = fread(idr, sizeof(idrante), DIM, fp);

	if(fclose(fp) != 0) {
		printf("Errore nella chiusura del file");
		exit(2);
	}
	
	for(i=0; i<n; i++) {
		printf("%d\t%s\t%d\t%d\n", i, idr[i].squadra, idr[i].x, idr[i].y);
	}

	return n;
}

float distanza_euclidea(idrante idr) {
	return sqrt(pow(idr.x, 2) + pow(idr.y, 2));
}

void distanza_massima(idrante idranti[], int n, char squad[]) { 
	int i, j;
	float max = distanza_euclidea(idranti[0]);
	
	for(i=0; i<n; i++) {
		float calc = distanza_euclidea(idranti[i]);
		
		if(calc > max) {
			max = distanza_euclidea(idranti[i]);
			strcpy(squad, idranti[i].squadra);
		}
	}
	printf("Il massimo è %f della squadra %s\n", max, squad);
}