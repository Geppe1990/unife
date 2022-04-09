#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <stdio.h>

int main() {
	list root = NULL;
	int i;

	do {
		printf("Inserisci un elemento nella lista: ");
		scanf("%d", &i);
		root = insertHead(i, root);
		//root = insertTail(i, root);
	} while (i != 0);

	printList(root);
	
	if (isInList(6, root)) {
		printf("Il numero è nella lista\n");
	}
	else {
		printf("Il numero non è nella lista\n");
	}

	root = deleteNode(6, root);
	printList(root);
}