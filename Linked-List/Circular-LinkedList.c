
/*

implement operations on Circular Linked List. These type of
lists have a property that the last node of the list points to first node and thus forms a cyclic-list

*/

#include<stdio.h>
#include<stdlib.h>


// CNode for the link list
typedef struct Node_ CNode;
struct Node_ {
    int data;
    CNode* next;
};

// Create a new node with next set to NULL
CNode* cnode_new( int data);

// Link list structure
typedef struct LList_ {
    CNode* head;
} CList;

// Create an empty list (head shall be NULL)
CList* clist_new();

// Traverse the linked list and return its size
int clist_size( CList* lst );

// Traverse the linked list and print each element
void clist_print( CList* lst );

//get the element at position @idx
int clist_get( CList* lst, int idx );

// Add a new element at the end of the list
void clist_append( CList* lst, int data );

// Add a new element at the beginning of the list
void clist_prepend( CList* lst, int data );

// Add a new element at the @idx index
void clist_insert( CList* lst, int idx, int data );

// Remove an element from the end of the list
void clist_remove_last( CList* lst );

// Remove an element from the beginning of the list
void clist_remove_first( CList* lst );

// Remove an element from an arbitrary @idx position in the list
void clist_remove( CList* lst, int idx );

// reverse the list
void clist_reverse(CList*);


// Create a new node with next set to NULL
CNode* cnode_new( int data)
{
	CNode* ptr = (CNode*)malloc(sizeof(CNode));	//dynamic memmory allocation using malloc
	
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
CList* clist_new()
{
	CList* New = (CList*)malloc(sizeof(CList));	//daynamic memmory allocation for list

	if(New==NULL)	//malloc error
	{
		exit(1);
	}
	else
	{
		New->head = NULL;	//initialising head to NULL
	}

	return New;

}//end fn


// Traverse the linked list and return its size
int clist_size( CList* lst )
{
	int count=1;	//to count the no of nodes

	if(lst->head == NULL)
	{
		return 0;	//if NULL size 0
	}
	else
	{
		CNode* curr = lst->head;	//temp node
		
		//traversing through list with incrementing count
		while(curr->next != lst->head )
		{
			count++;
				
			curr = curr->next;
		}
	}

	return count;
}//end fn



//linked list and printing each element
void clist_print( CList* lst )
{
	if(lst->head== NULL)
	{
		exit(1);
	}
	else
	{
		CNode* curr = lst->head;		
		CNode* rH = lst->head;
	
		//traversing through the list
		while(curr->next != rH)
		{
			printf("%d ",curr->data);	//printing values
	
			curr = curr->next;
		}

		printf("%d \n",curr->data);	//printing last element
	}
}//end fn


//get the element at position idx
int clist_get( CList* lst, int idx )
{
	if(lst->head== NULL)	//no link exit
	{
		exit(1);
	}
	else 
	{
		CNode* curr = lst->head;	
		
		int i;			//counter variable
		//traversing till idx
		for(i=0;i<idx;i++)
		{
			curr = curr->next;	//to next link
		}
	
		return curr->data;	//returning the element

	}
}//end fn


// Add a new element at the end of the list
void clist_append( CList* lst, int data )
{
	if( lst->head==NULL )
	{
		lst->head = cnode_new(data);	//list empty add new node at beginnig
		
		(lst->head)->next = lst->head;		//next to begining of link
	}
	else
	{
		CNode* curr = lst->head;
		
		//travesing till end
		while(curr->next != lst->head)				
		{
			curr = curr->next;
		}
		
		curr->next =  cnode_new(data);		//adding new link
	
		(curr->next)->next = lst->head;		//new link next to head
	}

}//end fn


// Add a new element at the beginning of the list
void clist_prepend( CList* lst, int data )
{
	if(lst->head==NULL)
	{
		lst->head = cnode_new(data);	//list empty add new node at beginnig
		
		(lst->head)->next = lst->head;		//next to begining of link
	}
	else
	{
		CNode* New = cnode_new(data);	//new link
		New->next = lst->head;
			
		CNode* curr = lst->head;
		
		//travesing till end
		while(curr->next != lst->head)				
		{
			curr = curr->next;
		}
		
		curr->next = New;	// last link next to new
		lst->head = New;	//link head to new
	}

}//end fn


// Add a new element at the idx index
void clist_insert( CList* lst, int idx, int data )
{
	
	if(lst==NULL)
	{
		exit(1);
	}
	else if(idx==0)
	{
		clist_prepend( lst,data );	//add at begining if idx is 0
	}
	else if(idx == clist_size(lst) )
	{
		clist_append(lst,data);		//add at end
	}
	else
	{
		CNode* curr = lst->head;	//temp to head
		CNode* prev;


		//traversing till idx
		int i;
		for(i=0;i<idx;i++)
		{
			prev = curr;		//previous node
			curr = curr->next;	//current node
		}		

		CNode* New = cnode_new(data);	//adding new link
		
		New->next = curr;
		prev->next = New;		
		
	}

}//end fn

void clist_remove_last( CList* lst )
{
	if(clist_size(lst)==1)
	{
		lst->head = NULL;
	}
	else
	{
		CNode* rH = lst->head;
		CNode* curr = lst->head;		//creating temp to traverse the list
		CNode* prev ;	
		
		//traversing till end
		while(curr->next != rH)
		{
			prev = curr;
			curr = curr->next;	//next link
	
		}
		
		prev->next = rH;	//next to head
				
		
		free(curr);	//free curr
	}
}//end fn

// Remove an element from the beginning of the list
void clist_remove_first( CList* lst )
{
	//if only one link
	if(clist_size(lst)==1)
	{
		lst->head = NULL;
	}
	else
	{
		CNode* rH = lst->head;		//head temp
		CNode* curr = lst->head;
		
		CNode* prev = rH->next;		//second link
		
		//traversing till end
		while(curr->next != lst->head)
		{
			curr = curr->next;  	//next link
		}			
		
		curr->next = prev;	//last to second

		lst->head = prev;	//head to second

		free(rH);
	}	
}//end fn

void clist_remove( CList* lst, int idx )
{
	if(idx==0)
	{
		clist_remove_first(lst);	//remove first
	}
	else if(idx == clist_size(lst)-1 )
	{
		clist_remove_last(lst);		//remove last
	}
	else
	{
	
		CNode* curr = lst->head;		
		CNode* temp ;
		int i;

		//traversing to idx
		for(i=1;i<idx;i++)
		{
			curr = curr->next;	//to idx
		}	
		temp = curr->next;			//idx link
		curr->next = (curr->next)->next;	//previous to next of idx
		
		free(temp);
		
				
	}	
}//end fn

//recursive fn to reverse
CNode* rec(CNode* curr,CList* lst)
{
	if( (curr->next==lst->head) )
	{
		return curr;		//base condition
	}
	else
	{
		CNode* recH = rec(curr->next,lst);	//calling recursive
		(curr->next)->next = curr;		//  next link's next to current
		curr->next = recH;			//  back to head
		return recH;
	}
}//end fn


//reverse the list
void clist_reverse(CList* lst )
{
	if(lst->head==NULL)
	{
		exit(1);	//no element
	}
	else
	{
		lst->head = rec(lst->head,lst); //calling recursive fn
	}
}//end fn
