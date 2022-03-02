#include <stdio.h>

main()
{
	int celsius, fahrenheit;
	printf("Inserisci la temperatura in celsius: ");
	scanf("%d", &celsius);
	fahrenheit = (celsius * 9/5 + 32);
	printf("%d gradi Celsius equivalgono a %d gradi Fahrenheit\n", celsius, fahrenheit);
}