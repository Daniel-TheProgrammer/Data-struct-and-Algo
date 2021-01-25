/*
Implement Polynomial (of a single variable) ADT using: Linked List
Representation: To keep Coefficient and Exponent – 
(a) Use structures as a node of the list Operations over the polynomials:
1) Print a polynomial (As explained below)
2) Degree of a polynomial,
3) Add two polynomials,
4) Subtract two polynomials,
5) Multiply two polynomials,
6) Evaluate a polynomial (when user inputs a value of polynomial variable)

Write separate functions for each operation. Assuming the numbering in problem statement to be
options for the operation, upon execution, user must be prompted to enter the option number(-1 to
terminate ) followed by desired input for that particular operation


Explanation:

Option 1 & 2:
t (number of terms in the polynomial)
t space separated integers in increasing order denoting the exponents
t space separated integers denoting the coefficients of the respective exponents

Option 3 & 4 & 5:
t1 (number of terms in the first polynomial)
t1 space separated integers in ascending order denoting the exponents
t1 space separated integers denoting the coefficients of the respective exponents
t2 (number of terms in the polynomial)
t2 space separated integers in increasing order denoting the exponents
t2 space separated integers denoting the coefficients of the respective exponents
Option 6: first three lines same as for option 1 & 2
k value of the variable polymoial will be evaluate at


Expected output:

option 1: for a 4 degree polynomial – a0+a1x+a2x^2+a3x^3+a4x^4
where a0,a1.... are coefficients.
option 2: a single integer, i.e. degree of the polynomial
option 3 & 4 & 5: resulting Polynomial in the same format as in option 1
option 6: value of the polynomial at variable= k


*/


#include<stdio.h>
#include "List.h"
#include<stdlib.h>


typedef struct Polynomial_lst{
	LList* exponents;
	LList* coeffs;
}Polynomial;


/*function to return the degree of the polynomial*/
int get_degree(Polynomial);

// print Polynomial
void print_polynomial(Polynomial);

/*Multiply two polynomials and return the result*/
Polynomial multiply(Polynomial, Polynomial);

/*Add two polynomials and return the result*/
Polynomial add(Polynomial, Polynomial);

/*Subtract second Polynomial from first*/
Polynomial subtract(Polynomial p1, Polynomial p2);

/*Evaluate Polynomial at var=k and return the result*/
long long evaluate(Polynomial, int k);





// printing the values for given node of exponent list and coeff list with a flag
void printL(Node* exp,Node* coeff,int f)
{
		if(exp->data==0)	//if exponent o
		{
			printf("%d ",coeff->data);	//print coeff
		}		
		else
		{
			if(f==0)	//if flag 0 means 1st value
			{
				printf("%dx^%d ",coeff->data,exp->data);	//print in format without sign
	
			}
			else
			{
				if(coeff->data > 0)
				{
					printf("+ %dx^%d ",coeff->data,exp->data);	//printing with sign
				}
				else if(coeff->data < 0)
				{
					printf("- %dx^%d ",-(coeff->data),exp->data);		//printing with sign
				}
			}			

		}//end outer else	

}//end fn



// print the polynomial p
void print_polynomial(Polynomial p)
{
	
	Node* exp = (p.exponents)->head;	//exp node to head 
	
	Node* coeff = (p.coeffs)->head;		//coeff node to head
	
	int i=0;	//flag

	//traverse till end
	while(exp != NULL)
	{
		printL(exp,coeff,i);	//print values for each node
			
		//going to next link
		exp = exp->next;
		coeff = coeff->next;	
		i++;

	}//end while

	printf("\n");	//new line

}//end fn

//to get degree of p
int get_degree(Polynomial p)
{

	Node* exp = (p.exponents)->head; //exp to head of list exponents
	Node* prev;		//prev node

	//traversing till end
	while(exp!=NULL)
	{
		prev = exp;
		exp = exp->next;	//to next link
	}
	
	return prev->data; //return the degree

}//end fn


//adding to polynomials
Polynomial add(Polynomial p1 , Polynomial p2)
{
	Polynomial ans;		//to store the added polynomial
	
	//creating lists for ans
	(ans.exponents) = llist_new();
		
	(ans.coeffs) = llist_new();

	//if p1 is empty
	if( (p1.exponents)->head == NULL )
	{
		ans = p2 ;
	}
	else if( (p2.exponents)->head == NULL ) //if p2 is empty
	{
		ans = p1;
	}
	else
	{
		//nodes too head of each lists
		Node* ep1 = (p1.exponents)->head;
		Node* cp1 = (p1.coeffs)->head;

		Node* ep2 = (p2.exponents)->head;
		Node* cp2 = (p2.coeffs)->head;
		
		//traversing till end of one list
		while(ep1!=NULL && ep2!=NULL)
		{
			if( (ep1->data) < (ep2->data) )		//mismatch exponent 
			{
				//append the lesser one
				llist_append(ans.exponents,ep1->data);	
				
				llist_append(ans.coeffs,cp1->data);
				
				//to next link of lists				
				ep1 = ep1->next;
				cp1 = cp1->next;
			}				
			else if(ep1->data == ep2->data)		//same power adding
			{
				int c = cp1->data + cp2->data;	//adding coeffs
				
				//appending at list ans
				llist_append(ans.exponents,ep1->data);
				llist_append(ans.coeffs,c );
							
				//to next link of lists	
				ep1 = ep1->next;
				cp1 = cp1->next;

				ep2 = ep2->next;
				cp2 = cp2->next;
			}
			else if( (ep1->data) > (ep2->data) ) 	//miss match
			{
				llist_append(ans.exponents,ep2->data);
				
				llist_append(ans.coeffs,cp2->data);
				
				//to next link
				ep2 = ep2->next;
				cp2 = cp2->next;
				
			}

		}//end while

		//adding remaining links if any
		while(ep1!=NULL)
		{
			llist_append(ans.exponents,ep1->data);
				
			llist_append(ans.coeffs,cp1->data);
				
			ep1 = ep1->next;
			cp1 = cp1->next;
		}

		//adding remaining links of 2 if any
		while(ep2!=NULL)
		{
				llist_append(ans.exponents,ep2->data);
				
				llist_append(ans.coeffs,cp2->data);
				
				ep2 = ep2->next;
				cp2 = cp2->next;
		}


	}//end else
		
	return ans;

}	//end fn


