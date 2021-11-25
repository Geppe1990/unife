// Si scriva un programma che prende in ingresso ore, minuti e secondi (interi) 
// della durata di un CD audio. Il programma deve stampare a video il valore corrispondente 
// in secondi fra simboli @ (chiocciola/a commerciale) 
// come indicato nella figura riportata di seguito.

// Nel main, si definiscano le variabili (intere): ore, minuti, secondi. 
// Il main dovrà invocare una funzione di conversione: 
// int tempo_to_sec(int ore, int minuti, int sec).
// Tale funzione prende in ingresso le 3 variabili e restituisce il 
// numero di secondi corrispondenti.

// Per tale calcolo si codifichino e si usino le seguenti funzioni:
// - int min_to_sec(int m) che, dato un numero di minuti m, restituisce il 
// numero di secondi corrispondente;
// - int ore_to_sec(int o) che, dato un numero di ore o, restituisce il 
// numero di secondi corrispondente.

// Per le funzioni si rispettino le interfacce indicate nel testo.
#include <stdio.h>

int min_to_sec(int m) {
	return m * 60;
}

int ore_to_sec(int o) {
	return o * 3600;
}

int tempo_to_sec(int ore, int minuti, int sec) {
	return sec + min_to_sec(minuti) + ore_to_sec(ore);
}

int main() {
	int ore, minuti, sec, totale;
	printf("Inserisci ore: ");
	scanf("%d", &ore);
	printf("Inserisci minuti: ");
	scanf("%d", &minuti);
	printf("Inserisci secondi: ");
	scanf("%d", &sec);

	totale = tempo_to_sec(ore, minuti, sec);
	printf("@");
	printf("%d", totale);
	printf("@\n");
}
