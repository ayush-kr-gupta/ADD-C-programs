#include  <stdio.h>

int  total_comp  =  0; 

void  swap(int  *a,  int  *b)
{
int  tmp  =  *a;
*a  =  *b;
*b = tmp;
}

void  heapify(int  arr[],  int  n,  int  i)
{
int  largest  =  i;	//  Initialize  largest  as  root 
int  l  =  2  *  i  +  1;  //  left  =  2*i  +  1
int  r  =  2  *  i  +  2;  //  right  =  2*i  +  2

//  If  left  child  is  larger  than  root 
if  (l  <  n  &&  arr[l]  >  arr[largest])
largest  =  l;

//  If  right  child  is  larger  than  largest  so  far 
if  (r  <  n  &&  arr[r]  >  arr[largest])
largest  =  r;

//  If  largest  is  not  root 
if  (largest  !=  i)
{
swap(&arr[i],  &arr[largest]);
//  Incrementing  total  no.  of  comparisons 
total_comp++;
//  Recursively  heapify  the  affected  sub-tree
heapify(arr,  n,  largest);
}
}
//  Main  function  to  do  heap  sort 
void heapSort(int arr[], int n)
{
// Build heap (rearrange array)
int  i =0;
for  (i = n/2-1;  i  >=  0;  i--)
 heapify(arr,  n,  i);


printf("Total  number  of  comparisons:-  %d\n",  total_comp);

//  One  by  one  extract  an  element  from  heap
 for  (i  =  n  -  1;  i  >  0;  i--)
{

swap(&arr[0],  &arr[i]);

heapify(arr,  i,  0);
}
}

 void  printArray(int  arr[],  int  n)
{
	int  i  =  0;
for  ( i  =  0;  i  <  n;  ++i) 
printf("%d  ",  arr[i]); 
printf("\n\n");
}

int main()
{
int  arr[]  =  {13,  32,  689,  69,  84,  11, 7};
int  n  =  sizeof(arr)  /  sizeof(arr[0]); 
heapSort(arr, n);
printf("Sorted  array  is  \n"); 
printArray(arr, n);
}