//to subtract two polynomials
Polynomial subtract(Polynomial p1, Polynomial p2)
{
	//for answer
	Polynomial ans;
	
	(ans.exponents) = llist_new();
		
	(ans.coeffs) = llist_new();

	//p2 is empty
	if( (p2.exponents)->head == NULL )
	{
		ans = p1;
	}
	else
	{
		//nodes to head of each lists
		Node* ep1 = (p1.exponents)->head;
		Node* cp1 = (p1.coeffs)->head;

		Node* ep2 = (p2.exponents)->head;
		Node* cp2 = (p2.coeffs)->head;

		//traversing till end of lesser list
		while(ep1!=NULL && ep2!=NULL)
		{
			if( (ep1->data) < (ep2->data) )		//missmatch append the lesser coeff element
			{
				llist_append(ans.exponents,ep1->data);
				
				llist_append(ans.coeffs,cp1->data);
				
				//to next link
				ep1 = ep1->next;
				cp1 = cp1->next;
			}				
			else if(ep1->data == ep2->data)	//match
			{
			
				int c = cp1->data - cp2->data;	//subtracting coeffs
				
				//appending in ans list
				llist_append(ans.exponents,ep1->data);
				llist_append(ans.coeffs,c );
												
				//to next link
				ep1 = ep1->next;
				cp1 = cp1->next;

				ep2 = ep2->next;
				cp2 = cp2->next;
			}
			else if( (ep1->data) > (ep2->data) )	//mismatch appending lesser exponent 
			{
				llist_append(ans.exponents,(ep2->data) );
				
				llist_append(ans.coeffs,-(cp2->data) );
				
				//to next link
				ep2 = ep2->next;
				cp2 = cp2->next;
				
			}

		}

		//appending remainig of poly1 if any
		while(ep1!=NULL)
		{
			llist_append(ans.exponents,ep1->data);
				
			llist_append(ans.coeffs,cp1->data);
				
			ep1 = ep1->next;
			cp1 = cp1->next;
		}

		//appending remainig of poly2 if any
		while(ep2!=NULL)
		{
				llist_append(ans.exponents,(ep2->data) );
				
				llist_append(ans.coeffs,-(cp2->data) );
				
				ep2 = ep2->next;
				cp2 = cp2->next;
		}


	}//end else
		
	return ans;
		
}//end fn

//evaluating poly at k
long long evaluate(Polynomial p, int k)
{
	//node to head of list
	Node* exp = (p.exponents)->head;
	
	Node* coeff = (p.coeffs)->head;

	long long sum =0;	
	
	//till end of list
	while(coeff!=NULL)
	{
		long long s=1,i;
		for(i=1;i<= exp->data;i++)	//raising to its power
		{
			s = s*k;
		}
		
		sum = sum + ( coeff->data )*s;	//adding to sum 
		
		//to next link
		coeff = coeff->next;
		exp = exp->next;
	}	
	
	return sum;

}//end fn

//multipy two polynomials
Polynomial multiply(Polynomial p1, Polynomial p2)
{

	//the multiplied polynomial
	Polynomial ans;
	
	(ans.exponents) = llist_new();
		
	(ans.coeffs) = llist_new();


	// node to head of each lists
	Node* ep1 = (p1.exponents)->head;
	Node* cp1 = (p1.coeffs)->head;

	Node* ep2 = (p2.exponents)->head;
	Node* cp2 = (p2.coeffs)->head;

	//till the end of first poly
	while(ep1!=NULL)
	{
		//temp to store the each  element multiplied poly
		Polynomial temp;
	
		(temp.exponents) = llist_new();
		
		(temp.coeffs) = llist_new();

		//till end of poly 2
		while(ep2!=NULL)
		{
			//multiplying the elements and storing in temp
			llist_append(temp.exponents,(ep1->data + ep2->data ) );
			llist_append(temp.coeffs,(cp1->data)*(cp2->data) );

			//to next link of poly2
			ep2 = ep2->next;
			cp2 = cp2->next;
		
		}//end while
		
		ans = add(ans,temp);	//adding  answer and temp in answer
		
		//again to head of polynomial2
		ep2 = (p2.exponents)->head;
	    cp2 = (p2.coeffs)->head;
	
		//to next element of poly1
		ep1 = ep1->next;
		cp1 = cp1->next;

	}//end while

	return ans;	

}//end fn
