/* A function to check the string is whether a palindrome string. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char * s)
{
	char * t = s + strlen(s) - 1;

	for ( ; s < t; ++s, --t)
		if (*s != *t)
			return false;

	return true;
}

int main()
{
	printf("is_palindrome(HellolleH): %d\n", is_palindrome("HellolleH"));
	printf("is_palindrome(Hello): %d\n", is_palindrome("Hello"));

	return 0;
}
