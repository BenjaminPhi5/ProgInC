#include <stdio.h>
#include <stdlib.h>

void test2();
void numberBases();
void useEnums();
void boolType();
void enumValues();
void scopeExample();
void controlFlow();
void gotoEx();
void bubble();

enum boolean {TRUE, FALSE};
enum months {JAN = 1, FEB = 2, MAR = 3, APR = 4, MAY = 5};


void lecture1(){
	printf("LECTURE 1 \n this is a test ok noice boiiii\n");
	test2();
	numberBases();
	useEnums();
	boolType();
	enumValues();
	scopeExample();
	controlFlow();
	gotoEx();
	bubble();
	return;
}

void test2(){
	printf("aaaaand another\n");
}

void numberBases(){
	int a = 52;
	int b = 064;
	int c = 0x34;
	printf("b is : %d\n", b);
	(a == b && b == (int)c) ? printf("same number\n") : printf("different number\n");
	}
	
void useEnums(){
	
	enum boolean x = FALSE;
	
	for(int i = 0; i < 10; i++){
		printf("i = %d\t", i);
		
		(i == 5) ? x = TRUE : printf("");
		
		if (x == TRUE){
			break;
		}
	}
	
}

void boolType(){
	printf("\n");
	
	_Bool x = 0;
	
	for(int i = 0; i < 10; i++){
		printf("i = %d\t", i);
		
		(i == 5) ? x = 256: printf("");
		
		if(x){
			break;
		}
	}
	
}

void enumValues(){

	enum months m = JAN;
	printf("\njan is the %dst month of the year\n", m);
	
	enum months x = MAR;
	printf("the value of the third element in the enum months is: %d\n", x);
	
	
}

int a;
unsigned char b = 'A';
extern int alpha;

void scopeExample(){

	
	extern unsigned char b;
	double a = 3.4;
	
	{
		extern a;
		printf("hi : %d %d\n", b, a+1);
	}
	
}

void controlFlow(){
	
	char s[]="University of Cambridge Computer Laboratory";
	
	char c;
	int i, j;
	
	for (i=0,j=strlen(s)-1;i<j;i++,j--) /* strlen(s)-1 ? */
	c=s[i], s[i]=s[j], s[j]=c;
	
	printf("%s\n",s);
	
}

void gotoEx(){
	for(int i = 0; i < 5; i ++){
		for(int j = 0; j < 10; j ++){
			if(i==3 && j== 2){
				printf("oink bacon. moo cheese");
				goto error;
			}
		}
	}
	
	error: {printf("\nyou wot m8\n"); printf("cheewsesesesese\n");}
}

/*EXERCISES CODE, WRITING IS ON MY WRITTEN SHEETS OKAY*/

void bubble(){
	
	int x[] = {4,1,2,3};
	int size = sizeof(x)/sizeof(int);
	enum boolean swap = FALSE;
	
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size - i - 1; j++){
			
			if(x[j] > x[j+1]){
				int hold = x[j];
				
				x[j] = x[j+1], x[j+1] = hold;
				
				swap = TRUE;
			}
		}
		
		if(swap = FALSE)
			break;
	}
	
	printf("result: [");
	for(int y = 0; y < size; y++)
		printf("%d",x[y]);
	
	printf("]\n");
}