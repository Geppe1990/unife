// Un ambulatorio dentistico ha memorizzate in un array di strutture tutte le prenotazioni effettuate per il mese di Novembre. Per ogni prenotazione si hanno i seguenti dati:
// - Cognome: stringa di 20 caratteri, compreso il terminatore.
// - Data: intero da 1 a 30.
// Le prenotazioni sono ordinate per cognome. Si supponga che ci siano al più 30 prenotazioni.

// Si scriva un programma in linguaggio C che stampa a video quali giorni sono liberi, secondo il seguente algoritmo:
// 1. Nel main, si invochi una funzione di lettura delle prenotazioni, e una di stampa dei giorni liberi (punto 2).
// Per semplificare l’immissione dei dati, la funzione "lettura_prenotazioni" viene fornita già implementata nel file inizializzazione.txt
// 2. Si scriva una funzione (da invocare nel main) che prende come parametri l'array di strutture (più eventualmente altri parametri) e stampa a video i giorni in cui non ci sono prenotazioni. Per fare questo, tale funzione deve invocare, per ogni giorno del mese, la funzione del punto 3.
// 3. Si scriva una funzione che prenda come parametri:
// - l'array di strutture contenente le prenotazioni.
// - ed una data (intero da 1 a 30).
// e fornisca a chi la invoca se ci sono prenotazioni per quella data (1=ci sono prenotazioni, 0=non ci sono prenotazioni).
// In tutte le procedure e funzioni è possibile aggiungere parametri. È invece vietato usare meno parametri di quelli richiesti.

#include <stdio.h>

typedef struct {
	char cognome[20];
	int data;
} prenotazione;

void lettura_prenotazioni(prenotazione P[], int* N_prenotazioni){
    const int N_elementi = 21;
    int i;
    prenotazione luglio[] = {
        {"Alberti",1},
        {"Baldoni",17},
        {"Bonfe",6},
        {"Bottazzi",25},
        {"Busi",18},
        {"Chesani",15},
        {"Franciosi",11},
        {"Giordano",27},
        {"Lamma",25},
        {"Leonardi",23},
        {"Martelli",6},
        {"Mascardi",26},
        {"Mello",22},
        {"Maio",16},
        {"Naponiello",10},
        {"Neri",1},
        {"Rossi",3},
        {"Toni",11},
        {"Torroni",5},
        {"Vecchi",5},
        {"Verdi",30}
    };
    for(i = 0; i < N_elementi; i++)
        P[i] = luglio[i];
    (*N_prenotazioni) = N_elementi;
}

int verifica_data(prenotazione P[31], int *N_elementi, int data) {
	int i, libero = 0;
	for(i=0; i<*N_elementi; i++)
		if(data == P[i].data)
			libero = 1;

	return libero;
}

void stampa_liberi(prenotazione P[31], int *N_elementi) {
	int i;
	for(i=1; i<=31; i++) {
		int libero = -1;
		libero = verifica_data(P, N_elementi, i);
		
		if(libero == 1)
			printf("Giorno %d è occupato\n", i);
		else
			printf("Giorno %d è libero\n", i);
	}
}

int main() {
	prenotazione P[31];
	int N;

	lettura_prenotazioni(P, &N);
	stampa_liberi(P, &N);
}
