// Un laboratorio per la ricerca sui microprocessori sta analizzando dei nuovi modelli appena prodotti. In particolare gli ingegneri stanno valutando se il nuovo processo produttivo è in grado di creare in maniera corretta le connessioni sui chip di silicio.
// Le immagini, di ogni connessione, prodotte dal microscopio a scansione vengono trasformate automaticamente in matrici di bit (0/1) dove il valore 0 rappresenta l'assenza del materiale conduttivo mentre il valore 1 rappresenta la sua presenza.
// Affinché una connessione sia "buona" deve esistere un percorso di materiale conduttivo che va dall'angolo in alto a sinistra dell'immagine fino all'angolo in basso a destra senza mai interrompersi.
// Osservando la corrispondente matrice di bit possiamo dire che due celle sono "connesse" se sono adiacenti verticalmente o orizzontalmente ed entrambe assumono il valore 1. Si supponga inoltre che la connessione non abbia diramazioni, il materiale conduttivo è quindi disposto lungo un unico percorso. Si veda l'immagine allegata per ulteriori esempi.

// Si scriva un programma in linguaggio C che data in input una matrice, stampi a video se la connessione in essa rappresentata è "buona" oppure se è difettosa.
// Per fare ciò il programma dovrà invocare una funzione leggi_matrice che carica i dati all'interno di una matrice di interi (trovate la funzione già implementata nel file allegato) e poi invocare una funzione verifica_connessione che prende come parametri la matrice da verificare ed eventualmente altri parametri. La funzione verifica_connessione restituisce 0 se la connessione è difettosa, 1 altrimenti.

#include<stdio.h>

#define DIM 5

void leggi_matrice_1(int M[][DIM], int* dimensione_righe, int* dimensione_colonne) {
	const int N_righe = 5;
	const int N_colonne = 5;

	int i, j;
	int matrice[DIM][DIM] = {
		{1, 0, 0, 0, 0},
		{1, 0, 1, 1, 1},
		{1, 0, 1, 0, 1},
		{1, 1, 1, 0, 1},
		{0, 0, 0, 0, 1}
	};
	for (i = 0; i < N_righe; i++)
		for (j = 0; j < N_colonne; j++)
			M[i][j] = matrice[i][j];
	(*dimensione_righe) = N_righe;
	(*dimensione_colonne) = N_colonne;
}

void leggi_matrice_2(int M[][DIM], int* dimensione_righe, int* dimensione_colonne) {
	const int N_righe = 5;
	const int N_colonne = 5;

	int i, j;
	int matrice[DIM][DIM] = {
		{1, 0, 0, 0, 0},
		{1, 1, 1, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 1, 1}
	};
	for (i = 0; i < N_righe; i++)
		for (j = 0; j < N_colonne; j++)
			M[i][j] = matrice[i][j];
	(*dimensione_righe) = N_righe;
	(*dimensione_colonne) = N_colonne;
}

void Scelta(int Matrice[][DIM], int Righe, int Colonne, int RigaAttuale, int ColonnaAttuale, int RigaPrecedente, int ColonnaPrecedente, int* RigaFutura, int* ColonnaFutura) {

	//CONTROLLO SE POSSO MUOVERMI VERSO L'ALTO
	//SE NON SONO ATTACCATO AL BORDO
	//SE HO UN CAMMINO VALIDO VERSO SINISTRA
	//E SE NON SONO VENUTO DA QUEL CAMMINO
	if (RigaAttuale > 0 && Matrice[RigaAttuale - 1][ColonnaAttuale] == 1 && RigaAttuale - 1 != RigaPrecedente) {

		//ALLORA ANDRO' VERSO QUEL PUNTO
		*RigaFutura = RigaAttuale - 1;
		*ColonnaFutura = ColonnaAttuale;
	}
	//CONTROLLO SE POSSO MUOVERMI VERSO SINISTRA
	else if (ColonnaAttuale > 0 && Matrice[RigaAttuale][ColonnaAttuale - 1] == 1 && ColonnaAttuale - 1 != ColonnaPrecedente) {

		*RigaFutura = RigaAttuale;
		*ColonnaFutura = ColonnaAttuale - 1;
	}
	//CONTROLLO SE POSSO MUOVERMI VERSO IL BASSO
	else if (RigaAttuale < Righe && Matrice[RigaAttuale + 1][ColonnaAttuale] == 1 && RigaAttuale + 1 != RigaPrecedente) {

		*RigaFutura = RigaAttuale + 1;
		*ColonnaFutura = ColonnaAttuale;
	}
	//CONTROLLO SE POSSO MUOVERMI VERSO DESTRA
	else if (ColonnaAttuale < Colonne && Matrice[RigaAttuale][ColonnaAttuale + 1] == 1 && ColonnaAttuale + 1 != ColonnaPrecedente) {

		*RigaFutura = RigaAttuale;
		*ColonnaFutura = ColonnaAttuale + 1;
	}
}

