// Si scriva una funzione int somma_potenze(int a, int n); 
// che dati a e n deve calcolare la sommatoria per i che varia da 1 a n di a^i.
// A tal fine si scriva e si usi una funzione int potenza(int x, int y); 
// che dati x e y deve calcolare x^y usando come operazione primitiva il prodotto.

// Si realizzi quindi un programma che prende in ingresso a ed n e stampi a video 
// il risultato della sommatoria.

// Esempio
// Se a = 2 e i = 5 il programma dovrà calcolare:
// 2^1 + 2^2 + 2^3 + 2^4 + 2^5 = 2 + 4 + 8 + 16 + 32 = 62

#include <stdio.h>

int potenza(int x, int y) {
	// x = 2, y = 3
	// 2 * 2 * 2
	int potenza = 1, i;

	for(i=1; i<=y; i++) {
		potenza *= x;
	}

	return potenza;
}

int somma_potenze(int a, int n) {
	int somma = 0, i;
	for(i=1; i<=n; i++) {
		somma += potenza(a, i);
	}
	return somma;
}

int main() {
	int a, b;
	printf("Inserisci base: ");
	scanf("%d", &a);
	printf("Inserisci esponente: ");
	scanf("%d", &b);
	printf("La sommatoria di %d^%d è %d\n", a, b, somma_potenze(a, b));
}