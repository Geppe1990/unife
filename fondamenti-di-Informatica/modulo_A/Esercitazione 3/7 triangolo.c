// Dato un numero di righe N, disegnare sullo schermo la seguente figura (esempio per N = 5)
//     *
//    ***
//   *****
//  *******
// *********


#include <stdio.h>

int main() {
	int N = 5, i, j, pallini = 1;
	
	for(i=0; i<N; i++) {
		int spazi = N-1-i;
		for(j=0; j<spazi; j++)
			printf(" ");

		for(j=0; j<pallini; j++)
			printf("*");

		printf("\n");
		pallini+=2;

	}
}