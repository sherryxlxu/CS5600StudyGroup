#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

//type
// typedef struct process_t
// {
// 	int identifier;
// 	char *name;
// 	int priority;	
// } process_t;

// typedef struct queue_t{
// 	void* data; /*payload  */
// 	/*pointer  */
// 	int isHead;
// 	struct queue_t *next;

// } queue_t;

// void enqueue(queue_t* queue, void* element);
// void* dequeue(queue_t* queue);
// process_t* dequeueProcess(queue_t* queue);
// int qsize(queue_t* queue);
// int size;

// process_t* dequeueProcess(queue_t* queue){
// 	int highestPriority;
// 	process_t *processNode;
// 	if (queue->next = NULL){
// 		return NULL;
// 	}
// 	//walk through link list
// 	queue_t *cur = queue;
// 	while(cur->next!=NULL){
// 		//get process_t info 
// 		processNode = (process_t*)cur->data;
// 		//get the priority value in the processNode
// 		if (processNode->priority > highestPriority){
// 			highestPriority = processNode->priority;
// 		}
// 		cur = cur->next;
// 	}
// 	queue_t *cur = queue;
// 	while(cur->next!=NULL){
// 		processNode = (process_t*)cur->data;
// 		if (processNode->priority == highestPriority){
// 			break;
// 		}
// 		cur = cur->next;
// 	}
// 	//remove current node
// 	return dequeue(cur);

// }
// void enqueue(queue_t* queue, void* element) {
    
// 	queue_t *cur = queue;

//     while (cur->next != NULL) {
//     	cur = cur->next;
//     }

//     queue_t * new_q = (queue_t *) malloc(sizeof(queue_t));
//     new_q->data = element;
//     cur->next = new_q;

//     // free(cur); 
//     size++;

// }


// void* dequeue(queue_t* queue) {

// 	if (queue->next == NULL) {
// 		return NULL;
// 	}
// 	queue_t *tmp = queue->next;
// 	queue->next = tmp->next;
// 	size--;
// 	void *data = tmp->data;
// 	free(tmp);
// 	return data;
// }


// queue_t* createQueue() {
// 	queue_t *queue = malloc(sizeof(queue_t));
// 	queue->isHead = 1;
// 	return queue;
// }

// void printQueue(queue_t* queue) {
// 	queue_t *cur = queue->next;
// 	if (cur == NULL) {
// 		printf("NULL->");
// 	} else {
// 		while (cur->next != NULL) {
// 			printf("%d->", cur->data);
// 			cur = cur->next;
// 		}
// 		printf("%d->", cur->data);
// 	}
// 	printf("\n");
// }

// int qsize(queue_t * queue){
// 	return size;
// }


int main(int argc, char const *argv[])
{
	queue_t *queue = createQueue();
	// printQueue(queue);
	// printf("%d\n", qsize(queue));
	// process_t *firstProcess ={
	// 	.identifier =1,
	// 	.name = "Merry",
	// 	.priority =5
	// };

	process_t *firstProcess = &(process_t) {1,"Merry",1};
	// process_t secondProcess = {2,"Nerry",6};
	// process_t *tmp = &secondProcess;
	// process_t *thirdProcess = (process_t *) malloc(sizeof(process_t*));
	// printf("identifer: %d\n", firstProcess->identifier);

	// printf(
	// 	"identifier: %d\n, name: %s\n priority: %d\n"
	// 	,firstProcess->identifier, firstProcess->name,firstProcess->priority);
	// printf(
	// 	"identifier: %d\n, name: %s\n priority: %d\n"
	// 	,secondProcess.identifier, secondProcess.name,secondProcess.priority);
	enqueue(queue, firstProcess);
	printQueue(queue);
	printf("%d\n", qsize(queue));

	process_t *secondProcess = &(process_t) {2,"Merry",2};
	process_t *thirdProcess = &(process_t) {3,"Merry",3};
	process_t *fourthProcess = &(process_t) {4,"Merry",4};
	process_t *fifthProcess = &(process_t) {5,"Merry",5};
	enqueue(queue, secondProcess);
	enqueue(queue, thirdProcess);
	enqueue(queue, fourthProcess);
	enqueue(queue, fifthProcess);
	printQueue(queue);
	// printf("%d\n", qsize(queue));

	// dequeue(queue);
	// printQueue(queue);
	// printf("%d\n", qsize(queue));

	dequeueProcess(queue);
	printQueue(queue);
	printf("%d\n", qsize(queue));
	// for (int i=1; i < 10; i++) {
	// 	int element = i;
	// 	enqueue(queue, element);
	// }
	// printQueue(queue);
	// printf("%d\n", qsize(queue));
	// for (int i = 1; i < 10; i++) {
	// 	dequeue(queue);
	// }
	// printQueue(queue);
	// printf("%d\n", qsize(queue));
	return 0;
}
