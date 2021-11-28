// Siamo a Natale. In una piazza, N bambini si sono disposti in cerchio attorno 
// a Babbo Natale in attesa di un regalo. Babbo Natale però è avaro e decide di 
// distribuire solamente N - 1 doni, in un modo un po’ strano: scelto un 
// bambino iniziale (per semplicità il primo bambino), salta K - 1 bambini raggiungendo 
// così il K-esimo, al quale viene dato un dono. Il bambino, tutto contento, 
// esce dal cerchio per lasciare la possibilità agli altri di ricevere un regalo.
// Di nuovo, Babbo Natale salta K - 1 bambini e dona un regalo al K-esimo bambino, 
// il quale, dopo aver ricevuto il regalo, torna a casa. Il cerchio si stringe sempre 
// di più finché i doni non finiscono ed un bimbo rimane senza regalo, il quale torna a 
// casa piangendo.

// Si scriva un programma in linguaggio C che dati come input i valori di N e K, determini 
// la posizione del bambino che rimarrà senza regalo.

// Esempio:
// se ci sono N = 5 bambini e K = 2, l’ordine di distribuzione è: 2, 4, 1, e 5 quindi 
// il bambino senza regalo sarà il numero 3.
// se N = 21 e K = 3, l'ordine di distribuzione è: 3, 6, 9, 12, 15, 18, 21, 4, 8, 13, 17, 1, 7, 14, 20, 10, 19, 11, 5, 16 
// quindi il bambino senza regalo sarà il numero 2.

// CONSIGLIO: Risolvere il problema utilizzando gli array per rappresentare il cerchio dei bambini.

// 1 2 3 4 5 [0][1][2][3][4]
// 1 0 3 4 5 TOLGO 2 -> BAMBINI[1]
// 1 0 3 0 5 TOLGO 4 -> BAMBINI[3]
// 0 X 3 0 5 TOLGO 1 -> BAMBINI[0]
// 0 X 3 0 X TOLGO 5 -> BAMBINI[4]

#include <stdio.h>

#define DIM 100

int main() {

	int i, j, Passo, Attuale = -1, Escluso = 0; //PASSO E' UN SINGOLO PASSO SUI K CHE FACCIO OGNI VOLTA
												//ATTUALE E' A -1 PERCHE' DEVO PARTIRE SALTANDO K RAGAZZI, SE PARTISSE DA 0 NE SALTEREI K+1
	int N = 5, K = 2;
	int Bambini[DIM];
	int Regali;

	//INSERIRE N E K
	// printf("Quanti bambini sono disposti in cerchio?\n");
	// scanf("%d", &N);
	// printf("Qual e' il primo bambino a ricevere il regalo?(K)\n");
	// scanf("%d", &K);

	//IL BAMBINO NON HA RICEVUTO IL REGALO = 0
	//IL BAMBINO HA RICEVUTO IL REGALO = 1

	//INIZIALIZZO ARRAY
	for (i = 0; i < N; i++) {

		Bambini[i] = 0;
	}

	//COMINCIO LA CONTA

	//CICLO CHE DEVE TERMINARE QUANDO TUTTI TRANNE 1 RAGAZZO HANNO RICEVUTO IL REGALO
	//CALCOLO QUINDI LA SOMMA DI TUTTI I BAMBINI CHE HANNO RICEVUTO IL REGALO

	//CONTINUO FINCHE' NON DO N-1 REGALI
	for (Regali = 0; Regali < N - 1; Regali++) {

		//CONTO
		for (Passo = 0; Passo < K; Passo++) {

			//ARRIVO AL BAMBINO SUCCESSIVO
			Attuale++;

			//SE SONO ARRIVATO SU UN BAMBINO GIA' USCITO DEVO INCREMENTARE (RICORDARE IL MODULO PERCHE' POTREI AVER TERMINATO IL GIRO)
			while (Bambini[Attuale % N] == 1) {

				Attuale++;
			}
		}

		//TERMINATI TUTTI I PASSI CONSEGNO IL REGALO

		Bambini[Attuale % N] = 1;
	}

	//STAMPO IL BAMBINO CHE E' RIMASTO FUORI
	while (Bambini[Escluso] != 0) {
		Escluso++;
	}
	printf("Il bambino escluso e' il numero %d", Escluso + 1);
}