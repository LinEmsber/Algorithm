/* An implementation of reversing string function. */

#include <stdio.h>
#include <string.h>

#define XORSWAP(a, b)   ((&(a) == &(b)) ? (a) : ((a)^=(b),(b)^=(a),(a)^=(b)))

/* Reverse a string. */
int reverse_string(char * s)
{
	if ( NULL == s)
		return -1;

	char * start = s;
	char * end = s;

	/* Find the last char index. */
	// end = s + strlen(s) - 1;
	while( *end != '\0' )
		++end;
	--end;

	printf("address of str: %p\n", start);
	printf("address of end: %p\n", end);

	/* Reverse. */
	while( start < end ){
		XORSWAP( *start, *end );
		start++;
		end--;
	}

	return 0;
}


int main()
{
	/* Declare a char array of size 7 and initialize it with the characters:
	 * s,t,r,i,n,g and \0. You are allowed to modify the contents of this array.
	 */
	char ptr[] = "string";

	/* Declare ptr as a char pointer and initializes it with address of string
	 * literal "string" which is read-only. Modifying a string literal is an
	 * undefined behavior. What you saw(segmemtation fault) is one manifestation
	 * of the undefined behavior.
	 */
	// char * ptr = "string";

	printf("Original str: %s\n", ptr);
	reverse_string(ptr);
	printf("Reversed str: %s\n", ptr);

	return 0;
}
