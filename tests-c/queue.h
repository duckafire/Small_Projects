#ifndef __QUEUE__
#define __QUEUE__

struct Queue {
	int value;
	struct Queue *next;
};

typedef struct Queue Queue;

void newItem(int value);
void travelQueue(void);
void clearQueue(void);

#endif
