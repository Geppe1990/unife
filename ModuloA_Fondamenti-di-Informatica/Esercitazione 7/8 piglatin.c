// Scrivere un programma, in linguaggio C, che legga una parola introdotta da tastiera. 
// La parola può contenere complessivamente al più 100 caratteri.

// Il programma deve svolgere le seguenti operazioni:
// - Visualizzare la parola inserita e la sua lunghezza;
// - Costruire una nuova parola seguendo le seguenti regole:
// 1. Per le parole che cominciano con una consonante, si prendono le lettere fino alla 
// prima vocale e le si posizionano alla fine della parola, aggiungendo “ay”. 
// Esempio: parlare → arlarepay
// 2. Per le parole che cominciano con una vocale si aggiunge solo “yay” alla fine delle parole. 
// Esempio: albero -> alberoyay
// - Il programma deve memorizzare la nuova parola in una opportuna variabile;
// - Visualizzare la nuova parola e la sua lunghezza.

#include <stdio.h>
#include <string.h>
#define DIM 100

int isVocale(int n) {
	if(
		n == 65 || n == 69 || n == 73 || n == 79 || n == 85 ||
		n == 97 || n == 101 || n == 105 || n == 111 || n == 117
	)
		return 1;
	else
		return 0;	
}

int main() {
	char s1[DIM] = "albero";
	char s2[DIM] = "";
	char suffisso[DIM];
	char prefisso[DIM];
	int i, j=0, k=0, z=0;
	int l = strlen(s1);
	int vocale = isVocale(s1[0]);

	printf("Hai inserito la parola: %s\n", s1);
	printf("La parola è lunga %d caratteri\n", l);

	if(vocale) {
		printf("La parola inizia con una vocale\n");

		strcat(s2, s1);
		s2[l] = 'y';
		s2[l+1] = 'a';
		s2[l+2] = 'y';
	}
	else {
		printf("\nLa parola inizia con una consonante\n");

		int vocaleTrovata = 0;
		while(s1[j] != '\0') {
			if(!isVocale(s1[j]) && !vocaleTrovata) {
				suffisso[k] = s1[j];
				k++;
			} else {
				vocaleTrovata = 1;
				suffisso[k] = 'a';
				suffisso[k+1] = 'y';
				prefisso[z] = s1[j];
				z++;
			}
			j++;
		}

		strcat(s2, strcat(prefisso, suffisso));
		
		printf("Suffisso: %s\n", suffisso);
		printf("Prefisso: %s\n", prefisso);
	}
	
	printf("nuova parola: %s\n", s2);
}