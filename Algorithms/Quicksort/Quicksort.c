/**
Quick is a sorting algorithm that, on average, makes O(nlogn) comparisons to 
sort n items. In the worst case, it makes O(n^2) comparisons, though this
behavior is rare. Quicksort is often faster in practice than other O(nlogn)
alrorithms. Additionally, quicksort's sequential and localized memory references work well with a cache.
Quicksort is a comparison sort and, iin efficient implementations, is not a stable sort. Quicksort can be implemented with an in-place partitioning algorithm,
so the entire sort can be done with only O(logn) additional space used by the stack during the recursion.
-----------From Wiki
By Chunting 
2013-04-10

**/


#include <stdio.h>
#define GET_ARRAY_LEN(arr,len){len=(sizeof(arr)/sizeof(arr[0]));}
int arr[]={14,10,11,5,6,15,0,15,16,14,0,8,17,15,7,1,18,7};
/*Swap: exchange the values of v[k] and v[j] */
inline void swap(int v[], int k,int j)
{
	if(v[k]!=v[j]){
		int temp;
		temp=v[k];
		v[k]=v[j];
		v[j]=temp;
	}
}
void quicksort(int v[],int left, int right)
{
	int j,last;
	/*If the lenght of v is smaller than 2, then do nothing */
	if(left>=right)
		return;
	swap(v,left,(left+right)/2);
	last=left;
	for(j=left+1;j<=right;j++)
	{
		if(v[j]<v[left])
		{
			swap(v,last++,j);
		}
	}
	printf("last: %d \tleft: %d \t right: %d\n",last,left,right);
	/*small,small... key, large, large...*/
	quicksort(v,left, last-1);
	quicksort(v,last, right);
}
int getsizeof(int v[])
{
	return 0;
}
int main()
{
	int j,len;
	GET_ARRAY_LEN(arr,len);
	quicksort(arr,0,len-1);
	for(j=0;j<len;j++)
	{
		printf("%d ",arr[j]);
	}

	printf("\n length: %d\n",len);
}



