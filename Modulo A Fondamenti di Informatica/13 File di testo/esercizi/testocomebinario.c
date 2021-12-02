#include <stdio.h>

int main() {
	FILE *fp;
	char s[30];
	int n;
	fp = fopen("testo.txt", "rb");
	fread(s, sizeof(char), 30, fp);
	printf("%s", s);

	fclose(fp);
}