/* The simple algorithm for string increment. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int i, j;
	char string[8] = "ABCDEFG";

	for (i = 0; i < 10000; i++){

		/* The algorithm for string increment. */
		for (j = 0; j < 7; j++){
			string[j] ++;
			string[j] = ( (string[j] - 65) % 52) + 65;
		}

		printf("string: %s\n", string);
	}

	return 0;
}
