// Codificare in linguaggio C la funzione
// int uguale(char a, char b)
// che restituisce:
// 1 se i due caratteri sono uguali, oppure rappresentano la stessa lettera 
// (anche se una delle due è maiuscola e l'altra minuscola).
// 0 altrimenti.

// Per esempio, devono fornire 1 le invocazioni: uguali('r','R'), uguali('*','*'), 
// uguali('F','f')
// mentre forniscono 0 le invocazioni: uguali('F','&'), uguali('!','A').

#include <stdio.h>

int uguale(char a, char b) {
	int r=0;
	if(a == b)
		r=1;
	else {
		if(
			((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) &&
			((b >= 65 && b <= 90) || (b >= 97 && b <= 122)) &&
			(a == b + 32 || a == b - 32)
		)
			r=1;
	}
	
	return r;
}

int main() {
	if(uguale('A', 'a'))
		printf("uguali\n");
	else
		printf("Non uguali\n");

	if(uguale('A', 'A'))
		printf("uguali\n");
	else
		printf("Non uguali\n");

	if(uguale('a', 'a'))
		printf("uguali\n");
	else
		printf("Non uguali\n");

	if(uguale('a', 'A'))
		printf("uguali\n");
	else
		printf("Non uguali\n");

	if(uguale('F','&')) {
		printf("uguali\n");
	}else {
		printf("Non uguali\n");
	}
	if(uguale('!','A')) {
		printf("uguali\n");
	}else {
		printf("Non uguali\n");
	}
}