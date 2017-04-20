/* The simple algorithm for string increment. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** string_increament(unsigned int _string_len)
{
	int i, j;
	char ** ptr_ptr_string;
	char string_[8] = "ABCDEFG";

	ptr_ptr_string = (char **) malloc ( sizeof(char*) * _string_len );

	for (i = 0; i < _string_len; i++){

		ptr_ptr_string[i] = (char *) malloc ( sizeof(char) * 8 );

		for (j = 0; j < 7; j++){
			string_[j] ++;
			string_[j] = ( (string_[j] - 65) % 52) + 65;
		}

		strcpy(ptr_ptr_string[i], string_);
		printf("string: %s\n", ptr_ptr_string[i]);
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

	char ** pp = string_increament(30);

	free_string(pp, 30);

	return 0;
}
