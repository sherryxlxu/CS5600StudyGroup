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
	void* data; /*payload  */
	/*pointer  */
	int isHead;
	struct queue_t *next;

} queue_t;

void enqueue(queue_t* queue, void* element);
void* dequeue(queue_t* queue);
process_t* dequeueProcess(queue_t* queue);
int qsize(queue_t* queue);
int size;

process_t* dequeueProcess(queue_t* queue){
	int highestPriority =0;
	process_t *processNode;
	//walk through link list
	queue_t *pre = queue;
	queue_t *cur = queue->next;
	if (queue->next == NULL) {
		return NULL;
	}
	while(cur!=NULL){
		//get process_t info 
		processNode = cur->data;
		//get the priority value in the processNode
		// printf("%d\n",processNode->priority);
		if (processNode->priority > highestPriority){
			highestPriority = processNode->priority;
			// printf("%d\n",highestPriority);
		}
		cur = cur->next;
	}
	printf("%d\n",highestPriority);
	cur = queue->next;
	while(cur!=NULL){
		processNode = cur->data;
		if (processNode->priority == highestPriority){
			printf("identifier: %d\n, name: %s\n priority: %d\n",processNode->identifier, processNode->name,processNode->priority);
			size --;
			pre->next = cur->next;
			void *data = cur->data;
			free(cur);
			return data;
		}
		cur = cur->next;
		pre = pre->next;
	}
	// printf("%d\n",highestPriority);
	// printf("identifier: %d\n, name: %s\n priority: %d\n",processNode->identifier, processNode->name,processNode->priority);

	

}
void enqueue(queue_t* queue, void* element) {
	printf("enqueued\n");
    
	queue_t *cur = queue;

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
	process_t *processNode;
	queue_t *cur = queue->next;
	if (cur == NULL) {
		printf("NULL->");
	} else {
		while (cur->next != NULL) {
			processNode = cur->data;
			// printf("%d\n%s\n%d\n", processNode);
			printf("identifier: %d\n, name: %s\n priority: %d\n",processNode->identifier, processNode->name,processNode->priority);
			cur = cur->next;
		}
		// printf("%d\n%s\n%d\n", processNode);
		processNode = cur->data;
		printf("identifier: %d\n, name: %s\n priority:%d\n",processNode->identifier, processNode->name,processNode->priority);
	}
	printf("\n");
}

int qsize(queue_t * queue){
	return size;
}
