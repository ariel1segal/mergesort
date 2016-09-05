/* 
* Project: Merge Sort Algorithm in C 
* Version: 1.0 
* File: main.c 
* Author: Ariel Segal 
* Date:  Sep 02, 2016 
* Description: 
*	This program demonstrate the merge sort algorithm. It runs unit tests and
*	black box tests to prove the integrity of the algorithm and the source code.
*/ 

#include <stdio.h>
#include "mergesort.h"
#include "foofootests.h"
#include "sorttest.h"

int main(int argc, char *argv[])
{
	printf("Merge Sort Testing Program\n");
	FooFoo(); // perform unit tests
	Sort();   // perform black box tests
	return 0;
}
