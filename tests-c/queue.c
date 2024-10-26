#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////
struct Queue {
	int value;
	struct Queue *next;
};

typedef struct Queue Queue;

void newItem(int value);
void travelQueue(void);
void clearQueue(void);
////////////////////////////

static Queue firstItem = {-1, NULL};

void newItem(int value){
	static Queue *lastItem = &firstItem;

	size_t size = sizeof(Queue);
	Queue *new = malloc(size);
	memset(new, '\0', size);

	lastItem->next = new;

	new->value = value;

	lastItem = new;
}

// example of use
void travelQueue(void){
	Queue *p;
	for(p = firstItem.next; p != NULL; p = p->next)
		printf("[%p] = { value = %d, next = %p}\n", p, p->value, p->next);
}

void clearQueue(void){
	Queue *p, *n;
	for(p = firstItem.next; p != NULL; p = n){
		n = p->next;
		free(p);
	}
}

// TEST
// int main(){
// 	for(int i = 0; i < 10; i++)
// 		newItem(i);
// 	travelQueue();
// 	clearQueue();
// 	return 0;
// }
