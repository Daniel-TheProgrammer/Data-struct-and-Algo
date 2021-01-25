/*

Implement Counting Sort.

Input:
Two space separated values n and k where n is the size of the array and array elements 2[0,k]
n array elements

Output A single line containing the array elements sorted in ascending order

*/

#include<stdio.h>


/*function to print the array*/

void printar(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}


}//end fn


/*mai fn*/

int main()
{
	int n;		//no of elements	
	int k;		//maximum element
	
	scanf("%d %d",&n,&k);		//taking input n and k
	
	int i,j;			//counter variables
	
	int a[n];			
	
	/*taking input in array*/
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	
	int b[k+1];		//temporary array of size k+1
	
	/*initializing elements of temporary array to 0*/
	for(i=0;i<k+1;i++)
	{
		b[i]=0;
	}
	
	/*counting the digits of array given in temporary array*/
	for(i=0;i<n;i++)
	{
		b[(a[i])]++;
	}
	
	int c[n];		//array to store sorted elements
	
	j=0;	//initializing j
	
	/* storing the elements form temporary array to c*/
	for(i=0;i<k+1;i++)
	{
		while(b[i]>0)
		{
			c[j]=i;
			j++;
			b[i]--;
		}
	}
	printf("\n");
	
	printar(c,n);	//printing sorted array
	
	return 0;
	
}//end main

