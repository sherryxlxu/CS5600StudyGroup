#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//type
typedef struct process_t
{
	int identifier;
	char *name;
	int priority;	
} process_t;

typedef struct queue_t{
	int data; /*payload  */
	/*pointer  */
	int isHead;
	struct queue_t *next;

} queue_t;

void enqueue(queue_t* queue, int element);
void* dequeue(queue_t* queue);
process_t* dequeueProcess(queue_t* queue);
int qsize(queue_t* queue);
int size;

void enqueue(queue_t* queue, int element) {
    
	queue_t *cur = NULL;
    // cur = (queue_t *) malloc(sizeof(queue_t));
    cur = queue;

    while (cur->next != NULL) {
    	cur = cur->next;
    }

    queue_t * new_q = (queue_t *) malloc(sizeof(queue_t));
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
	queue_t *queue = malloc(sizeof(queue_t));
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
		printf("%d->", cur->data);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	queue_t *queue = createQueue();
	printQueue(queue);

	enqueue(queue, 0);
	printQueue(queue);

	for (int i=1; i < 10; i++) {
		int element = i;
		enqueue(queue, element);
	}
	printQueue(queue);
	for (int i = 1; i < 10; i++) {
		dequeue(queue);
	}
	printQueue(queue);
	return 0;
}
