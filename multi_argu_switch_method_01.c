/* The simple demonstration for using switch method to implement the argument selection of a program
 * for multi-arguments.
 */

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define TOTAL_ARGUMENTS 10

int main(int argc, char **argv)
{
	int i;
	int operation;
	int index = TOTAL_ARGUMENTS;

	/* allocate memory for a pointer to pointer which points to a argument array. */
	char ** argument_array =  malloc (sizeof(char *) * index);

	/* Each member of the argument array is a pointer, which points to a 10 byte memory. */
	for (i = 0; i < index; i++)
		argument_array[i] = (char *) malloc (sizeof(char) * 10);

	/* The specific string of argument. */
	argument_array[0] = strdup("");
	argument_array[1] = strdup("-A");
	argument_array[2] = strdup("-BB");
	argument_array[3] = strdup("-CCC");
	argument_array[4] = strdup("-DDDD");
	argument_array[5] = strdup("-EEEEE");
        argument_array[6] = strdup("-FFFF");
        argument_array[7] = strdup("-GGG");
        argument_array[8] = strdup("-HH");
        argument_array[9] = strdup("-I");

	/* search the argument */
	i = index -1;
	while(i) {

		operation = strcmp(argument_array[i], argv[1]);

		if ( operation == 0)
			break;

		i--;
	}

	/* In the switch case to select the corresponding argument. */
	switch(i){
                case 9:
                      printf("argv: %s\n", argument_array[i]);
                      break;
                case 8:
                      printf("argv: %s\n", argument_array[i]);
                      break;
                case 7:
                      printf("argv: %s\n", argument_array[i]);
                      break;
                case 6:
                      printf("argv: %s\n", argument_array[i]);
                      break;
		case 5:
		      printf("argv: %s\n", argument_array[i]);
		      break;
		case 4:
		      printf("argv: %s\n", argument_array[i]);
		      break;
		case 3:
		      printf("argv: %s\n", argument_array[i]);
		      break;
		case 2:
		      printf("argv: %s\n", argument_array[i]);
		      break;
		case 1:
		      printf("argv: %s\n", argument_array[i]);
		      break;
		case 0:
		      printf("wrong argument\n");
		      break;
	}

	return 0;
}
