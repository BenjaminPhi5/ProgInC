#include <stdio.h>
#include <stdlib.h>


void lecture1();
void lecture2();
void lecture3();
void lecture4();
void lecture5();
void lecture6();


int main(int argc, char **argv)
{
	printf("\n\nhello world\n");
	lecture1();
	lecture2();
	lecture3();
	lecture4();
	lecture5();
	lecture6();
	printf("\n\n");
	return 0;
}

void myExternFunction(){
	printf("Thhsi function is an externally declared function to its use,\n(declared here, used in lecture 2)\n");
}
