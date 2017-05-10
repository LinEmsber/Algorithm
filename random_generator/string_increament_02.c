/* The simple algorithm for string increment. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TIMES 64

char ** string_increament(unsigned int _string_len)
{
	int i, j;
	char ** ptr_ptr_string;
	char string[8] = "ABCDEFG";

	ptr_ptr_string = (char **) malloc ( sizeof(char*) * _string_len );

	for (i = 0; i < _string_len; i++){

		ptr_ptr_string[i] = (char *) malloc ( sizeof(char) * 8 );

		for (j = 0; j < 7; j++){
			string[j] ++;
			string[j] = ( (string[j] - 65) % 26) + 65;
		}

		strcpy(ptr_ptr_string[i], string);
	}

	return ptr_ptr_string;
}

void free_string(char ** _ptr_ptr_string, unsigned int _string_len)
{
	int i;

	for (i = 0; i < _string_len; i++)
		free(_ptr_ptr_string[i]);

	free(_ptr_ptr_string);
}


int main()
{
	int i;
	char ** pp = string_increament(TIMES);

	for (i = 0; i < TIMES; i++)
		printf("string: %s\n", pp[i]);

	free_string(pp, TIMES);

	return 0;
}
