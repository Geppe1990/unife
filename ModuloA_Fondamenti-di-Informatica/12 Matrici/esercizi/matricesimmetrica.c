// - Si legga da tastiera una matrice 3x3, tramite una procedura lettura
// - Si verifichi, tramite una funzione simm, se la matrice è simmetrica
// - Si visualizzi se la matrice è simmetrica o no

#include <stdio.h>
#define DIM 3

void checkSimm(int M[][DIM], int *sim) {
	int i, j;
	for(i=0; i<DIM; i++) {
		for(j=i+1; j<DIM; j++) {
			if(M[i][j] != M[j][i]){
				printf("M[%d][%d]: %d\n", i, j, M[i][j]);
				*sim = 0;
			}
		}
	}
}

void getData(int M[3][3]) {
	int i, j;
	printf("Inserisci i valori della matrice\n");

	for(i=0; i<DIM; i++) {
		for(j=0; j<DIM; j++) {
			scanf("%d", &M[i][j]);
		}
	}
}

int main() {
	int M[DIM][DIM], sim = 1;
	getData(M);
	checkSimm(M, &sim);

	if(sim) {
		printf("La matrice è simmetrica\n");
	}
}