/* 
* Project: Merge Sort Algorithm in C 
* Version: 1.0 
* File: mergesort.c 
* Author: Ariel Segal 
* Date:  Sep 02, 2016 
* Description:
* Implementation of the merge sort for unsigned integers.
*/ 

#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h" 

// the merge function, implementing the algorithm
/*
Input:
list - pointer to a list object
compare - pointer to a compare function
Output:
The function returns a new list object with the same elements of the original
but sorted.
This function does not change the original list object.
*/
list_t *MergeSort(list_t *list, compareFunction_t compare)
{
	list_t *left;					// holds the left list after splitting
	list_t *right;				// holds the right list after splitting
	list_t *sLeft;				// holds the left list after merging
	list_t *sRight;				// holds the right list after merging
	list_t *sortedList;		// holds the final sorted list
	
	
	if(list->size > 1)		// as long as the list to be sorted is bigger the one
	{
		SplitList(list, &left, &right);			// split list to left and right
		sLeft = MergeSort(left, compare);		// recursive call, sort left list result is in sLeft
		
		// retain sorted list for next recursive iteration
		DestroyList(&left);									// destroy the old left list
		left = CloneList(sLeft);						// copy the sorted result back to left object
		DestroyList(&sLeft);								// destroy the result object created by the sort
		
		sRight = MergeSort(right, compare);		// recursive call, sort right list result is in sRight
		
		// retain sorted list for next recursive iteration
		DestroyList(&right);															// destroy the old right list
		right = CloneList(sRight);												// copy the sorted result back to right object
		DestroyList(&sRight);															// destroy the result object created by the sort
		
		// here the recursion process is on its way up
		MergeLists(&sortedList, left, right, compare); // merge sorted left list and right list, 
																									 // store result in list to be retuned
		DestroyList(&right);													 // free memory of the right list
		DestroyList(&left);                            // free memory of the left list
	}
	else if(list->size == 1)												 // the list has one element, exit from recursion
	{
		sortedList = CloneList(list);									 // return the same list
	}
	return sortedList;															 // return sorted list
}

/*
Merges to sorted lists into one sorted list
Input:
left - holds a pointer to the left list
right - holds a pointer to the right list
compare - holds a pointer to the compare function
Output:
merged - the resulting merged list in a new object
This function does not free the memory of the left and right lists
*/
void MergeLists(list_t **merged, list_t *left, list_t *right, compareFunction_t compare)
{
	*merged = CreateEmptyList(left->size + right->size); // prepare allocated memory for the result
	unsigned leftIndex = 0, rightIndex = 0, mergedIndex = 0;	// indexes to run on the lists
	bool leftEnd = false, rightEnd = false;		// reached end of list indecators
	while(!leftEnd && !rightEnd)	// as long as no list reaches the end
	{
		compare_t cmp = compare(left->ar[leftIndex], right->ar[rightIndex]); // compare the elements
		switch(cmp)	// check comparison result to choose the element on the merged list
		{
		case Tie_e:	// elements are equal
			// choose the element from the left list and move to the next
			// elements in both lists
			// can also choose the element from the right list
			(*merged)->ar[mergedIndex] = left->ar[leftIndex++];
			++rightIndex;
			break;
		case LeftWins_e: // element of the left list precedes
			// choose the element from the left list and move to the next
			// elements in the left list, in next iteration compare with the
			// same right element
			(*merged)->ar[mergedIndex] = left->ar[leftIndex++];
			break;
		case RightWins_e:	// element of the right list precedes
			// choose the element from the right list and move to the next
			// elements in the right list, in next iteration compare with the
			// same left element
			(*merged)->ar[mergedIndex] = right->ar[rightIndex++];
			break;
		default:	// code shoul not reach here!!!!!
			printf("ERROR: Compare function went wild!!!!\n");
			*merged = NULL;
			return;
		}
		// check if any list reached the end
		if(leftIndex == left->size)
			leftEnd = true;
		if(rightIndex == right->size)
			rightEnd = true;
		// next element in the merged list
		++mergedIndex;
	}
	if(!leftEnd || !rightEnd) // if any of lists reached the end
	{
		list_t *tempList; // holds pointer to the longer list
		unsigned tempIndex; // index in longer list starts from the place the short list ends
		if(leftEnd && !rightEnd) // if right list is longer
		{
			tempList = right;
			tempIndex = rightIndex;
		}
		else if(rightEnd && !leftEnd) // if left list is longer
		{
			tempList = left;
			tempIndex = leftIndex;
		}
		// copy the remaining elements in the longer list to the merged list
		for(unsigned i = mergedIndex, j = tempIndex; i < (*merged)->size; ++i, ++j)
			(*merged)->ar[i] = tempList->ar[j];
	}
}

