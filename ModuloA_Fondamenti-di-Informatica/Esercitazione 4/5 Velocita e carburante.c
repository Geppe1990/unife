// Un automobilista deve percorrere un tratto autostradale di 40km tutti i giorni e 
// si chiede a che velocità gli conviene percorrerlo, considerando il costo della 
// benzina e il tempo di viaggio.

// Vuole quindi scrivere un programma che, data in input la velocità da tenere (in km/h), 
// calcola
// 1. quanti minuti dura il viaggio
// 2. quanta benzina consumerà per percorrere il tratto di 40 km.

// Per stimare il consumo di benzina, ha trovato un articolo
// (https://www.researchgate.net/publication/311703927_Urban_Transportation_Solutions_for_the_CO2_Emissions_Reduction_Contributions) 
// che riporta questa formula:

// C = 0.0019*V^2 - 0.2506*V + 13.74

// dove
// - V è la velocità in km/h
// - C è il consumo di benzina in litri per 100km


// P.S.: La formula per ricavare il tempo percorso deriva dalla legge
// s=v*t, dove s è lo spazio percorso, v è la velocità e t è il tempo impiegato.
// Ricordarsi di eseguire le dovute conversioni per calcolare il tempo in minuti

#include <stdio.h>
#include <math.h>

int main() {
	int velocita;
	int minuti;
	float consumo;
	int lunghezza = 40;
	velocita = 200;
	minuti = (float)lunghezza/velocita * 60;
	consumo = 0.0019*pow(velocita, 2) - 0.2506*velocita + 13.74;
	printf("Per fare %dkm a una velocità di %dkm/h ci vogliono %d minuti, ", lunghezza, velocita, minuti);
	printf("Consumando %f litri di carburante\n", consumo);

}