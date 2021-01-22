
// queue using array


#include <stdio.h>
#include <stdlib.h>
#define size 1000



typedef struct Queue_a{
	int *arr;
	int front;
	int rear;
}queue;

// create a new queue
queue* queue_new();

// add an element in the queue
void enqueue(queue*, int);

// remove the first element from the queue
int dequeue(queue*);

// Check if queue is empty
bool queue_is_empty(queue*);

// bool check if queue is full
bool queue_is_full(queue*);

// find the size of the queue
int queue_size(queue*);

// print queue element
void queue_print(queue*);





// Check if queue is empty
bool queue_is_empty(queue* a)
{
	if(a->front > 2 )
	{
		if(a->rear == a->front-1)		
		{
			return true;
		}
		else
		{
			return false;
		}	
	}
	else
	{
		if(a->front==0&&a->rear==size-1)
		{
			return true;
		}
		else return false;
	}
}

// bool check if queue is full
bool queue_is_full(queue* a)
{
	if(a->front > 2 )
	{
		if(a->rear == a->front-2)		
		{
			return true;
		}
		else
		{
			return false;
		}	
	}
	else
	{
		if( (a->front==0&&a->rear==size-2)||(a->front==1&&a->rear==size-1) )
		{
			return true;
		}
		else return false;
	}

}


// create a new queue
queue* queue_new()
{
	queue* ptr = (queue*)malloc(sizeof(queue));
	if(ptr!=NULL)
	{		
		ptr->arr = (int*)malloc(size*sizeof(int));

		ptr->front = 0;
		ptr->rear = size-1;
	}	
	else
	{
		exit(1);
	}

}

// add an element in the queue
void enqueue(queue* s, int k)
{
	if( queue_is_full(s) == false )
	{ 
		
		(s->rear)++;

		if(s->rear==size)
		{		
			s->rear=0;		
		}

		s->arr[s->rear] = k;
	}

}


// remove the first element from the queue
int dequeue(queue* s)
{
	if(queue_is_empty(s)==false )
	{
		int k = s->arr[s->front];
	
		if(queue_size(s)==1)
		{
			s->front--;
		}
		else
		{
			s->front++;
		}	
		return k;	

	}
}


// find the size of the queue
int queue_size(queue* s)
{
	int count = (s->rear - s->front + 1+ size )%size;

	return count;
}


// print queue element
void queue_print(queue* s)
{
	if(queue_is_empty(s)==false )
	{		
		int i = s->front;

		while(i!=(s->rear) )
		{
			printf("%d ",s->arr[i] );
			
			i++;
			
			if(i==size)
			{
				i=0;
			}		
						
		}

		printf("%d",s->arr[i]);
	}
}
