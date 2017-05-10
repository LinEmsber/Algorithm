/* random string generator
 * gcc -Wall -g random_string_generator_01.c && valgrind -v ./a.out
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 4


char ** random_string_generator(size_t _each_string_length, size_t _string_count)
{
	int i, j;
	char ** ptr_ptr_string;
	char string_tmp[_each_string_length];

	ptr_ptr_string = malloc ( sizeof(char *) * _string_count );

	for (i = 0; i < _string_count; i++){

		/* create the memory space for each string */
		ptr_ptr_string[i] = malloc (sizeof(char) * _each_string_length);

		/* generate the random string */
		for(j = 0; j < _each_string_length - 1; j++) {
			string_tmp[j] = (rand() % 26) + 'a';
		}
		string_tmp[_each_string_length - 1] = '\0';

		/* copy the random string to the target string */
		strncpy(ptr_ptr_string[i], string_tmp, _each_string_length);
	}

	return ptr_ptr_string;
}

void free_string(char ** _ptr_ptr_string, size_t _string_count)
{
	int i;

	for (i = 0; i < _string_count; i++){
		free(_ptr_ptr_string[i]);
	}

	free(_ptr_ptr_string);
}

int main()
{
	int i;
	srand( (unsigned) time(NULL) );

	char ** pp = random_string_generator(32, COUNT);

	for (i = 0; i < COUNT; i++)
		printf("string: %s\n", pp[i]);

	free_string(pp, COUNT);

	return 0;
}
