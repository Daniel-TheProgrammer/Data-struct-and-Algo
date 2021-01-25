
/*
implementation of All Sorting algorithms
- bubble sort
- insertion sort
- selection sort
- merge sort
- quick sort

*/

void bubble_sort(int*, int);
void selection_sort(int*, int);
void insertion_sort(int*,int);
void quick_sort(int*,int,int);
void merge_sort(int*,int,int);


/*bubble sort*/
void bubble_sort(int* a, int n)
{

	int i,j;	//counter ariables

	//iterating till n-1 elements
	for(i=0;i<n-1;i++)
	{
		//n-1-i comparison each elements
		for(j=0;j<n-1-i;j++)
		{
			//swaping the no if its greater than next element
			if(a[j]>a[j+1])
			{
				int temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}//end for
	
	}//end for

}//end fn


/*selection sort*/
void selection_sort(int* a, int n)
{
	int i,j,minIndex;	//counter variables and index of minmum elements

	//iterate till n-1
	for(i=0;i<n-1;i++)
	{
		minIndex = i;	//initializing min index
		
		/*n-1 comparisons each elements*/
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[minIndex])	//finding min elements
			{
				minIndex=j;	//assigning to min index
			}
		}
		
		//swaping the min element if its not equal to that no
		if(i!=minIndex)
		{
			int temp=a[i];
			a[i]=a[minIndex];
			a[minIndex]=temp;
		}
	}//end for

}//end selection sort


/*inserion sort*/
void insertion_sort(int* a,int n)
{
	int i,j;	//counter variables

	//for each elements
	for(i=1;i<n;i++)
	{
		
		int temp= a[i];		//storing a[i] to temp
		
		/*if the element is smaller then previous one shift it upwards*/
		for(j=i;j>0&&temp<a[j-1];j--)	
		{
			a[j]=a[j-1];
			a[j-1]=temp;
		}
	}//end outer for
	
}//end insertion sort



/*function to split the array with given m into two arrays and merge it i sorted order*/
void merge(int* a,int l,int m,int r)
{

	int n2= r-m;	//size of right array
	int n1=  m-l+1;	//size of leaft array

	int l1[n1],l2[n2];	//two array two store each side

	int x,y; //counter variables
	
	/*copying elements in left and right array*/
	for(x=0;x<n1;x++)
	{
		l1[x]=a[l+x];
	}

	for(y=0;y<n2;y++)
	{
		l2[y]=a[m+1+y];
	}

	//counter variables
	int i=0,j=0,k=l;

	//merging the left and right in soorted order
	while(i<n1 && j<n2)
	{
		if(l1[i]>l2[j])
		{
			a[k]=l2[j];
			k++;			
			j++;
		}
		else
		{
			a[k]=l1[i];
			k++;
			i++;
		}
	}//end while

	//copy the remaining elements of l1 at end
	while(i<n1)
	{
		a[k]=l1[i];
		k++;
		i++;		
	}
		
	//copy the remaining elements of l2 at end 
	while(j<n2)
	{
		a[k]=l2[j];
		k++;		
		j++;
	}

}//end merge fn


/*recursive fn for mrge sort*/
void merge_sort(int* a,int l,int r)
{	
	
	if(l<r)
	{
		int m=l+(r-l)/2;	//splitting in two halves
		
		//recursive calls to each side
		merge_sort(a,l,m); 	
		merge_sort(a,m+1,r);
	
		// merging the two splitted parts		
		merge(a,l,m,r);				
	}
}//end merge sort


//two swap two elements
void swap(int* a,int* b)
{
	int temp = *a ;
	*a = *b;
	*b = temp;	
}

//partition the array based on the last element of array
int part(int* a,int l,int r)
{
	int sel= a[r];	//selection element is last element
	int i = (l-1);	//counter variable

	//iterating for each elments	
	for (int j = l; j <= r- 1; j++)
    	{
        	//if no is less than slection element swap that no. to left
        	if (a[j] <= sel)
        	{
        	    i++;    
        	    swap(&a[i], &a[j]);
        	}
    	}

	swap(&a[i + 1], &a[r]); //swap the selection element to its postion 
	
	return (i + 1);	// return the index of selection element

}//end part

/*recursive fn quick sort */
void quick_sort(int* a,int l,int r)
{
	 if (l < r)
    	{
        
        	int pi = part(a,l,r);	//partitioning the array based on last element
 
        	quick_sort(a, l, pi-1);		//quick sort left partition
        	quick_sort(a, pi + 1, r);	//quick sort right partition

    	}						
				
						
}//end quick sort
