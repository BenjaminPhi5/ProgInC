#include <stdio.h>
#include <stdlib.h>
#include "HeaderLecture3.h"

void lecture3(){
	printf("\n\n\n");
	intro();
	pointersEx();
	arrayEx();
	arrayEx2();
	int s[5] = {1,2,3,4,5};
	printarr(s,5);
	copied(s);
	printarr(s, 5);
	int x = 4;
	int y = 5;
	swap2(&x, &y);
	printf("I swapped x and y see: now x = %d, y = %d\n",x,y);
	multdim();
	doSort();
	struct circle c;
	struct circle a = {12,23,5};
	struct circle b = circle_init();
	changeC(&a);
	printf("i changed the value to 3 of the circles x coordinate (the structure ooh) %d\n", a.x);
	printf("b rad is %d\n", b.r);
	unionExample();
	unionExample2();
	bitFieldTest();
	ex1();
	ex2();
	ex3();
	ex4();
	printf("\n\n\n");
}

void intro(){
	printf("LECTURE 3: Pointers and Structures!\n");
}

void pointersEx(){
	int x=1, y=2;
	int * pi;
	int ** ppi;
	
	pi = &x;
	ppi = &pi;
	
	printf("%p, %p, %d=%d=%d\n",ppi, pi, x, *pi, **ppi);
	pi = &y;
	printf("%p, %p, %d=%d=%d\n",ppi, pi, y, *pi, **ppi);
}

void arrayEx(){
	int array[] = {12,22,55,635,897};
	for(int i = 0; i < 5; i++){
		printf("Index is: %d\tAddress is: %p\tValue is: %d\n", i, &array[i], array[i]);
	}
}

void arrayEx2(){
	char str[] = "A string.";
	printf("%s\n", str);
	char * pc = str;
	//my guess, A, A, t
	printf("%c %c %c\n", str[0], *pc, pc[3]);
	pc+=2;
	//my guess, s, r, g
	printf("%c %c %c\n", *pc, pc[2], pc[5]);
}

void copied(int s[]){
	for(int i = 0; i < 5; i++){
		s[i] = 5;
	}
}

void swap2(int * x, int * y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void multdim(){
	int x[5][5];
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(i==j){
				x[i][j] = 1;
			} else {
				x[i][j] = 0;
			}
		}
	}
	
	for(int i = 0; i < 5; i++){
		printarr(x[i], 5);
	}
}

void sort(int a[], const int len, int (*compare)(int,int)){
	int i, j,temp;
	for(i = 0; i < len-1; i++)
		for(j = 0; j < len-1-i; j++)
			if((*compare)(a[j], a[j+1]))
				temp = a[j], a[j] = a[j+1], a[j+1] = temp;
}

int inc(int a, int b){
	return a > b ? 1 : 0;
}

int desc(int a, int b){
	return a < b ? 1 : 0;
}

void doSort(){
	int a[] = {1,4,3,2,5};
	printf("before:\n");
	printarr(a,5);
	unsigned int len = 5;
	sort(a,len,*inc); // or sort(a,len,inc); is fine too wierd
	printf("now:\n");
	printarr(a,5);
	printf("desc");
	sort(a,len,desc);
	printarr(a,5);
}

void changeC(struct circle * pc){
	pc->x = 3, pc->y = 3, (*pc).r = 7;
	//can do pointer->member or else you have to dereferdnce using (*pc).x which looks a bit clumsy
}

struct circle circle_init(){
	struct circle x = {12,12,45};
	return x;
}

void unionExample(){
	union Data data;        

   data.i = 10;
   data.f = 220.5;
   strcpy( data.str, "C Programming");

   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);
   
   
   // when you print this out, you see the values get corrupted, because
   // a union only stores one varible, of one type at a time okay.
   // so the int and float values are lost, instead it tries to represent tge string as those values
}


void unionExample2(){
	
	union Data data;
	
	data.i = 10;
	printf( "data.i : %d\n", data.i);
	
	data.f = 220.45;
	printf( "data.f : %f\n", data.f);
	
	strcpy(data.str, "My Fany String K");
	printf( "data.str : %s\n", data.str);
	
	// now we have changed the values one at at time, the way they are supposed to be used.
	
	return;
}

void bitFieldTest(){
	struct age Age;
	printf( "Sizeof( Age ) : %d\n", sizeof(Age) );
	
	Age.age = 4;
	printf( "Age.age : %d\n", Age.age );
	
	Age.age = 7;
	printf( "Age.age : %d\n", Age.age );
	
	Age.age = 8;
	printf( "Age.age : %d\n", Age.age );
	
	return;
}

/*Exercises OKAY
 * 
 * if p is a pointer, then p[-2] means acces the element two places back
 * 
 * */
 
