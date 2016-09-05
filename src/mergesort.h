/* 
* Project: Merge Sort Algorithm in C 
* Version: 1.0 
* File: mergesort.h 
* Author: Ariel Segal 
* Date:  Sep 02, 2016 
* Description:
* This header file contains averything needed to sort an array of unsigned integers.
*/ 

/*
	Sorts a list of unsigned integers.
*/
#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include <stdbool.h>

// general compare results
// the criteria which to return one of these values is determined in the
// implementation of the compare function
typedef enum
{
	Tie_e
	, LeftWins_e
	, RightWins_e
} compare_t;

// compare function type. returns result of the compae. accepts two elements of the list
typedef compare_t (*compareFunction_t)(unsigned, unsigned);

// list object type
typedef struct
{
	unsigned size;				// Length of list.
	unsigned *ar;					// pointer to an unsigned int array.
} list_t;

// constructors
// creates a new list from an array of unsigned integers
// this function allocates memory for the object of type list_t
// and for the array, and copies the array
list_t *CreateList(unsigned size, unsigned ar[]);

// creates a new empty list. this function gets the size
// and allocates memory for an array of unsigned integers
// the memory is not initialized
list_t *CreateEmptyList(unsigned size);

// clones a list_t object
list_t *CloneList(list_t *orig);

// destructor
// first frees the memory allocated to the array, and then releases the object
void DestroyList(list_t **list);

// the merge function, implementing the algorithm
list_t *MergeSort(list_t *list, compareFunction_t compare);

// helper functions
// creates two new objects, does not free the original list
void SplitList(list_t *orig, list_t **left, list_t **right);

// creates a new object by merging two objects. does not free memory.
void MergeLists(list_t **merged, list_t *left, list_t *right, compareFunction_t compare);

// output the list
void PrintList(list_t *list);

// compare functions
compare_t DescendingOrder(unsigned left, unsigned right);
compare_t AscendingOrder(unsigned left, unsigned right);

#endif // _MERGESORT_H_

