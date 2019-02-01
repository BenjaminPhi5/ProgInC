#include <ctype.h>
#include <string.h>
#include "revwords.h"

void reverse_substring(char str[], int start, int end) { 
  /* reverse a string */
  int i, j, hold;
  i = start, j = end;
  
  for(; i < j; i++, j--){
	  hold = str[i], str[i] = str[j], str[j] = hold;
  }
}


int find_next_start(char str[], int len, int i) { 
	/* finding position of next start
	  * i must be less than len*/
	  
	 if(i < len){
		 for(; i < len; i++){
			 if((str[i] == ' ' || str[i] == '-') && (isalpha(str[i+1]) || isdigit(str[i+1])))
				 return i+1;
		 }
	 }
	  
	// if no start found, return -1
  return -1;
}

int find_next_end(char str[], int len, int i) {
  /* finds the end of the current word, i must be less than len 
   * --i because we want the character before the space/end!
   * so the for loop will break when i hits len, the last index+ 1, then decrement when it returns*/
  for(; i < len; i++){
	  if(!isalpha(str[i]))
		  break;
  }
  
  return --i;
}

void reverse_words(char s[]) { 
	// First step find the length
	int len = 0;
	for(int i = 0; i < 10000; i++){
		//to prevent it from never ending in case of bad formmated array
		if(s[i] == '\0')
			break;
		len++;
	}
	
	int start, end;
	start = 0, end = find_next_end(s, len, 0);
	while(start != -1){
		reverse_substring(s, start, end);
		start = find_next_start(s, len, end), end = find_next_end(s, len, start);
	}
	
}
