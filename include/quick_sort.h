/*******************************************
 * DANIEL'S PRIVATE ALGORITHM IMPLEMENTAIONS
 * QuickSort Algorithm
 * Features:
 * 1. sort array in O(nlogn) time.
 * 2. most generic fast sorting algorithm
 *******************************************/
#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include <generic.h> 

/**
 * the quick-sort partition routine
 */
inline int partition(int list[],int begin, int end)
{
	int pivot_idx = choose_pivot(begin,end);
    int pivot = list[pivot_idx];
	swap(list[begin],list[pivot_idx]);

	int i = begin + 1;
	int j = end;
  
	while(i <= j)
	{
		while((i <= end) && (list[i] <= pivot))
			i++;
		while((j >= begin) && (list[j] > pivot))
			j--;
		if(i < j)
			swap(list[i],list[j]);
	}
      
	swap(list[begin],list[j]);
	return j; // final pivot position
}

/**
 * quick sort an array of range [begin, end]
 */
inline void quicksort(int list[],int begin,int end)
{
	if( begin < end)
	{
        int pivot_idx = partition(list, begin, end);
		quicksort(list, begin, pivot_idx-1);
		quicksort(list, pivot_idx+1, end);
	}
}

#endif //
