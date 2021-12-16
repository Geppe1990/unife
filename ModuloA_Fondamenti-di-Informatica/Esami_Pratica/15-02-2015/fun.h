#define DIM 100

typedef struct {
	char squadra[15];
	int x, y;
} idrante;

int lettura(idrante idr[]);
float distanza_euclidea(idrante idr);
void distanza_massima(idrante idranti[], int n, char squad[]);
