/* Random Number Generator, RNG
 * Using /dev/urandom to generate a random number with data type uint8_t.
 *
 * The maximun length of number array is 255.
 *
 * Reference:
 * http://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Randomization.html
 * https://sockpuppet.org/blog/2014/02/25/safely-generate-random-numbers/
 * http://insanecoding.blogspot.tw/2014/05/a-good-idea-with-bad-usage-devurandom.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* random number generator, RNG.
 * generate 8 bits unsigned integer, range from 0 to 255.
 * This function allocate memory from heap, it is necessary to free it.
 */
uint8_t * rand_num_generator_uint8(uint8_t len, uint8_t max, uint8_t min)
{
        int i;
        FILE * f;

        uint8_t rand_val;
        uint8_t * rand_val_array;
        uint8_t range = max - min;

        rand_val_array = malloc( len * sizeof(uint8_t) );

        f = fopen("/dev/urandom", "r");

        for (i = 0; i < len; i++){
                fread(&rand_val, sizeof(rand_val), 1, f);
                rand_val_array[i] = (rand_val % range) + min;
        }

        fclose(f);

        return rand_val_array;
}

void print_arr(uint8_t *arr, int len)
{
        int i;

        for ( i = 0; i < len; i++)
                printf("%d ", *(arr + i) );

        printf("\n");
}

int  main(int argc, char *argv[])
{
        int n = atoi( argv[1] );
        uint8_t * array;

        array = rand_num_generator_uint8(n, 255, 128);

        print_arr(array, n);

        free(array);

        return 0;
}
