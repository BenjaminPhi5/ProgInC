#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "example4.h"
#include <ctype.h>
#include "HeaderLecture2.h"
// Need the header files suggested above for all of the function declarations.

void lecture2(){
	intro();
	myExternFunction();
	printf("here is a function that doesnt check its arguments, add, %d\n", add('a',5));
	printf("here is a function that does check its arguments, checkAdd, %d\n", checkAdd((char)'a',5));
	printf("Youp can have a function with variable numbers of parameters.\n");
	printf("here is a call to the function min, with numbers 4,6,3 (and the arg count of 3) min = %d\n", min(3,4,6,3));
	printf("and a call with numbers 5,3,6,2,7,5,9, min = %d\n", min(7, 5,3,6,2,7,5,9));
	printf("and here a function for calcualting average of variable number of numbers\n");
	printf("aveage of 1,5,3,5,8,5,3,5,3,3 is: %d\n", average(10,1,5,3,5,8,5,3,5,3,3));
	printf("recursion with the factorial function: fact(4): %d", fact(4));
	printf("unsigned ints return false as a test (if n) when n is 0 for example: check n = 4\n");
	check(4);
	printf("using a header and another file to store some code:, reverse a string\n");
	char s[] = "Reverse this string please";
	reverse(s);
	printf("Reversed  it is: %s\n", s);
	triTest();
	preprocessorTest();
	printf("Exercises\n");
	/* Testing for exercises */
	printf("count number of lower case in 'Hello There :)', = %d\n", countlower("Hello There :)", 15));
	printf("count number of lower case in 'u Wot M8', = %d\n", countlower("u Wot M8", 15));
	printf("test condition on mod: %s\n", !(2 % 2) ? "true" : "false");
	int anarr[] = {2,4,7,9,1,3,5,6};
	int anarr2[] = {5,6,7,8,1,2,3,4};
	int anarr3[] = {1,2,3,5,6,6,7,8};
	int anarr4[] = {9,10,12,1,6,2,7,8,9};
	myMerge(anarr4, 9);
	printref(anarr4, 9);
	testSwap();
	return;
}


void intro(){
	printf("\n\n\nLECTURE 2: Functions and the Preprocessor\n");
	return;
}

int add(int a, int b){
	return a + b;
}

int checkAdd(int a, int b){
	return a+b;
}

int min(int arg_count,...){
	
	int i, min, a;
	
	va_list ap;
	va_start(ap, arg_count);
	
	min = 10000;
	
	for(i = 0; i < arg_count; i++)
		if((a = va_arg(ap, int)) < min)
			min = a;
	
	va_end(ap);
	
	return min;
}

int average(int arg_count,...){
	
	int i, averageN;
	
	va_list ap;
	va_start(ap, arg_count);
	
	averageN = 0;
	
	for(i = 0; i < arg_count; i++)
		averageN += va_arg(ap, int);
	
	va_end(ap);
	
	return averageN / arg_count;
	
}

unsigned int fact(unsigned int n){
	return n ? n*fact(n-1) : 1;
	// this is cool, unsigned int will return false if givwn:
}

unsigned int check(unsigned int n){
	return n ? (printf("true for n : %d\n", n), check(n-1)) : printf("false for n : %d\n", n), 1; 
}

void triTest(){

	printf("Hello World??=");
}

void preprocessorTest(){
	const unsigned int a1 = 3;
	const unsigned int i = JOIN(a,1);
	printf("%u %g\n", i, MAX(PI, 3.14));
	DPRINT(MAX(PERCENT(0.32+0.16), PERCENT(0.15+0.48)));
	return;
}

/* Exercises are here */
int countlower(char str[], int len){
	int count = 0;
	
	for(int i = 0; i < len; i ++){
		if(islower(str[i]))
			count += 1;
	}
	
	return count;
}

void myMerge(int* arr, unsigned int len){
	
	//setup the temporary address
	int* tempArr;
	tempArr = (int*) malloc(len * sizeof(int));
	
	// Run the algorithm
	mergeSort(arr, tempArr, 0, len-1);
	
}

