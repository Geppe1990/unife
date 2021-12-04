// L'autorità di Agamennone è stata messa in discussione e lo stato maggiore Acheo organizza le elezioni per decidere se confermarlo o eleggere un nuovo capo supremo. Dai diversi accampamenti sono giunti i risultati, ma vanno aggregati per determinare il totale generale dei voti di ciascuno (non esistono candidati prefissati, ognuno può incidere sul coccio il nome di uno qualunque dei nobili).
// I voti dei vari accampamenti sono riportati in un array di strutture strutturato nel seguente modo:
// - Nome candidato: stringa di 20 caratteri (compreso il terminatore).
// - Numero voti: intero.
// Si scriva un programma C che legga l'array di strutture in cui sono memorizzati i voti (al più 100), e riporti in un altro array di strutture i candidati trovati, ciascuno con i corrispondenti voti totali. Si supponga che ci siano al più 100 nobili eleggibili.
// Si stampi, infine, l'array costruito.

// Esempio: se l'array iniziale contiene i dati
// "Agamennone", 4;
// "Achille", 3;
// "Agamennone", 5

// il programma dovrà costruire l'array contenente i dati:
// "Agamennone", 9;
// "Achille", 3
// e stamparlo.

// Si utilizzi il seguente algoritmo:
// 1. Nel main, si inizializzi l'array dei voti con la funzione di lettura contenuta nel file inizializzazione.txt (allegato) e si dichiari un opportuno array finale di strutture per contenere i candidati e il totale dei voti. Tale array è inizialmente vuoto.
// 2. Per ciascun elemento dell'array dei voti, si invochi una procedura inserimento che inserisce nell'array finale, creato al punto 1, il candidato letto.
// La procedura inserimento dovrà:
// - verificare, tramite una funzione ricerca, se il candidato è già presente nell'array finale (la funzione ricerca restituisce l’indice del candidato nell’array se esso è presente, -1 altrimenti);
// - se il candidato non è presente, dovrà inserire una nuova voce, contenente il candidato con il numero di voti letto;
// - se, invece, il candidato è già presente, si dovrà aggiornare opportunamente il numero di voti (somma).
// 3. Infine, si stampi l'array finale ottenuto.

#include <stdio.h>
#include <string.h>

#define DIM 100

typedef struct {
	char nome[20];
	int voti;
} votazione;

void lettura_votazioni(votazione V[], int* N_votazioni){
    const int N_elementi = 22;
    int i;
    votazione accampamenti[] = {
        {"Odisseo", 4},{"Achille", 3},{"Menelao", 2},{"Odisseo", 2},{"Agamennone", 5},{"Menelao", 2},{"Tersite", 1},{"AiaceTelamonio", 5},{"AiaceTelamonio", 2},{"Diomede", 4},{"AiaceOileo", 2},{"Agamennone", 3},{"Achille", 5},{"AiaceOileo", 2},{"Odisseo", 3},{"Achille", 5},{"Agamennone", 2},{"Menelao", 2},{"Diomede", 3},{"AiaceTelamonio", 2},{"Diomede", 2},{"AiaceOileo", 2}
    };
    for(i = 0; i < N_elementi; i++)
        V[i] = accampamenti[i];
    (*N_votazioni) = N_elementi;
}

int ricerca(votazione v[], int *n, char candidato[]) {
	int i;
	for(i=0; i<(*n); i++) {
		if(strcmp(v[i].nome, candidato) == 0) {
			return i;
		}
	}
	return -1;
}

void inserimento(votazione candidato, votazione v[], int *n) {
	int index = ricerca(v, n, candidato.nome);
	if(index != -1) {
		v[index].voti += candidato.voti;
	} else {
		strcpy(v[(*n)].nome, candidato.nome);
		v[(*n)].voti = candidato.voti;
		(*n)++;
	}
}

int main() {
	votazione votazioni[DIM];
	votazione votazioni_finali[DIM];
	int N_votazioni;
	int N_votazioni_finali = 0;
	int i;
	lettura_votazioni(votazioni, &N_votazioni);

	for(i=0; i<N_votazioni; i++)
		inserimento(votazioni[i], votazioni_finali, &N_votazioni_finali);

	for(i=0; i<N_votazioni_finali; i++)
		printf("%s ha ricevuto %d voti\n", votazioni_finali[i].nome, votazioni_finali[i].voti);
}
