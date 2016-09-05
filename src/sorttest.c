/* 
* Project: Merge Sort Algorithm in C 
* Version: 1.0 
* File: sorttest.c 
* Author: Ariel Segal 
* Date:  Sep 02, 2016 
* Description:
* Black box tests of the merge sort implementation.
*/ 

#include <stdio.h>
#include "sorttest.h"
#include "mergesort.h" 

void SortTest(unsigned array[], unsigned size, char *testName, compareFunction_t compare);

/*
The black box tests, test the merge sort algorithm as a whole in different test cases:
1. Best case with ascending order, input list is already sorted.
2. Worst case with ascending order, input list is in reverse order.
3. Normal case with ascending order, input list is unsorted.
4. Best case with descending order, input list is already sorted.
5. Worst case with descending order, input list is in reverse order.
6. Normal case with descending order, input list is unsorted.
*/
void Sort()
{
	printf("START Sort TESTS\n");
	unsigned array1[10] = {0,1,2,3,4,5,6,7,8,9};
	SortTest(array1, 10, "descending: worst case", DescendingOrder);
	unsigned array2[10] = {9,8,7,6,5,4,3,2,1,0};
	SortTest(array2, 10, "descending: best case", DescendingOrder);
	unsigned array3[10] = {0,9,1,8,2,7,3,6,4,5};
	SortTest(array3, 10, "descending: normal case", DescendingOrder);
	unsigned array4[10] = {9,8,7,6,5,4,3,2,1,0};
	SortTest(array4, 10, "ascending: worst case", AscendingOrder);
	unsigned array5[10] = {0,1,2,3,4,5,6,7,8,9};
	SortTest(array5, 10, "ascending: best case", AscendingOrder);
	unsigned array6[10] = {9,0,8,1,7,2,6,3,5,4};
	SortTest(array6, 10, "ascending: normal case", AscendingOrder);
	printf("END Sort TESTS\n");
}

// merge sort function
/*
Input:
array - array of unsigned integers
size - number of elements in the array
testName - a string with a test name
compare - the compare function
Output:
The function prints three lines:
1. The original array, received in the input.
2. The sorted array.
3. The original array again, to show it was not changed.
*/
void SortTest(unsigned array[], unsigned size, char *testName, compareFunction_t compare)
{
	printf("START %s test\n", testName);
	list_t *list = CreateList(size, array);
	PrintList(list);
	list_t *sortedList = MergeSort(list, compare);
	PrintList(sortedList);
	PrintList(list);
	DestroyList(&list);
	DestroyList(&sortedList);
	printf("END %s test\n", testName);
}
