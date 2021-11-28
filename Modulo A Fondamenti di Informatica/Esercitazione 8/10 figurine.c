// Un bambino ha un album di figurine, con 25 posti per attaccare figurine, numerate da 1 a 25. Gli hanno regalato un certo numero di bustine di figurine; ogni bustina contiene 5 figurine.
// I dati sulle figurine sono memorizzati in un array di strutture di tipo bustina. Per ciascuna bustina si hanno 5 interi; ogni intero contiene il numero di una figurina che è presente nella bustina.

// Il bambino apre la prima bustina eattacca le figurine in essa contenuta, poi procede con la seconda bustina, ecc, finché non ha completato l'album oppure non ha finito le bustine (quindi se finisce l'album, gli possono rimanere delle bustine chiuse).

// Si scriva un programma C che calcola se il bambino riuscirà a completare l'album e, se ci riesce, quante delle bustine ha effettivamente usato (le bustine che ha aperto) per completare l'album, tenendo in considerazione che le bustine vengono aperte in ordine.


// *** Testo tratto dall'esame del 22/12/2014 ***

#include <stdio.h>

typedef struct {
	int figurine[5];
} bustina;

int main() {
	const int Nbustine = 12; // 12 se usi dummy content, 11 senza
	int album[25];
	int i,j,k;
	int Nalbum=0;
	int bustineUsate = 0;
	bustina Bustina[Nbustine]={
		{1,3,7,9,10},
		{1,7,5,4,9},
		{2,24,25,21,22},
		{17,16,15,14,19},
		{1,3,2,4,5},
		{2,6,5,4,8},
		{11,13,14,15,12},
		{4,20,5,23,2}, // DUMMY CONTENT
		{19,18,17,16,15},
		{2,4,6,3,12},
		{4,5,2,18,17},
		{13,5,4,6,12},
	};
// 20, 23
	for(i=0; i<Nbustine; i++) {
		if(Nalbum < 25) {
			bustineUsate++;
			printf("\nContenuto bustina n. %d\n", i+1);
			printf("Hai già inserito %d figurine\n", Nalbum);
			for(j=0; j<5; j++) {
				// printf("%d ", Bustina[i].figurine[j]);
				int presente = 0;
				for(k=0;k<Nalbum; k++) {
					if(Bustina[i].figurine[j] == album[k]) {
						printf("Figurina %d già presente\n", Bustina[i].figurine[j]);
						presente = 1;
					}
				}

				if(presente == 0) {
					printf("Aggiungo la figurina %d all'album\n", Bustina[i].figurine[j]);
					album[Nalbum] = Bustina[i].figurine[j];
					Nalbum++;
				}
			}
		}
	}
	if(Nalbum<25) {
		printf("\n[Il bambino non ha completato l'album]\n");
	} else {
		printf("\n[Sono state ncessarie %d bustine per completare l'album]\n", bustineUsate);
	}
}