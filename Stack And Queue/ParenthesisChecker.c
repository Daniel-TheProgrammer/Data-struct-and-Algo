/*
 Parenthesis Checker

Given an string expression, examine whether the pairs and the orders of {,},(,),[,] are correct in exp. For
example, the program should print ’1’ for exp = [()]{}{[()()]()} and ’0’ for exp = [(])

Input

The first line of input contains an integer T denoting the number of test cases. Each test case consist of a
string of expression, in a separate line.

output
Print ’1’ without quotes if pair of parenthesis are balanced else print ’0’ in a separate line.

constraint
1 = |S| = 1000

Example

Input
3
{([)}
()
()[]
output
011

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "stack.h"	//including stack.h

//if not match push
int Match(stack* s,char curr); 

//if s1 close s2 then true
bool Closed(char s1,char s2);

int main()
{
	//test cases	
	int t;
	scanf("%d",&t);

	//iterarting for t times
	while(t>0)
	{
		char str[1000];		//array to store in put
		scanf("%s",str);

		stack *s = stack_new();		//new stack
		
		int brk=0;	//flag for break in while
		int ans;	//answer 0 and 1
		int i=0;	//counter variable
		
		//iterating till last of string		
		while(str[i]!='\0')
		{
			int flag = Match(s,str[i]);	//checking match with str[i] and pop of s
			
			if(flag==-1)	//if first element is closing bracket
			{		
				brk=1;		//flag brk =1
				break;		
			}
			else if(flag==0)	//if dont match
			{
				stack_push(s,(int)str[i]);	//push str[i] in stack
			}
				
			i++;	//counter incremented
		}		
		
		//for output
		if(brk==1)
		{
			ans=0;		//starting with closing bracket
		}
		else if(stack_size(s)==0)
		{
			ans = 1;	//no element in stack all brackets closed
		}		
		else
		{
			ans = 0;	//brackets still open
		}
		printf("%d\n",ans);	

		t--;		//decremetning t
	}//end while
}//end main


//to find the match bw curr and s
int Match(stack* s,char curr)
{
	if(stack_size(s)==0)
	{
		//if first bracket is closing bracket 
		if( curr=='}'||curr==']'||curr==')')
		{
			return -1;	//to break loop
		}
		else
		{
			return 0;	//else push
		}

	}
	else
	{
		
		char a1 = (char)stack_pop(s);	//poping from stack

		if( Closed(a1,curr)==false )	//if pop and curr do not close eachother
		{
			stack_push(s,(int)a1);	//push poped element
			return 0;		//flag to push curr
		}
		else
		{
			return 1;	//there is a match	
		}
	}//end if else
}//end Match

//to check if s1 closes s2
bool Closed(char s1,char s2)
{
	//if s1 and s2 closes return true
	if(s1=='('&& s2==')' )
	{
		return true;
	}
	else if(s1=='{'&&s2=='}')
	{
		return true;
	}
	else if(s1=='['&&s2==']')
	{
		return true;		
	}
	else
	{
		return false; //else false
	}
}//end fn