// Split list into two lists, if the list has an even number of elements, the two resulting
// lists are equal. If  the list has an odd number of elements, the right list has one more 
// element then the left list.
// Input:
// orig - list to split
// Output:
// left - resulting left list
// right - resulting right list
void SplitList(list_t *orig, list_t **left, list_t **right)
{
	*left = CreateList(orig->size/2, orig->ar);
	*right = CreateList(orig->size/2 + (orig->size%2? 1: 0), &(orig->ar[orig->size/2]));
}

// Constructor:
// creates a new list object with an array of unsigned integers and the size of the array
list_t *CreateList(unsigned size, unsigned ar[])
{
	list_t *list = (list_t*)malloc(sizeof(list_t)); // allocate memory for the object
	list->size = size; // set size
	unsigned *array = (unsigned*)malloc(sizeof(unsigned)*(size)); // allocate memory for the array
	
	// copy the array to the allocated space
	for(unsigned i = 0; i < size; i++)
		array[i] = ar[i];
	list->ar = array; // set the array of the object
	return list; // return pointer to the object
}

// Constructor:
// Creates a new list object with an uninitialized array with the size of the array.
list_t *CreateEmptyList(unsigned size)
{
	list_t *list = (list_t*)malloc(sizeof(list_t)); // allocate memory for the object
	list->size = size; // set size
	unsigned *array = (unsigned*)malloc(sizeof(unsigned)*(size)); // allocate memory for the array
	list->ar = array; // set the array of the object
	return list; // return pointer to the object
}

// Copy Constructor:
// Creates a new list object by cloning an existing one.
list_t *CloneList(list_t *orig)
{
	list_t *list = (list_t*)malloc(sizeof(list_t)); // allocate memory for the object
	list->size = orig->size; // set size
	unsigned *array = (unsigned*)malloc(sizeof(unsigned)*(orig->size)); // allocate memory for the array

	// copy the array of the origial object to the allocated space
	for(unsigned i = 0; i < list->size; i++)
		array[i] = orig->ar[i];
	list->ar = array;
	return list; // return pointer to the cloned object
}

// Destructor:
// The only way to free the memory of an object.
// This function sets the pointer to the object to NULL.
void DestroyList(list_t **list)
{
	list_t *li = *list; // temp pointer to object
	free(li->ar); // free memory of the array
	free(*list);  // free memory of the object
	*list = NULL; // set the pointer that holds the object to NULL
}

// output the list
void PrintList(list_t *list)
{
	printf("size %u : ", list->size);
	for(unsigned i = 0; i < list->size; i++)
		printf("%u ", list->ar[i]);
	printf("\n");
}

// compare functions

// compare function for unsigned integer in decending order
compare_t DescendingOrder(unsigned left, unsigned right)
{
	compare_t ret;
	if(left == right)
		ret = Tie_e;
	else if(left > right)
		ret = LeftWins_e;
	else if(left < right)
		ret = RightWins_e;
	return ret;
}

// compare function for unsigned integer in acending order
compare_t AscendingOrder(unsigned left, unsigned right)
{
	compare_t ret;
	if(left == right)
		ret = Tie_e;
	else if(left > right)
		ret = RightWins_e;
	else if(left < right)
		ret = LeftWins_e;
	return ret;
}

