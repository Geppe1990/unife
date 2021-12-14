// Programmare un convertitore di valuta:

// leggere un carattere che rappresenta la valuta;
// leggere un valore;
// leggere un ultimo carattere che rappresenta la valuta verso cui si vuole
// effettuare e stampare la conversione.

// Le valute sono e (euro), s (dollari), l (sterline). Impostare arbitrariamente 
// questi tassi di conversione:
// 1 e = 1,16 s
// 1 e = 0,85 l
// 0,85 l = 1,16 s
// 0,85 l = 1 e
// 1,16 s = 0,85 l

#include <stdio.h>

int main() {
	char valuta1;
	float valore;
	char valuta2;

	printf("Inserisci la valuta di partenza(e, l, s): ");
	scanf("%c", &valuta1);
	printf("Inserisci il valore: ");
	scanf("%f", &valore);
	printf("Inserisci la valuta finale(e, l, s): ");
	scanf("\n%c", &valuta2);

	printf("%f%c equivalgono a ", valore, valuta1);

	if(valuta1 == 's') {
		if(valuta2 == 'e')
			valore /= 1.16; //DA S A E

		if(valuta2 == 'l')
			valore = (valore/1.16)*0.85; // DA S A L
	}

	if(valuta1 == 'l') {
		if(valuta2 == 'e')
			valore = valore/0.85; // DA L a E
		
		if(valuta2 == 's') {
			valore = (valore/0.85)*1.16; // DA L a S
		}
	}

	if(valuta1 == 'e') {
		if(valuta2 == 's')
			valore = valore*1.16; //DA E a S
		
		if(valuta2 == 'l')
			valore = valore*0.85; //DA E a L
	}
	printf("%f%c\n",valore, valuta2);
}