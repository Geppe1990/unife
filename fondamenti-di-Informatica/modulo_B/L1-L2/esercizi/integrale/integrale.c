#include<stdio.h>

float quadra(float x) {
	return x*x;
}

float cubo(float x) {
	return x*x*x;
}

float rettangoli(float (*func)(float), float a, float b, int n) {
	float x, sum = 0, h;
	int j;

	h = (b-a)/n;

	x = a;

	for(j = 0; j < n; j++) {
		sum = sum + (*func)(x);
		x=x+h;
	}

	sum = h*sum;

	return sum;
}