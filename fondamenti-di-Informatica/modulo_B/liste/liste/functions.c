#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

list insertHead(int e, list L) {
	list t = (list)malloc(sizeof(item));
	t->value = e;
	t->next = L;

	return t;
}

list insertTail(int e, list L) {
	list aux;
	list patt = L;
	list prec = L;

	aux = (list)malloc(sizeof(list));
	aux->value = e;
	aux->next = NULL;

	if (L == NULL) {
		return aux;
	}
	else {
		while (patt != NULL) {
			prec = patt;
			patt = patt->next;
		}
		prec->next = aux;
		return L;
	}
}

void printList(list L) {
	if (L != NULL) {
		printf("%d\n", L->value);
		printList(L->next);
	}
}

int isInList(int e, list L) {
	int trovato = 0;

	while (L != NULL && !trovato) {
		if (L->value == e) {
			trovato = 1;
		}
		else {
			L = L->next;
		}
	}

	return trovato;
}

list deleteNode(int e, list L) {
	int trovato = 0;
	list aux = L;
	list prev = NULL;

	if (aux != NULL) {
		if (aux->value == e) {
			L = aux->next;
			free(aux);
		} else {
			while ((aux != NULL) && (!trovato)) {
				if (aux->value == e) {
					trovato = 1;
				}
				else {
					prev = aux;
					aux = aux->next;
				}
			}

			if (aux != NULL) {
				prev->next = aux->next;
				free(aux);
			}
		}
	}

	return L;
}