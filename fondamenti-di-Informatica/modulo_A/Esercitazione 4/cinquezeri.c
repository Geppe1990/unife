// Scrivere un programma C che legge una sequenza di interi e termina
// quando l'utente inserisce 5 zeri consecutivi. Esempio:
// Inserisci una sequenza:
// 1
// 0
// 1
// 0
// 0
// 3
// 0
// 0
// 1
// 0
// 0
// 0
// 0
// 0

// Gli ultimi 5  valori sono tutti zero.

#include <stdio.h>
int i=0, num;

int main() {

	do {
		printf("Inserisci un intero: ");
		scanf("%d", &num);
		if(num == 0) {
			i++;
			printf("Hai inserito %d zeri\n", i);
		} else
			i = 0;
	}while(i<5);
}