void ex1(){
	int arr[] = {1,4,1,2,5,6};
	int * parr = arr;
	parr+=5;
	//parr now points to the last element
	printf("second from last element is: %d\n", parr[-2]);
	parr = arr;
	//its only valid if there is an element two places back i think,
	//if not you just accessing memeory before it which may not exist
	//may get segementation fault?
	printf("trying to access to elements before the start (not valid): %d\n", parr[-2]);
}

void ex2(){
	// write a string function that returns a pointer to the first occurance of string s in a string f
	char* s = "world";
	char* f = "hello there world where be the string";
	char* p = strfind(s,f);
	printf("points too: %s\n", p);
}

char* strfind(const char* s, const char* f){
	int end = 10000;
	//to prevent it running forever, incase it fails, due to bad formatted string
	while(end--)
		for(int i, flag = 0; f[i] != '\0'; i++){
			if(s[0] == f[i])
				for(int j = 0; s[j] != '\0'; j++)
					(s[j] == f[i+j]) ? (flag = 1) : (flag = 0);
				
			if(flag)
				return (f+i);
		}
	return NULL;
}

struct ex ex_init(int n){
	struct ex next;
	struct ex a = {{n,n,n,n,n}, n, &next};
	return a;
}

void ex3(){
	//my structures are in the header file
	struct ex a = ex_init(1);
	struct ex b = ex_init(5);
	struct ex c = ex_init(8);
	struct ex arr[] = {a, b, c};
	struct ex * p = arr;
	
	//SNIPPET 1
	/*This snippet access the value j in array a pointed to by p and increments it
	 * before multiplying it by 3. so it increments it from 1 to 2, and then
	 * multiplies it by 3, so it should now hold 6.
	 * */
	++p->j, p->j *= 3;
	printf("Snippet 1\n");
	printf("the value of j at structure a is now: %d\n--\n", (arr)->j);
	
	//SNIPPET 2
	/* This snippet sets the value of j in the structure a to be 27
	 * before incrementing the pointer by one to point to structure b*/
	p++->j = 27;
	/* so now p points to b, so this will change b,j to 10*/
	p->j *= 2;
	printf("Snippet 2\n");
	printf("the value of j at structure a is now: %d\n", (arr)->j);
	printf("the value of j at structure b is: %d\n--\n", (arr+1)->j);
	
	//SNIPPET 3
	/* This will change the value of j in structure be to be equal to
	 * the value of the first element in the list i in structure b, namely 5
	 * This is because *p->i dereferences the pointer stored at p->i which is an array
	 * of five fives.
	 */
	p->j = *p->i;
	printf("Snippet 3\n");
	printf("the value of j at structure b is: %d\n--\n", (arr+1)->j);
	
	//SNIPPET 4
	/*This is going to be used to assign the value of j in structure c
	 * (as p currently points to p, p+1 is c's pointer.
	 * now *p->k++ is dereferencing the pointer at p->k, which is the 'next'
	 * structure in structure b. It is dereferenced, so it holds the actual structure itself, so we use . not ->.
	 * after the expression is finished, the pointer k is incremented, what it points to who knows)
	 * the value of j taken from it to assign to j in c will be 0, since nexts value are never
	 * assigned, so they all default to 0.
	 * */
	printf("Snippet 4\n");
	(p+1)->j = (*p->k++).j;
	printf("the value of j at structure c is now : %d\n", (arr+2)->j);
	printf("what will we find at the k pointer now its been incremented, who knows");
	printf("the j value that it supposedly holds is: %d\n--\n", (*p->k).j);
	
	
	//SNIPPET 5
	/*This snippet of code is assigning the value of j in structure a now.
	 * It is assigning it to the dereferenced value of the pointer pointing to the
	 * array in structure b (which p points to), so it will point to the first element which is a
	 * 5. This will then be incremented afterwards, so that the first element becomes 6,
	 * all other elements will remain 5 (in the array in structure b)*/
	(p-1)->j = (*p->i)++;
	printf("Snippet 5\n");
	printf("the value of j at structure a is now: %d\n", (arr)->j);
	printf("the value of i[0] at structure b is now: %d\n", (arr+1)->i[0]);
	printf("the value of i[0] at structure b is still: %d\n--\n", (arr+1)->i[1]);
	
	
	//SNIPPET 6
	/*This code will get the pointer k in structure b (which p points to)
	 * after the expression is finished p is incremented, to point to c
	 * also the value of j in the k structure at b is set to 27
	 * since p now points to c, the value of j in c should now be 125*/
	(*p++->k).j = 27;
	p->j = 125;
	printf("the value of j at structure k in structure b is now: %d\n", (arr+1)->k->j);
	printf("the value of j at structure c should be 125: %d\n--\n", (arr+2)->j);
	
	//All snippets have now been used. noice.
	
}

void ex4(){
	/*This is a dedicated program, see project folder calc*/
	printf("This is a dedicated program, see project folder calc\n");
}