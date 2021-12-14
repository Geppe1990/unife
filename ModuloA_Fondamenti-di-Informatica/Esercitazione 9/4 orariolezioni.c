// L’orario di una lezione è rappresentato dalla struttura:

// typedef struct
// { char nomecorso[20];
// int orainizio, durata;
// } orario;

// Si scriva una funzione che, date 2 lezioni, verifica se si sovrappongono e, qualora si sovrappongano, lo segnali al chiamante e sposti in avanti la lezione che inizia più tardi, in modo che inizi appena finisce l’altra lezione.
// Nota: non sappiamo a priori quale delle due lezioni comincia prima (bisogna controllare il valore di orainizio).
// Nota2: Non è obbligatorio fare il controllo dell'input, si supponga che l'utente inserisca un ora iniziale compresa tra 0 e 23.

#include <stdio.h>
#include <string.h>

typedef struct{ 
	char nomecorso[20];
	int orainizio, durata;
} orario;

void checkLezioni(orario *lezione1, orario *lezione2) {
	int sovrappongono = 0;
	
	if(
		((*lezione2).orainizio >= (*lezione1).orainizio && 
		(*lezione2).orainizio < (*lezione1).orainizio + (*lezione1).durata) ||
		((*lezione1).orainizio >= (*lezione2).orainizio && 
		(*lezione1).orainizio < (*lezione2).orainizio + (*lezione2).durata)
	) {
		sovrappongono = 1;
	}

	if(sovrappongono) {
		printf("Le lezioni si sovrappongono: ");
		if((*lezione1).orainizio <= (*lezione2).orainizio) {
			printf("%s inizia prima di %s\n", (*lezione1).nomecorso, (*lezione2).nomecorso);
			(*lezione2).orainizio = (*lezione1).orainizio + (*lezione1).durata;
			printf("%s dovrebbe iniziare alle %d\n", (*lezione2).nomecorso, (*lezione2).orainizio);
		} else {
			printf("%s inizia prima di %s\n", (*lezione2).nomecorso, (*lezione1).nomecorso);
			(*lezione1).orainizio = (*lezione2).orainizio + (*lezione2).durata;
			printf("%s dovrebbe iniziare alle %d\n", (*lezione1).nomecorso, (*lezione1).orainizio);
		}
	}
}

int main() {
	orario lezione1;
	orario lezione2;

	strcpy(lezione1.nomecorso, "Matematica");
	lezione1.orainizio = 10;
	lezione1.durata = 2;
	strcpy(lezione2.nomecorso, "Geometria");
	lezione2.orainizio = 11;
	lezione2.durata = 3;

	printf("Nome Lezione 1: %s\n", lezione1.nomecorso);
	printf("Nome Lezione 1: %s\n", lezione2.nomecorso);

	checkLezioni(&lezione1, &lezione2);
}