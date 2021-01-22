
/*
stack implementation using array
*/


#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define size 1000

typedef struct Stack_a{
	int *arr;
	int top;
}stack;

// create a new stack
stack* stack_new();

// push an element on the stack
void stack_push(stack*, int);

// pop the top element from the stack
int stack_pop(stack*);

// Check if stack is empty
bool stack_is_empty(stack*);

// bool check if stack is full
bool stack_is_full(stack*);

// find the size of the stack
int stack_size(stack*);

// print stack element
void stack_print(stack*);




// bool check if stack is full
bool stack_is_full(stack* a)
{
	if(a->top == size-1)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool stack_is_empty(stack* a)
{
	if(a->top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}

}


// create a new stack
stack* stack_new()
{

	stack* ptr = (stack*)malloc(sizeof(stack));
	if(ptr!=NULL)
	{		
		ptr->arr = (int*)malloc(size*sizeof(int));

		ptr->top = -1;
	}	
	else
	{
		exit(1);
	}

}

// push an element on the stack
void stack_push(stack* s, int k)
{
	if( stack_is_full(s) == false )
	{ 
		(s->top)++;
		s->arr[s->top] = k;		
	}
	else
	{
		printf("array full");	
	}

}

// pop the top element from the stack
int stack_pop(stack* s)
{
	if( stack_is_empty(s) == false )
	{
		int k = s->arr[s->top];
		(s->top)--;
		return k;
	}
}

// find the size of the stack
int stack_size(stack* s)
{
	return (s->top)+1;
}

// print stack element
void stack_print(stack* s)
{
	if(stack_is_empty(s)==false)
	{		
		int i;

		for(i=s->top;i>=0;i--)
		{
			printf("%d ",s->arr[i] );
		}

	}
}

