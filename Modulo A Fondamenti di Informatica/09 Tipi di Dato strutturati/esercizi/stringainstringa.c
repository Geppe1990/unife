// Date due stringhe, verificare se una contiene l'altra
// es: "zio" è contenuta in "Stazione"

#include <stdio.h>

main() {
	char s1[] = "ziona";
	char s2[] = "Stazione";
	int i, j = 0;
	int contenuta = 0;

	for(i=0; s2[i] != '\0'; i++) {
		if(s2[i] == s1[0]) {
			int k = i, exit = 0;
			while(s1[j] != '\0') {
				if((s1[j] == s2[k]) && !exit){
					contenuta = 1;
				} else {
					contenuta = 0;
					exit = 1;
				}
				k++;
				j++;
			}
		}
	}

	if(contenuta) {
		printf("%s è contenuta in %s\n", s1, s2);
	} else {
		printf("%s NON è contenuta in %s\n", s1, s2);
	}
}