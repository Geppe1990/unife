// Date due stringhe, verificare se una contiene l'altra
// es: "zio" è contenuta in "Stazione"

#include <stdio.h>

main() {
	char s1[] = "zio";
	char s2[] = "Stazione";
	int i, j;
	int contenuta = 0;

	for(i=0; s2[i] != '\0'; i++) {
		if(s2[i] == s1[0]) {
			int k = i, exit = 0;
			
			for(j=0; s1[j] != '\0'; j++, k++) {
				if((s1[j] == s2[k]) && !exit){
					contenuta = 1;
				} else {
					contenuta = 0;
					exit = 1;
				}
			}
		}
	}

	if(contenuta) {
		printf("%s è contenuta in %s\n", s1, s2);
	} else {
		printf("%s NON è contenuta in %s\n", s1, s2);
	}
}