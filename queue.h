/* queue - Implement Process Queue  */

/*
 * queue.h / Implement Process Queue
 *
 * Xiaoliang Xu / CS5600 / Northeastern University
 * Collaborator:
 * Spring 2023 / Jan 25, 2023
 *
 */

/* 
 * This program has a queue data structure and with queue, scheduler could keep track of processes to schedule.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct process_t		/*process_t contains all the information related to the process  */
{
	int identifier;
	char *name;
	int priority;	
} process_t;

typedef struct queue_t{			/*queue_t is the node of a queue linked list  */
	void* data;					/*node store generic data  */
	int isHead;					/*head node  */
	struct queue_t *next;		/*pointer  */

} queue_t;

void enqueue(queue_t* queue, void* element);
void* dequeue(queue_t* queue);
process_t* dequeueProcess(queue_t* queue);
int qsize(queue_t* queue);
int size;

process_t* dequeueProcess(queue_t* queue){
	int highestPriority =0;
	void* data;
	process_t *processNode;
	queue_t *pre = queue;
	queue_t *cur = queue->next;
	if (queue->next == NULL) {
		return NULL;
	}
	while(cur!=NULL){
		processNode = cur->data;		/*get process_t information from the node in queue  */
		if (processNode->priority > highestPriority){			/*get the priority value in the processNode  */
			highestPriority = processNode->priority;			/*update highestPriority value  */
		}
		cur = cur->next;
	}
	cur = queue->next;		/*walk through link list again and identify the node with highest priority and remove it  */
	while(cur!=NULL){
		processNode = cur->data;		/*get process_t information from the node in queue  */
		if (processNode->priority == highestPriority){
			size --;
			pre->next = cur->next;		/*remove the pointer from current node to next node  */
			data = cur->data;			
			free(cur);					/*remove the memory  */
			return data;				/*content that we have removed  */
		}
		cur = cur->next;
		pre = pre->next;				/*walk through linked list  */
	}
}

void enqueue(queue_t* queue, void* element) {
	queue_t *cur = queue;
    while (cur->next != NULL) {			/*If cur->next is NULL then we could append new element to the pointer  */
    	cur = cur->next;
    }
    queue_t * new_q = (queue_t *) malloc(sizeof(queue_t));
    new_q->data = element;
    cur->next = new_q;
    size++;								/*As enqueued, the size increased by 1  */

}


void* dequeue(queue_t* queue) {
	void *data;
	if (queue->next == NULL) {			/*If dumb head node points to null, it means the linked list is empty  */
		return NULL;
	}
	queue_t *tmp = queue->next;			/*Intend to remove the node after dumb head node  */
	queue->next = tmp->next;
	size--;
	data = tmp->data;
	free(tmp);							/*remove the memory  */
	return data;
}


queue_t* createQueue() {				/*create a queue with dumb head node  */
	queue_t *queue = malloc(sizeof(queue_t));
	queue->isHead = 1;
	return queue;
}

void printQueue(queue_t* queue) {
	process_t *processNode;
	queue_t *cur = queue->next;			/*skip the dumb head node  */
	if (cur == NULL) {
		printf("NULL->");
	} else {
		while (cur->next != NULL) {
			processNode = cur->data;
			printf("identifier: %d\n, name: %s\n priority: %d\n",processNode->identifier, processNode->name,processNode->priority);
			cur = cur->next;
		}
		processNode = cur->data;
		printf("identifier: %d\n, name: %s\n priority:%d\n",processNode->identifier, processNode->name,processNode->priority);
	}
	printf("\n");
}

int qsize(queue_t * queue){				/*return global variable size  */
	return size;
}
