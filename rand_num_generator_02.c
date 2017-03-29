/* Random Number Generator, RNG.
 * Using /dev/urandom to generate a random integer number array
 *
 * Reference:
 * http://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Randomization.html
 * https://sockpuppet.org/blog/2014/02/25/safely-generate-random-numbers/
 * http://insanecoding.blogspot.tw/2014/05/a-good-idea-with-bad-usage-devurandom.html
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_arr(uint8_t *arr, int len)
{
        int i;

        for ( i = 0; i < len; i++)
                printf("%d ", *(arr + i) );

        printf("\n");
}

int  main(int argc, char *argv[])
{
	int i;
        // int n = atoi()

	FILE *f;
        uint8_t rand_val;
	uint8_t rand_val_array[ atoi(argv[1]) ];

	f = fopen("/dev/urandom", "r");

	for (i = 0; i < atoi(argv[1]); i++){
		fread(&rand_val, sizeof(rand_val), 1, f);
		rand_val_array[i] = rand_val;
	}

	print_arr(rand_val_array, atoi(argv[1]));

	fclose(f);


	return 0;
}