void mergeSort(int* arr, int* tempArr, unsigned int p, unsigned int r){
	/* arr, the array to sort, tempArr temporary space, the size of the array
	 * p is the starting position to sort from and r is the end point (so
	 * in the first pass these will be the first and last elements).
	 */
	 
	// base case, list to sort is of length 1, in which case p = 1, so we return
	// else, divide into two halfs, run recurisvely on those, and then combine
	if (p < r){
		int q = (p+r)/2;
		mergeSort(arr, tempArr, p, q);
		mergeSort(arr, tempArr, q+1, r);
		merge(arr, tempArr, p, q, r);
	}
	
	return;
}

void merge(int* arr, int* tempArr, unsigned int p, unsigned int q, unsigned int r){
	/* arr is the array to be sorted, tempArr is an array of the same size,
	 * p is the first element pointer of the left half, q is the last element
	 * of the first half, and r is the point to the end of the right half
	 * (right half starts at q+1)
	 * */
	int i,j,k;
	
	//copy the entire relevant range into the temporary array, which has identitcal
	//locations to the actual array
	for(i = 0; i <= r-p; i++){
		//tempArr[p+i] = (arr[p+i]);
		*(tempArr+p+i) = *(arr+p+i);
	}
	
	j = 0, k = 1;
	
	for(i = p; i <= r; i++){
		/* j < q-p then left hand side is still not empty
		 * k < q-r then right hand side is still nto empty*/
		 if(j <= q-p){
			 if(k <= r-q){
				 // both still not empty
				// (tempArr[j+p] < tempArr[k+q]) ? (arr[i] = tempArr[j+p]), j++ : (arr[i] = tempArr[k+q]), k++;
				(*(tempArr+j+p) < *(tempArr+k+q)) ? (*(arr+i) = *(tempArr+j+p)), j++ : (*(arr+i) = *(tempArr+k+q), k++);
			 } else {
				 // right hand side full, fill with rest of left
				 for(; j <= q-p; j++){
					  //printf("left: %d\n", *(tempArr+j+p));
					 //arr[i] = tempArr[j+p], i++;
					 *(arr+i) = *(tempArr+j+p), i++;
				 }
			 }
		 } else {
			 // left hand side full, fill with rest of right
				for(; k <= r-q; k++){
					//printf("right: %d\n", *(tempArr+k+q));
					//arr[i] = tempArr[j+p], j++;
					*(arr+i) = *(tempArr+k+q), i++;
				}
		 }
	}
}

/*
 * Space complexity of my MERGE SORT
 * because it uses references to the array, instead of taking copies
 * it is n elements in the array and n in the temporary array, and there is a copy
 * of each pointer to the array copied with each function call, so at
 * the deepest point there will be lg n pointers, so overall complexoty is O(n)
 * */

void testSwap(){
	int v[] = {2,2,2,2};
	int w[] = {0,0,1,2,3};
	int i = 1;
	int x = 2;
	printf("I swapped the number 2 and 3 from some arrays and functions\n");
	printf("now they are swapped: %d, %d\n", SWAP(int, v[i++], w[f(x)]));
}

int f(int x){
	return 2*x;
}

/*MACROS
 * I am not quite sure what is being asked for number 3, but yes my macro does
 * indeed work for the definition specified.
 * The macro would not work if you were doing say v[i++,x] in a macro
 * because in the arguments of a macro brackets do not have to balance,
 * i.e when the preprocessor sees a comma, it thinks it has reached the end of an
 * argument.
 * my macro did not use a temporary.
 * */

void printarr(int arr[], len){
	printf("array is : [");
	for(int i = 0; i < len; i++){
		printf("%d, ", arr[i]);
	}
	printf("]\n");
	return;
}

void printref(int * arr, len){
	printf("is : [");
	for(int i = 0; i < len; i++)
		printf("%d, ", *(arr+i));
	printf("]\n");
	return;
}