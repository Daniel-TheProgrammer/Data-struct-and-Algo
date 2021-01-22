/*
Next larger element

Given an array A [ ] having distinct elements, the task is to find the next greater element for each element
of the array in order of their appearance in the array. If no such element exists, output -1

Input
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow.
Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The
Second line of each test case contains N space separated positive integers denoting the values/elements
in the array A[ ].

output
For each test case, print in a new line, the next greater element for each array element separated by space
in order.

constraint
1 <= |S| <= 10000

Example

Input
14
1 3 2 4

output
3 4 4 -1


Explanation
In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn’t exist hence -1.

*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "stack.h"

//to find next large element
void nextG(int a[],int n);

int main()
{
	//test cases	
	int t;
	scanf("%d",&t);

	//iterarting for t times
	while(t>0)
	{
		//no of elements	
		int n;
		scanf("%d",&n);
		
		int a[n];  //to store input elements
		int i;     //counter

		//input array elemnts
		for(i=0;i<n;i++)	
		{
			scanf("%d",&a[i]);
		}
		
		//function to find next large elemnt
		nextG(a,n);
		
		printf("\n");	//next line
		
		t--;

	}//end while

}//end main

//to find and print next large element
void nextG(int a[],int n)
{

	int b[n];	//temporary array to store next large of element at index

	stack* s = stack_new();		//new satck
	
	stack_push(s,0);	//pushing the first index =0

	int i;			//counter

	int curr,pop;		//curr value of array elemnt and poped value from stack

	//traverse till last 
	for(i=1;i<n;i++)
	{
		//stack is not empty 
		if(stack_is_empty(s)==false)
		{
			pop = stack_pop(s);	//pop from satck
		
			curr = a[i];		//curr is a[i]
	
			//if curr is greater than poped
			while(curr > a[pop])
			{
				b[pop]=curr;	//next large element is current
			
				//satck empty break
				if(stack_is_empty(s)==true)
				{
					break;
				}
								
				pop = stack_pop(s); //not empty pop again				
			}
			
			//if curr is less than or equal to pop push pop back in stack
			if(curr<=a[pop])
			{
				stack_push(s,pop);		
			}//end if	
	
		}//end if	

		stack_push(s,i); //push curr in stack to find next large of it
	
	}//end for

	
	//if there are still elemnts in stack 
	while(stack_is_empty(s)==false)
	{
		int x = stack_pop(s);  //pop them and assign -1
		b[x] = -1;
	}

	//print the next large elements
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);		
	}

}//end fn

