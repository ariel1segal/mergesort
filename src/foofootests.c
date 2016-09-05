/* 
* Project: Merge Sort Algorithm in C 
* Version: 1.0 
* File: foofootests.c 
* Author: Ariel Segal 
* Date:  Sep 02, 2016 
* Description: This file contains the functions of the unit test.
*/ 

#include <stdio.h>
#include "foofootests.h"
#include "mergesort.h" 

// perform all unit tests
void FooFoo()
{
	printf("----- START FooFoo TESTS -----\n");
	CreateAndDestroy();
	Split();
	Merge();
	Clone();
	MergeOne();
	printf("----- END FooFoo TESTS -----\n");
}

// split list of size two and merge it again
/*
This unit test checks that the merge function is correct when merging two lists 
with one elements in each. This is a demonstration that two lists of size one 
can be sorted in one itiration.
The two test cases are:
1. First list comes first.
2. Second list comes first.
A prerequisite for this test is that the split function works.
Order of sort is insignificant for this test, so all merges uses descending order compare function.
*/
void MergeOne()
{
	printf("START Merge lists of size one test\n");
	printf("---\n");
	unsigned array1[2] = {9,8}; // sorted already
	SplitAndMerge(array1, 2, DescendingOrder);
	printf("---\n");
	unsigned array2[2] = {3,4}; // unsorted list
	SplitAndMerge(array2, 2, DescendingOrder);
	printf("---\n");
	printf("END Merge lists of size one test\n");
}

// test the clone constructor
void Clone()
{
	printf("START clone test\n");
	unsigned array[10] = {1,9,2,8,3,0,7,4,6,5};
	list_t *list = CreateList(10, array); // regular constructor
	PrintList(list);
	list_t *cloned = CloneList(list); // construct object by cloning
	PrintList(cloned);
	DestroyList(&list);
	DestroyList(&cloned);
	printf("END clone test\n");
}

// test merging two lists
/*
This unit test checks that the merge function is correct.
The test cases:
1. Merge two lists of even size.
2. Merge when one list is of even size and the other is of odd size.
3. All elements of one list are should end up before the elements of the other.
4. The merge needs to alternate the preceding element between the two lists.
A prerequisite for this test is that the split function works.
Order of sort is insignificant for this test, so all merges uses descending order compare function.
*/
void Merge()
{
	printf("START Merge test\n");
	printf("---\n");
	unsigned array1[10] = {9,8,7,6,5,4,3,2,1,0};
	SplitAndMerge(array1, 10, DescendingOrder);
	printf("---\n");
	unsigned array2[7] = {9,8,7,6,5,4,3};
	SplitAndMerge(array2, 7, DescendingOrder);
	printf("---\n");
	unsigned array3[7] = {9,7,5,8,6,4,3};
	SplitAndMerge(array3, 7, DescendingOrder);
	printf("---\n");
	unsigned array4[10] = {9,7,5,3,1,8,6,4,2,0};
	SplitAndMerge(array4, 10, DescendingOrder);
	printf("---\n");
	printf("END Merge test\n");
}

// helper function that splits a list to two lists and merge them back
/*
This helper function combines the two main functions of the merge sort,
split a list, and merge a list.
This function is called in tests that test the merge function.
*/
void SplitAndMerge(unsigned array[], unsigned size, compareFunction_t compare)
{
	list_t *list = CreateList(size, array);
	PrintList(list);
	list_t *left, *right, *merged;
	SplitList(list, &left, &right);
	PrintList(left);
	PrintList(right);
	MergeLists(&merged, left, right, compare);
	PrintList(merged);
	DestroyList(&list);
	DestroyList(&right);
	DestroyList(&left);
	DestroyList(&merged);
}

// test splitting a list
/*
Test cases:
1. Split a list with an even number of elements.
   The two resulting lists are equel in size.
2. split a list with an odd number of elements.
   One of the resulting lists is longer by one element from the other.
*/
void Split()
{
	printf("START Split test\n");
	unsigned array[10] = {1,9,2,8,3,0,7,4,6,5};
	list_t *list = CreateList(10, array);
	PrintList(list);
	list_t *left, *right;
	SplitList(list, &left, &right);
	PrintList(left);
	PrintList(right);
	DestroyList(&list);
	DestroyList(&right);
	DestroyList(&left);
	unsigned oddArray[7] = {1,9,2,8,3,0,7};
	list = CreateList(7, oddArray);
	PrintList(list);
	SplitList(list, &left, &right);
	PrintList(left);
	PrintList(right);
	DestroyList(&list);
	DestroyList(&right);
	DestroyList(&left);
	printf("END Split test\n");
}

// test constructor and destructor
void CreateAndDestroy()
{
	printf("START Create and Destroy test\n");
	unsigned array[10] = {1,9,2,8,3,0,7,4,6,5};
	list_t *list = CreateList(10, array);
	PrintList(list);
	DestroyList(&list);
	unsigned oddArray[7] = {1,9,2,8,3,0,7};
	list = CreateList(7, oddArray);
	PrintList(list);
	DestroyList(&list);
	printf("END Create and Destroy test\n");
}
