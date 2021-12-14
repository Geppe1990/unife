// - Tramite una procedura, si leggano da tastiera
// 	- due interi: Nr e Nc (max 10)
// 	- una matrice M di dimensione Nr x Nc
// - Si scriva poi una procedura che genera una matrice N in cui è stato eliminato il "bordo": si vogliono togliere da M le prime righe nulle e le prime colonne nulle
// - Stampa la matrice N
#include <stdio.h>
#define SIZE 10

void getSize(int *Nr, int *Nc) {
	printf("Quante righe vuoi inserire? ");
	scanf("%d", Nr);
	printf("Quante colonne vuoi inserire? ");
	scanf("%d", Nc);
}


void getData(int M[SIZE][SIZE], int *Nr, int *Nc) {
	int i, j;

	for(i=0; i<*Nr; i++)
	{
		for(j=0; j<*Nc; j++) {
			printf("Inserisci il dato al valore [%d][%d]: ", i, j);
			scanf("%d", &M[i][j]);

		}
		printf("\n");
	}
}

int main() {
	int M[SIZE][SIZE], Nr, Nc;
	getSize(&Nr, &Nc);
	getData(M, &Nr, &Nc);
	
}