#include <stdio.h>
#include <stdlib.h>
#include "HeaderLecture4.h"

void lecture4(){
	printf("\n\n");
	intro();
	constEx();
	structType();
	gotcha1();
	gotcha2();
	gotcha3();
	gotcha4();
	gotcha5();
	printf("\n\n");
}

void intro(){
	printf("LECTURE 4: Misc: Library features, gotchas, hints + tips\n");
}


void constEx(){
	int i = 32;
	int j = 28;
	
	const int * pc = &i; // pc is a pointer to a constant, so int const * pc also acceptable
	// *pc = 41; this will not complie:
	/*not allowed because this is assigning the value hold in i, which it cant
	even though i is not decalred constant, it is as far as pc is concerned, so the dereferenced
	value cannot be changed.
	*/
	pc = &j; // this is fine, it is changing pc which is not itself constant.
	
	int * const cp = &i; // here the pointer itself is a constant, not the value that it points to.
	*cp = 41; // This time this is valid, as the dereferneced value itself is not a pointer, just the pointer.
	// cp = &j; However, this is wrong and will not compile, as it is trying to modify the pointer itself, which is constant
	
	const int * const cpc = &i; // Now both the pointer and the valueit points to are constant, so neither can be changed, hence:
	// *cpc = 41; // wrong, the value pointed to is constant
	// cpc = &j; // wrong, the pointer itself is constant too.
	
	const int k = 12;
	//k = 3; // This is wrong because the value is constant.
	int * pk = &k; // this is the normal thing.
	*pk = 55;
	
	int normal = 5;
	int * pn = &normal;
	printf("the address of the normal variable is:                 %p\n", &normal);
	printf("ther address of the pointer is the same:               %p\n", pn);
	
	printf("the address of the const variable is:                  %p\n", &k);
	printf("the address of the pointer to the const variable is:   %p\n", pk);
	printf("the value of k the const variable is:                  %d\n", k);
	printf("but the value pointed to at pk is:                     %d\n", *pk);
	printf("but the address of pk now is still the same:           %p\n", pk);
	printf("and the address of const variable k now is:            %p\n", &k);
	
	// I DO NOT UNDERSTAND THIS, THEY BOTH HAVE THE SAME ADDRESS BUT HOLD DIFFERENT VALUES
}

void structType(){
	printf("My linked list data type has been made, and using typedef\n");
	//llptr a;
	//a->val = 5;
	struct llist x;
	llptr a = &x;
	a->val = 5;
	printf("I can point to it easily with my variable a");
	struct llist y;
	llptr b = &y;
	b->val = 2;
	a->next = b;
	printf("Now I hve a linked list, with a pointer a. the first element is: %d\n", a->val);
	printf("The second element is: %d\n", a->next->val);
}

/*
 * I havent put anything about files and memory alloc here, youll need to read about it
 * at some point though, its in with all the library stuff go look it up
 * */
 
 void gotcha1(){
	// uses a structure test.
	//operator precedence here.
	
	test_t a,b;
	test_t * p[] = {&a, &b};
	p[0]->i = 0;
	p[1]->i = 0;
	test_t * q = p[0];
	
	printf("the test we do: %d\n", ++q->i); // What does this do.
	// My guess is that it incremenst the value pointed to by q->i, which is the i value in a;
	printf("a's value is: %d\n", a.i);
	printf("b's value is: %d\n", b.i);
	
	return;
}

void gotcha2(){
	//more operator precedence
	
	int i = 2;
	int j = i++ + ++i;
	printf("i and j are : %d, %d\n", i, j); // What does this print;
	return;
}

char * unary(unsigned short s){
	char local[s+1];
	int i;
	for(i = 0; i < s; i++) local[i] = '1';
	local[s] = '\0';
	return local; // this seems to return a string of 1's the size of s, with a end symbol at the end
	// but actually it returns the address of stack memory, will not print a string out for some reason.
}

void gotcha3(){
	printf("what does this print: %s\n", unary(6)); //but however it prints nothing, even though derefernced, the first element is a 1.
	printf("what does this print: %c\n", *unary(6));
	printf("what does this print: %c\n", *(unary(6)+1));
	printf("what does this print: %c\n", *(unary(6)+6)); // I do not get this one, something to do with everything is locally decalred in unary, not accessible to the callign function.
}

char global[10];

char * unary2(unsigned short s){
	char local[s+1];
	char *p = s%2 ? global : local;
	int i;
	for(i = 0; i < s; i++) p[i] = '1';
	p[s] = '\0';
	return p; // this seems to return a string of 1's the size of s, with a end symbol at the end
	// but actually it returns the address of stack memory, and not a global variable is s is odd, is s is even then the memory is globally accesible.
}


void gotcha4(){
	//more local stack problems
	printf("unary2 function: %s\n",unary2(6)); //What does this print?
}


struct values{int a; int b;};

void gotcha5(){
	//gotta be careful with them pointers.
	struct values test2 = {2,3};
	struct values test1 = {0,1};
	
	int *pi = &(test1.a);
	pi +=1; // Is this sensible, no the structures are not like arrays, and you dont nessesarily know
	//the size of the thing stored in the structure, so might not point to what you think.
	printf("the value pointer to by pi is now: %d\n", *pi);
	pi += 2; //What could this point at; //this could point at literally anything, no gaurantee it points to an element in test 2 at all;
	// but it does seem to point to element b in test 2 which is odd.
	printf("the value pointer to by pi is now: %d\n", *pi);
	
	printf("the adress of test 2: %p\n", &test2);
	printf("the adress of test 1: %p\n", &test1);
	// test1 has indeed be placed before test2 in memory in this case.
	return;
}