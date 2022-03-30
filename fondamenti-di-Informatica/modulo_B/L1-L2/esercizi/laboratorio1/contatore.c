static int count;

void reset(void) {
	count = 0;
}

void inc(void) {
	count++;
}

int getValue(void) {
	return count;
}