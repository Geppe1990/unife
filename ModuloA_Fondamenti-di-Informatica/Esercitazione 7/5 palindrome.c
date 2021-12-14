// Scrivere un programma che riceve in ingresso una parola inserita da tastiera. 
// Si consideri che la parola può contenere solo caratteri minuscoli, 
// e complessivamente al massimo 30 caratteri.
// Il programma deve svolgere le seguenti operazioni:
// - Visualizzare la parola inserita;
// - Verificare se la parola è palindroma;
// - Visualizzare il risultato.

// N.B.: Una parola si dice "palindroma" se può essere letta indifferentemente 
// da sinistra verso destra e da destra verso sinistra. Ad esempio, 
// le seguenti parole sono palindrome: otto, ingegni, anna, osso.

#include <stdio.h>
#include <string.h>
#define DIM 31

int main(){
	char s[DIM] = "otto";
	int l = 0, i, j, palindroma;
	printf("Inserisci una stringa: ");
	scanf("%s", s);
	printf("Hai inserito la stringa: %s\n", s);
	
	for(i=0; s[i] != '\0'; i++)
		l++;
	printf("La stringa è lunga %d caratteri\n", l);
	
	i=0;
	j=l-1;
	palindroma=1;
	
	printf("%s al contrario è ", s);
	while(i<l) {
		printf("%c", s[j]);

		if(s[i] != s[j])
			palindroma = 0;
		i++;
		j--;
	}
	printf("\n");
	
	if(palindroma)
		printf("La parola è palindroma\n");
	else {
		printf("La parola NON è palindroma\n");
	}
}