// Scrivere un programma in C per calcolare le statistiche di un campionato di calcio.
// Il programma memorizza tutti i dati relativi alle varie squadre in un array (usare il file di inizializzazione allegato) dove ogni elemento dell'array è una struttura dati Squadra contente:
// - nome squadra (stringa di lunghezza 20 compreso il terminatore);
// - codice squadra (intero);
// - goal fatti (intero);
// - goal subiti (intero).
// A partire dall'array di strutture contenente tutti i dati:
// * Stampare a video tutti i nomi e i codici delle squadre che hanno un numero di goal fatti maggiore del numero di goal subiti.
// * Stampare a video tutti i nomi delle squadre che hanno un numero di goal fatti maggiori rispetto alla media dei goal fatti di tutte le squadre.

#include <stdio.h>

typedef struct {
	char nome[20];
	int codice;
	int goal_fatti;
	int goal_subiti;
} squadra;

int main() {
	const int Nsquadre = 7;
	int i = 0;
	int mediaGoal_fatti;
	squadra s[]={
		{"TeamRossi", 0, 6, 14},
		{"TeamVerdi", 4, 8, 2},
		{"TeamIronMan", 52, 30, 0},
		{"TeamCaptainAmerica", 36, 0, 34},
		{"TeamDoctorStrange", 38, 20, 4},
		{"TeamMarvel", 42, 55, 3},
		{"DcComicsIsNotSoGood", 8, 5, 23}
	};

	for(i=0; i<Nsquadre; i++) {
		mediaGoal_fatti += s[i].goal_fatti;
	}

	mediaGoal_fatti /= mediaGoal_fatti;

	printf("Nomi e i codici delle squadre che hanno un numero di goal fatti maggiore del numero di goal subiti\n");
	for(i=0; i<Nsquadre; i++) {
		if(s[i].goal_fatti > s[i].goal_subiti) {
			printf("Nome: %s\n", s[i].nome);
			printf("Codice: %d\n", s[i].codice);
		}
	}

	printf("Squadre che hanno un numero di goal fatti maggiori rispetto alla media dei goal fatti di tutte le squadre.\n");
	for(i=0; i<Nsquadre; i++) {
		if(s[i].goal_fatti > mediaGoal_fatti){
			printf("Nome: %s\n", s[i].nome);
		}
	}
}