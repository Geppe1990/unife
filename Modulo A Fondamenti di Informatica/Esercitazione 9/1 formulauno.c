// Un sistema di cronometraggio per la Formula 1 registra i tempi in millisecondi. Tuttavia tali tempi devono essere presentati in termini di minuti, secondi e millisecondi.

// Creare una procedura che, ricevuto in ingresso un tempo dato in millisecondi, fornisca al chiamante l’equivalente in termini di minuti, secondi, millisecondi.
// void fromMillisec(int millisec, int* mm, int* sec, int* min).

// Si realizzi un programma in linguaggio C. Il programma all'interno della funzione main chiede all’utente di inserire un valore di tempo in millisecondi, invoca la funzione fromMillisec per la conversione e stampa a video il tempo nel formato
// min:sec,millisec

#include <stdio.h>

void fromMillisec(int millisec, int* mm, int* sec, int* min) {
	*min = millisec/60000;
	millisec %= 60000;
	*sec = millisec/1000;
	millisec %= 1000;
	*mm = millisec;
}

int main() {
	int ms;
	int mm;
	int sec;
	int min;
	
	printf("Inserisci un tempo in millisec: ");
	scanf("%d", &ms);
	fromMillisec(ms, &mm, &sec, &min);
	printf("ris: %d:%d,%d\n", min, sec, mm);
}