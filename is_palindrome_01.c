/* A function to check the string is whether a palindrome string. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char* s)
{
	int i, j;
	int len = strlen(s);

	for ( i = 0, j = len - 1; i < j; ++i, --j)
		if (s[i] != s[j])
			return false;
	return true;
}

int main()
{
	printf("is_palindrome(HellolleH): %d\n", is_palindrome("HellolleH"));
	printf("is_palindrome(Hello): %d\n", is_palindrome("Hello"));

	return 0;
}
