typedef struct list_element {
	int value;
	struct list_element* next;
} item;

typedef item* list;

list insertHead(int e, list L);
list insertTail(int e, list L);
list deleteNode(int e, list L);
int isInList(int e, list L);
void printList(list L);
