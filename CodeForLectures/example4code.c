#include <string.h>
#include "example4.h"

/*reverse a string in place */
void reverse(char s[]) {
	int c, i, j;
	for(i = 0, j = strlen(s) -1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}