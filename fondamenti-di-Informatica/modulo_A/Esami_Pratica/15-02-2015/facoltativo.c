#include <stdio.h>
#include "fun.h"

int main() {
	idrante idranti[DIM];
	int N = lettura(idranti);
	squadra squadre[DIM];
	int N2 = getSquadre(idranti, squadre, N);
	squadra squadra_max_km;

	//PARTE 2
	getTotalKm(squadre, N2, &squadra_max_km);
	printf("La squadra che ha percorso più km è la squadra %s con %fkm\n",
	squadra_max_km.nome, squadra_max_km.distanza);
}