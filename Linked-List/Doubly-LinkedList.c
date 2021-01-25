
/*
to implement functions to perform operations on DoublyLinked-List. These type of lists are used in applications 
which requires traversal in both directions
from the current node. For Example- in lift simulators where movements in both directions happen,
browser history where users can switch back and forth between pages and so

*/

#include<stdio.h>
#include<stdlib.h>


// DNode for the link list
typedef struct Node_ DNode;
struct Node_ {
	int data;
    DNode* prev; 
    DNode* next;
};

// Create a new node with next set to NULL
DNode* dnode_new( int data);

// Link list structure
typedef struct LList_ {
    DNode* head;
} DList;

// Create an empty list (head shall be NULL)
DList* dlist_new();

// Traverse the linked list and return its size
int dlist_size( DList* lst );

// Traverse the linked list and print each element
void dlist_print( DList* lst );

//get the element at position @idx
int dlist_get( DList* lst, int idx );

// Add a new element at the end of the list
void dlist_append( DList* lst, int data );

// Add a new element at the beginning of the list
void dlist_prepend( DList* lst, int data );

// Add a new element at the @idx index
void dlist_insert( DList* lst, int idx, int data );

// Remove an element from the end of the list
void dlist_remove_last( DList* lst );

// Remove an element from the beginning of the list
void dlist_remove_first( DList* lst );

// Remove an element from an arbitrary @idx position in the list
void dlist_remove( DList* lst, int idx );

void dlist_reverse(DList*);

// Create a new node with next set to NULL
DNode* dnode_new( int data)
{

	DNode* ptr = (DNode*)malloc(sizeof(DNode));	//dynamic memmory allocation using malloc
	
	if(ptr==NULL)
	{
		exit(1);	//malloc error
	}
	else
	{
		ptr->data = data;	// initializing node variables
		ptr->next = NULL;
		ptr->prev = NULL;

	}

	return ptr;

}//end fn

DList* dlist_new()
{
	
	DList* New = (DList*)malloc(sizeof(DList));	//daynamic memmory allocation for list

	if(New==NULL)		//malloc error
	{
		exit(1);
	}
	else
	{
		New->head = NULL;		//initialising head to NULL
	}

	return New;

}//end fn

// Traverse the linked list and return its size
int dlist_size( DList* lst )
{
	DNode* curr;		//temp node
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
void dlist_print( DList* lst )
{
	if(lst->head== NULL)
	{
		exit(1);
	}
	else
	{
		DNode* curr = lst->head;		
	
		//traversing through the list
		while(curr != NULL )
		{
			printf("%d ",curr->data);	//printing elements
	
			curr = curr->next;		//next link
		}

	}	

	printf("\n");
}//end fn

//get the element at position idx
int dlist_get( DList* lst, int idx )
{
	DNode* curr;		//temp node
	int i;
	
	if( idx > ( dlist_size(lst)-1 ) )
	{
		return -1;
	}	
	else if(lst->head != NULL)	//checking list is not empty
	{
		curr = lst->head;

		//traversing till idx
		for(i=0;i<idx;i++)
		{
			curr = curr->next;	//next link
		}
	
		return curr->data;	//returning element
	}

}

// Add a new element at the end of the list
void dlist_append( DList* lst, int data )
{
	DNode* new = dnode_new(data);		//new link

	DNode* curr = lst->head;		//temp node assigned to list head

	DNode* erl;				//previous link

	if(curr==NULL)
	{
		lst->head = new;	//list empty add new node at beginnig
			
	}	
	else
	{
		//traverse till end
		while(curr != NULL)
		{
			erl = curr;
			curr = curr->next;
		
		}
		erl->next = new;	//adding new link
		new->prev = erl;	//back linking
	

	}

}//end fn

// Add a new element at the beginning of the list
void dlist_prepend( DList* lst, int data )
{
	DNode* new = dnode_new(data);		//creating new link
	
	DNode* tempH = new;		//temp node

	if(lst->head==NULL)
	{
		lst->head = new;	//if no element add at begining
	}
	else
	{
		new->next = lst->head;		//new next to head
	
		(lst->head)->prev = tempH;	// adding at begining

		lst->head = tempH;
	}
}//end else


// Add a new element at the @idx index
void dlist_insert( DList* lst, int idx, int data )
{
	DNode* new = dnode_new(data);		//new link

	int i;		//counter variable
	
	if( idx > dlist_size(lst) )	//if size is greater
	{
	}
	else if(idx==0)	
	{
		dlist_prepend(lst,data );	//add at begining if idx is 0
	}
	else if( idx == dlist_size(lst) )
	{
		dlist_append(lst,data);		//at end
	}
	else
	{
		DNode *curr = lst->head;		//curr to head
		DNode* erl;				//previous node

		//traversing till idx
		for(i=0;i<idx;i++)
		{
			erl = curr;
			curr = curr->next;	//next link
		}	
		

		new->next = curr;	//new to idx
		new->prev = curr->prev;		//back linking
		erl->next = new;
		curr->prev = new;		

	}

}//end fn


// Remove an element from the end of the list
void dlist_remove_last( DList* lst )
{
	
	DNode* curr = lst->head;		//creating temp to traverse the list
	DNode* erl;	
	DNode* erl1;	//previous element
	
	//traversing till end
	while(curr!=NULL)
	{
		erl1 = erl;
		erl = curr;
		curr = curr->next;

	}
	erl1->next = NULL; //removing the last link by assigning NULL to previous pointer

	erl->prev = NULL;

	free(erl);
}//end fn

// Remove an element from the beginning of the list
void dlist_remove_first( DList* lst )
{
	DNode* tempH;
	DNode* curr;

	curr = lst->head ;	//temp node to list head

	tempH = curr->next ;	//head to next link

	tempH->prev = NULL;	//new link previous NULL

	curr->next = NULL;	//removing first link

	lst->head = tempH;	//list head to next link

	free(curr);
}//end fn

// Remove an element from an arbitrary @idx position in the list
void dlist_remove( DList* lst, int idx )
{
	DNode* curr = lst->head;  //curr node to list head

	DNode* erl;	//previous node
	
	int i;

	if(idx==0)
	{
		dlist_remove_first(lst);	//remove first link if idx is 0
	}
	else
	{
		//traversing till idx node
		for(i=0;i<idx;i++)
		{
			erl = curr ;
			curr = curr->next;		
		}

		erl->next = curr->next ; //previous node point to the next link after idx
		(curr->next)->prev = erl;

		curr->next = NULL;	//idx element pointing to NULL
		curr->prev = NULL;

		free(curr);

	}
	
}//end fn


//recursive fn 
DNode* rec(DNode* head)
{
	if(head==NULL || head->next==NULL )	
	{
		return head;	//base condition
	}
	else
	{
		DNode* recH = rec(head->next);	//recursive call
		(head->next)->next = head;	//curr to next to next to head
		head->prev = head->next;
		(head->next)->prev = NULL;	//
		head->next = NULL;
	
	
		return recH;	//returning head of last link
	}
}//end fn

//fn to reverse list
void dlist_reverse(DList* lst)
{
	if(lst==NULL || lst->head==NULL)
	{
		exit(1);
	}
	else
	{
		lst->head = rec(lst->head);	//calling fn
	}
}//end fn
