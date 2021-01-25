/*
implementation of Linked list
and functions defined in List.h

*/

//including List.h
#include "List.h"

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


// Create a new node with next set to NULL
Node* node_new( int data)
{
	Node* ptr;		//pointer 

	ptr = (Node*)malloc(sizeof(Node));		//dynamic memmory allocation using malloc
	
	if(ptr==NULL)	//malloc error
	{
		exit(1);
	}
	else
	{
		ptr->data = data;	// initializing node variables
		ptr->next = NULL;	// next pointer to NULL
	}

	return ptr;

}//end fn


// Create an empty list (head to NULL)
LList* llist_new()
{
	LList* list;	
	
	list = (LList*)malloc(sizeof(LList)) ;		//daynamic memmory allocation for list
		
	if(list==NULL)		//if malloc error
	{
		printf("list not");
		exit(1);
	}	

	return list;
}//end fn


// Traverse the linked list and return its size
int llist_size( LList* lst )
{
	Node* curr;		//temp node
	int count=0;	//to count the no of nodes

	if(lst!=NULL)
	{
		//traversing through list with incrementing count
		for(curr = lst->head; curr!=NULL ; curr = curr->next )
		{
			count++;
		}	

		return count;
	}
	else
	{
		return 0; //if NULL
	}
}//end fn


//linked list and printing each element

void llist_print( LList* lst )
{
	Node* curr;	

	//traversing through the list
	if(lst->head != NULL)
	{
		for(curr = lst->head; curr!=NULL ;curr = curr->next)
		{
			printf("%d ",curr->data);	//printing values
		}
		
		printf("\n");	//new line
	}
}//end fn


//get the element at position idx
int llist_get( LList* lst, int idx )
{
	Node* curr;		//temp node
	int i;

	if(lst->head != NULL)	//checking list is not empty
	{
		curr = lst->head;

		//traversing till idx
		for(i=0;i<idx;i++)
		{
			curr = curr->next;
		}
	
		return curr->data;
	}

}//end fn



// Add a new element at the end of the list
void llist_append( LList* lst, int data )
{
	Node* new = node_new(data);		//creating new node

	Node* curr = lst->head;		//temp node assigned to list head
	
	if(curr==NULL)
	{
		lst->head = new;	//list empty add new node at beginnig
	}	
	else
	{
		//traverse till end
		while(true)
		{
			if(curr->next==NULL)
			{
				curr->next = new; 	//adding new at end
				break;
			}
			curr = curr->next;	// to next link
		}
	}

}//end fn

// Add a new element at the beginning of the list
void llist_prepend( LList* lst, int data )
{

	Node* new = node_new(data);		//creating new link

	Node* tempH = new;

	new->next = lst->head;		//adding at begining

	lst->head = tempH;

}	//end fn


// Add a new element at the idx index
void llist_insert( LList* lst, int idx, int data )
{
	Node* new = node_new(data);		//new link

	int i;		//counter variable
	
	if(idx==0)	
	{
		llist_prepend(lst,data );	//add at begining if idx is 0
	}
	else if(idx==1) //adding at index 1
	{
		Node* curr = lst->head;
		new->next = curr->next;
		curr->next = new;
	}
	else
	{
		Node* curr = lst->head;
		
		//for greater than 1 traversing and adding element
		for(i=0;i<idx-1;i++)
		{
			curr = curr->next;		
		}

		new->next = curr->next;	

		curr->next = new;
	}//end else

}//end fn


// Remove an element from the end of the list
void llist_remove_last( LList* lst )
{
	
	Node* curr = lst->head;		//creating temp to traverse the list
	Node* prev ;	
	Node* prev1;	//previous element
	
	//traversing till end
	while(curr!=NULL)
	{
		prev1 = prev;
		prev = curr;
		curr = curr->next;

	}
	prev1->next = NULL; //removing the last link by assigning NULL to previous pointer


}//end fn


// Remove an element from the beginning of the list
void llist_remove_first( LList* lst )
{
	Node* tempH;
	Node* curr;

	curr = lst->head ;	//temp node to list head

	tempH = curr->next ;	//head to next link

	curr->next = NULL;	//removing first link

	lst->head = tempH;	//list head to next link

}//end fn


// Remove an element from an arbitrary idx position in the list
void llist_remove( LList* lst, int idx )
{
	Node* curr = lst->head;  //curr node to list head

	Node* prev;	//previous node
	
	int i;

	if(idx==0)
	{
		llist_remove_first(lst);	//remove first link if idx is 0
	}
	else
	{
		//traversing till idx node
		for(i=0;i<idx;i++)
		{
			prev = curr ;
			curr = curr->next;		
		}

		prev->next = curr->next ; //previous node point to the next link after idx

		curr->next = NULL;	//idx element pointing to NULL
	}
	

}//end fn

