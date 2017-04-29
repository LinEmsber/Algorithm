/* random string generator
 * gcc -Wall -g random_string_generator_01.c && valgrind -v ./a.out
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char ** string_generator(size_t _string_number, size_t _each_string_length)
{
	int i, j;
	char ** ptr_ptr_string;
	char string_tmp[_each_string_length];

	ptr_ptr_string = malloc ( sizeof(char *) * _string_number );

	for (i = 0; i < _string_number; i++){

		ptr_ptr_string[i] = malloc (sizeof(char) * _each_string_length);

		for(j = 0; j < _each_string_length - 1; j++) {
			string_tmp[j] = (rand() % 26) + 'a';
		}
		string_tmp[_each_string_length - 1] = '\0';

		strncpy(ptr_ptr_string[i], string_tmp, _each_string_length);
	}

	return ptr_ptr_string;
}

void free_string(char ** _ptr_ptr_string, size_t _string_number)
{
	int i;

	for (i = 0; i < _string_number; i++){
		free(_ptr_ptr_string[i]);
	}

	free(_ptr_ptr_string);
}

int main()
{
	int i;
	srand( (unsigned) time(NULL) );

	char ** pp = string_generator(100, 32);

	for (i = 0; i < 20; i++)
		printf("string: %s\n", pp[i]);

	free_string(pp, 20);

	return 0;
}
