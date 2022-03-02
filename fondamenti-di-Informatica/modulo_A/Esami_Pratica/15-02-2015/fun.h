#define DIM 100

typedef struct {
	char squadra[15];
	int x, y;
} idrante;

typedef struct {
	char nome[15];
	float distanza;
} squadra;

int lettura(idrante idr[]);
float distanza_euclidea(idrante idr);
void distanza_massima(idrante idranti[], int n, char squad[]);
int getSquadre(idrante idranti[], squadra squadre[], int N);
void getTotalKm(squadra squadre[], int N, squadra *squadra_max_km);