#include <stdio.h>
#include <stdlib.h>
#include "HeaderLecture6.h"

#define BIG_NUMBER 1000000000

lecture6(){
	printf("\n\n");
	intro();
	speed();
	printf("\n\n");
}

void intro(){
	printf("LECTURE 6: The memory hierarchy and cache optimisation\n");
}

void increment_every(int *array){
  for (int i = 0; i < BIG_NUMBER; i += 1)
    array[i] = 0;
}
void increment_8th(int *array) {
  for (int i = 0; i < BIG_NUMBER; i += 8)
    array[i] = 0;
}
void increment_16th(int *array) {
  for (int i = 0; i < BIG_NUMBER; i += 16)
    array[i] = 0;
}

void speed(){
	int * arr = malloc(BIG_NUMBER * sizeof(int));
	printf("increment every\n");
	increment_every(arr);
	printf("increment 8ths\n");
	increment_8th(arr);
	printf("increment 16ths\n");
	increment_16th(arr);
	printf("done\n");
	printf("as you can see, the 16ths is much faster");
}