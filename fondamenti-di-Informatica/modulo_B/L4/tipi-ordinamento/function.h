#define N 11
typedef float ELEMENT;
typedef ELEMENT ARRAY[N];
typedef enum {false, true} Boolean;

void naiveSort(ARRAY a, int dim);
void bubbleSort(ARRAY a, int dim);
void mergeSortR(ARRAY a, int iniz, int fine);