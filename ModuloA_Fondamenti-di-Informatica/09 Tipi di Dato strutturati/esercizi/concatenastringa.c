// Date due stringhe, mettere in una terza stringa la concatenazione delle due

#include <stdio.h>

main() {
	char s1[] = "Ciao, mi chiamo ";
	char s2[] = "Giuseppe";
	char s3[30];
	int i, j = 0;

	for(i=0; s1[i] != '\0'; i++, j++) {
		s3[i] = s1[i];
	}

	for(i=0; s2[i] != '\0'; i++, j++) {
		s3[j] = s2[i];
	}
	s3[j+1] = '\0';

	printf("%s\n", s3);
}