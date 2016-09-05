/* 
* Project: Merge Sort Algorithm in C 
* Version: 1.0 
* File: sorttest.h 
* Author: Ariel Segal 
* Date:  Sep 02, 2016 
* Description: 
* Black box tests of the merge sort implementation.
* The black box tests, test the merge sort algorithm as a whole in different
* test cases:
* 1. Best case with ascending order, input list is already sorted.
* 2. Worst case with ascending order, input list is in reverse order.
* 3. Normal case with ascending order, input list is unsorted.
* 4. Best case with descending order, input list is already sorted.
* 5. Worst case with descending order, input list is in reverse order.
* 6. Normal case with descending order, input list is unsorted.
*/ 

#ifndef _SORTTEST_H_ 
#define _SORTTEST_H_

#include "mergesort.h"

// run all black box tests
void Sort();

#endif // _SORTTEST_H_

