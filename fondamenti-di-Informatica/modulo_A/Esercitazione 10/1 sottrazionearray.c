// 1. Si scriva una funzione che legge da input una sequenza di n interi terminata dal numero -1 e la memorizza in un array. Il valore -1 non va inserito nell'array. Il valore n è al massimo 100.
// 2. Nel main, si invochi due volte la funzione al punto 1 per leggere due array.
// 3. Si scriva una procedura che prende come parametri due array (ed eventuali altri parametri) ed elimina dal primo array i numeri presenti nel secondo. Ad esempio, se come parametri si hanno gli array [2,5,7,3,4,7] e [7,9,5], la procedura dovrà modificare il primo array come segue: [2,3,4].
// 4. Nel main, si invochi la procedura al punto 3 passando i due array letti al punto 2 ed infine si stampi l'array risultante tramite una procedura.

#include <stdio.h>
#define DIM 100

void delete(int a1[], int a2[], int *n1, int *n2) {
	int i = 0, j = 0;

	while(i < *n1) {
		j = 0;
		int modificato = 0;
		while(j < *n2 && modificato == 0) {
			if(a1[i] == a2[j]) {
				for(int x=i; x<*n1; x++) {
					a1[x] = a1[x+1];
				}
				modificato = 1;
				i = 0;				
				(*n1)--;
			}
			j++;
		}
		if(modificato == 0)
			i++;
	}
}

void print(int a[], int n) {
	int i;
	printf("\n");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
}

int initialize(int a[]) {
	int insert = 0;
	int i=0;
	while(insert != -1 && i < DIM) {
		printf("Inserisci un numero: ");
		scanf("%d", &insert);

		if(insert != -1) {
			a[i] = insert;
			i++;
		}
	}
	print(a, i);
	return i;
}

int main() {
	int a1[DIM] = {2,5,7,3,4,7}; // SONO HARDCODATI
	int a2[DIM] = {7,9,5}; // SONO HARDCODATI
	
	int n1 = initialize(a1);
	int n2 = initialize(a2);
	delete(a1, a2, &n1, &n2);
	printf("\n\n");
	print(a1, n1);
	printf("\n");
	print(a2, n2);
	printf("\n");
}