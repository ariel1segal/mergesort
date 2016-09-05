/* 
* Project: Merge Sort Algorithm in C 
* Version: 1.0 
* File: foofootests.h 
* Author: Ariel Segal 
* Date:  Sep 02, 2016 
* Description: This header file contains the prototypes of the unit test functions.
*/ 

#ifndef _FOOFOOTESTS_H_
#define _FOOFOOTESTS_H_

#include "mergesort.h"

// run all unit tests
void FooFoo();

// test constructor and destructor
void CreateAndDestroy();

// test splitting a list
void Split();

// test merging two lists
void Merge();

// helper function that splits a list to two lists and merge them back
void SplitAndMerge(unsigned array[], unsigned size, compareFunction_t compare);

// test the clone constructor
void Clone();

// split list of size two and merge it again
void MergeOne();

#endif // _FOOFOOTESTS_H_

