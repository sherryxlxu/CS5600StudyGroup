#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

//type
typedef struct process_t {
	int identifier;
	char *name;
	int priority;	
} process_t;

typedef struct queue_t {
	void* data;
	int isHead;
	struct queue_t *next;
} queue_t;

void enqueue(queue_t* queue, void* element);
void* dequeue(queue_t* queue);
process_t* dequeueProcess(queue_t* queue){
    int max = INT_MIN;
    while (queue){
        if (queue->data > max){
            max = queue->data;
        }
        queue = queue->next;
    }
    return max;
};
int qsize(queue_t* queue);
int size = 0;

void enqueue(queue_t* queue, void* element) {
	queue_t* cur = queue;
    while (cur->next != NULL) {
    	cur = cur->next;
    }
    queue_t* new_q = (queue_t*) malloc(sizeof(queue_t));
    new_q->data = element;
    cur->next = new_q;
    // free(cur); 
    size++;
}

void* dequeue(queue_t* queue) {
	if (queue->next == NULL) {
		return NULL;
	}
	queue_t *tmp = queue->next;
	queue->next = tmp->next;
	size--;
	void *data = tmp->data;
	free(tmp);
	return data;
}

queue_t* createQueue() {
	queue_t* queue = (queue_t*) malloc(sizeof(queue_t));
	queue->isHead = 1;
	return queue;
}

void printQueue(queue_t* queue) {
	queue_t *cur = queue->next;
	if (cur == NULL) {
		printf("NULL->");
	} else {
		while (cur->next != NULL) {
			printf("%d->", cur->data);
			cur = cur->next;
		}
		printf("%d", cur->data);
	}
	printf("\n");
}

int qsize(queue_t* queue){
	return size;
}

int main(int argc, char const *argv[])
{
	queue_t *queue = createQueue();
	printQueue(queue);
	printf("%d\n", qsize(queue));

	enqueue(queue, 0);
	// printQueue(queue);
	printf("%d\n", qsize(queue));

	for (int i=1; i < 10; i++) {
		int element = i;
		enqueue(queue, element);
	}
	printQueue(queue);
	printf("%d\n", qsize(queue));
	for (int i = 1; i < 10; i++) {
		dequeue(queue);
	}
	printQueue(queue);
	printf("%d\n", qsize(queue));
	return 0;
}
