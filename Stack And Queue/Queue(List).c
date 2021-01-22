
//queue implementaion using list

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
	LList* front;
	LList* rear;
}queue;

// create a new queue
queue* queue_new();

// add an element to the queue
void enqueue(queue*, int);

// remove the front element from the queue
int dequeue(queue*);

// Check if queue is empty
bool queue_is_empty(queue*);

// find the size of the queue
int queue_size(queue*);

// print queue element
void queue_print(queue*);



// Check if queue is empty
bool queue_is_empty(queue* a)
{
	if( (a->front)->head == NULL )
	{
		return true;
	}
	else 	
	{
		return false;
	}

}


// create a new queue
queue* queue_new()
{
	queue* ptr = (queue*)malloc(sizeof(queue));
	
	if(ptr!=NULL)
	{
		ptr->front = llist_new();		
	
		ptr->rear = llist_new();
	}

	return ptr;
}

// add an element to the queue
void enqueue(queue* s, int data)
{
	if(queue_is_empty(s)==true)
	{
		llist_append(s->front,data);
		(s->rear)->head = (s->front)->head;
	}
	else
	{
		llist_append(s->front,data);
		
		(s->rear)->head = ((s->rear)->head)->next;
	}

}

// remove the front element from the queue
int dequeue(queue* s)
{
	if(queue_is_empty(s)==false)
	{
		int k;
		k = ((s->front)->head)->data;
	
		llist_remove_first(s->front);
		
		return k;
	}	

}

// find the size of the queue
int queue_size(queue* s)
{
	return llist_size(s->front);
}


// print queue element
void queue_print(queue* s)
{
	if(queue_is_empty(s)==false)
	{
		llist_print(s->front);
	}
}
