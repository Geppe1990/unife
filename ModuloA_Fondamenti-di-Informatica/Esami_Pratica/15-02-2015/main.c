#include <stdio.h>
#include "fun.h"

int main() {
	idrante idranti[DIM];
	int N = lettura(idranti);
	char squadra_distanza_massima[15];

	//PARTE 1	
	distanza_massima(idranti, N, squadra_distanza_massima);
	printf("Il massimo è della squadra %s\n", squadra_distanza_massima);
}