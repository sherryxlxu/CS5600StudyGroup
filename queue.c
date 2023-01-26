/* queue - Implement Process Queue  */

/*
 * queue.c / Implement Process Queue
 *
 * Xiaoliang Xu / CS5600 / Northeastern University
 * Collaborator: Zhixuan Cao, Ye Yao
 * Spring 2023 / Jan 25, 2023
 *
 */

/* 
 * This program has a queue data structure and with queue, scheduler could keep track of processes to schedule.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char const *argv[])
{
	queue_t *queue = createQueue();
	printf("Process information includes an integer as indentifier of the process, the name of current process, and an integer for priority of the process.\n");
	process_t *firstProcess = &(process_t) {1,"Merry",1};
	process_t *secondProcess = &(process_t) {2,"Merry",2};
	process_t *thirdProcess = &(process_t) {3,"Merry",9};
	process_t *fourthProcess = &(process_t) {4,"Merry",4};
	process_t *fifthProcess = &(process_t) {5,"Merry",5};

	enqueue(queue, firstProcess);
	enqueue(queue, secondProcess);
	enqueue(queue, thirdProcess);
	enqueue(queue, fourthProcess);
	enqueue(queue, fifthProcess);
	printQueue(queue);
	printf("size of queue: %d\n\n", qsize(queue));

	dequeue(queue);
	printQueue(queue);
	printf("size of queue: %d\n\n", qsize(queue));

	dequeueProcess(queue);
	printQueue(queue);
	printf("size of queue: %d\n\n", qsize(queue));
	
	return 0;
}
