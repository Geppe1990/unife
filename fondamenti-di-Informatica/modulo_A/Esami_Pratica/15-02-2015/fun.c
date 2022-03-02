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
	return sqrt((idr.x * idr.x) + (idr.y * idr.y));
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

void getDistanza(idrante idranti[], squadra *squadre, int N) {
	int i;
	float x = 0;
	float y = 0;
	(*squadre).distanza = 0;
	for(i=0; i<N; i++) {
		float distanza = 0;
		if((strcmp(idranti[i].squadra, (*squadre).nome)) == 0) {
			int squadrax = x - idranti[i].x;
			int squadray = y - idranti[i].y;
			x = idranti[i].x;
			y = idranti[i].y;
			(*squadre).distanza += sqrt((squadrax * squadrax) + (squadray * squadray) );
		}
	}
}

int getSquadre(idrante idranti[], squadra squadre[], int N) {
	int i,j;
	int N2 = 0;

	for(i=0; i<N; i++) {
		int presente = 0;
		for(j=0; j<N2; j++) {
			if((strcmp(idranti[i].squadra, squadre[j].nome)) == 0) {
				presente = 1;
			}
		}
		if(presente == 0) {
			strcpy(squadre[N2].nome, idranti[i].squadra);
			N2++;
		}
	}

	for(i=0; i<N2; i++) {
		getDistanza(idranti, &squadre[i], N);
	}
	return N2;
}

void getTotalKm(squadra squadre[], int N, squadra *squadra_max_km) {
	int i;
	float max = squadre[0].distanza;
	for(i=0; i<N; i++) {
		if(squadre[i].distanza > max) {
			max = squadre[i].distanza;
			*squadra_max_km = squadre[i];
		}
	}
}