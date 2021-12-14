// Si scriva un programma C che:
// - Attraverso una funzione int lunghezza() legga da tastiera un intero N, 
// l'intero deve essere compreso tra 1 e 20, se non lo è si stampi un messaggio di errore;
// - Legga da tastiera N elementi interi e li inserisca in un array chiamato InputArray

// - Si chieda una soglia S e si copi:
// 1. Gli elementi del vettore InputArray che hanno valori maggiori della soglia in 
// un secondo vettore Array2;
// 2. Gli elementi del vettore InputArray che hanno valori minori della soglia in 
// un terzo vettore Array3;
// - Si stampino a video gli elementi di Array2 e Array3

// NOTA: negli Array 2 e 3 non devono esserci "buchi", pertanto i vettori dovranno 
// essere i più corti possibili, e contenere tutti gli elementi.

#include <stdio.h>

int lunghezza() {
	int N;
	printf("Inserisci N: ");
	scanf("%d", &N);

	if(N < 1 || N > 20) {
		printf("N deve essere compreso tra 1 e 20!\n");
		return lunghezza();
	} else {
		return N;
	}
}

int main() {
	int N = lunghezza();
	int S;
	int InputArray[N];
	int Array2[N];
	int Array3[N];
	int i;
	int j = 0, k = 0;

	printf("Inserisci %d valori\n", N);
	for(i=0; i<N; i++) {
		scanf("%d", &InputArray[i]);
	}

	printf("Inserisci la soglia S: ");
	scanf("%d", &S);

	for(i=0; i<N; i++) {
		if(InputArray[i] > S) {
			Array2[j] = InputArray[i];
			j++;
		}else if(InputArray[i] < S){
			Array3[k] = InputArray[i];
			k++;
		}
	}

	printf("Elementi di array2: ");
	for(i=0; i<j; i++) {
		printf("%d ", Array2[i]);
	}

	printf("\nElementi di array3: ");
	for(i=0; i<k; i++) {
		printf("%d ", Array3[i]);
	}
	printf("\n");
}