int ControlloStrade(int Matrice[][DIM], int Righe, int Colonne, int RigaAttuale, int ColonnaAttuale) {

	int NumeroStrade = 0;

	if (RigaAttuale > 0) {
		if (Matrice[RigaAttuale - 1][ColonnaAttuale] == 1)
			NumeroStrade++;
	}
	if (RigaAttuale < Righe) {

		if (Matrice[RigaAttuale + 1][ColonnaAttuale] == 1)
			NumeroStrade++;
	}
	if (ColonnaAttuale > 0) {

		if (Matrice[RigaAttuale][ColonnaAttuale - 1] == 1)
			NumeroStrade++;
	}
	if (ColonnaAttuale < Colonne) {
		if (Matrice[RigaAttuale][ColonnaAttuale + 1] == 1)
			NumeroStrade++;
	}
	return NumeroStrade;
}

int verifica_connessioni(int Matrice[][DIM], int Righe, int Colonne) {

	int RigaAttuale, RigaPrecedente, RigaFutura;
	int ColonnaAttuale, ColonnaPrecedente, ColonnaFutura;

	int NumeroStrade;

	//PARTO DAL PRIMO PUNTO
	if (Matrice[0][0] == 0)
		return 0;

	//CONTROLLO QUALE E' IL PRIMO PASSO CHE DEVO COMPIERE
	if (Matrice[1][0] == 1 && Matrice[0][1] == 0) {

		RigaPrecedente = 0;
		RigaAttuale = 1;
		ColonnaPrecedente = 0;
		ColonnaAttuale = 0;
	}
	else if (Matrice[1][0] == 0 && Matrice[0][1] == 1) {

		RigaPrecedente = 0;
		RigaAttuale = 0;
		ColonnaPrecedente = 0;
		ColonnaAttuale = 1;
	}
	else
		return 0;

	//DOPO AVER FATTO IL PRIMO PASSO POSSO ENTRARE IN UN CICLO DOVE CONTROLLO DI AVERE SEMPRE 2 STRADE POSSIBILI, UNA CHE TORNA INDIETRO E UNA CHE VA AVANTI.
	//IL TUTTO FINCHE' NON RAGGIUNGO LA FINE

	while (RigaAttuale != Righe - 1 && ColonnaAttuale != Colonne - 1) {

		//CONTROLLO QUANTE STRADE CI SONO
		NumeroStrade = ControlloStrade(Matrice, Righe, Colonne, RigaAttuale, ColonnaAttuale);
		if (NumeroStrade != 2)
			return 0;
		else {

			//DEVO TROVARE LA RIGA E LA COLONNA FUTURE
			Scelta(Matrice, Righe, Colonne, RigaAttuale, ColonnaAttuale, RigaPrecedente, ColonnaPrecedente, &RigaFutura, &ColonnaFutura);

		}

		//DOPO AVERLE TROVARE MI SPOSTO E RIPETO
		RigaPrecedente = RigaAttuale;
		ColonnaPrecedente = ColonnaAttuale;
		RigaAttuale = RigaFutura;
		ColonnaAttuale = ColonnaFutura;

	}

	//DOPO ESSERE ARRIVATO ALLA FINE SENZA ESSERE USCITO PRIMA POSSO RITORNARE 1.
	return 1;
}

int main() {
	int Matrice[DIM][DIM];
	int Righe, Colonne;
	int Buona;

	leggi_matrice_1(Matrice, &Righe, &Colonne);

	Buona = verifica_connessioni(Matrice, Righe, Colonne);

	if (Buona == 1)
		printf("La connessione 1 e' corretta\n");
	else
		printf("La connessione 1 non e' corretta\n");

	leggi_matrice_2(Matrice, &Righe, &Colonne);

	Buona = verifica_connessioni(Matrice, Righe, Colonne);

	if (Buona == 1)
		printf("La connessione 2 e' corretta\n");
	else
		printf("La connessione 2 non e' corretta\n");
}