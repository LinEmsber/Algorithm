/* Random Number Generator, RNG
 * Using /dev/urandom to generate a random number with data type int.
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
 * This function allocate memory from heap, it is necessary to free it.
 */
int * rand_num_generator(int len, int max, int min)
{
        int i;
        FILE * f;
        unsigned int rand_val;
        int * rand_val_array;
        int range = max - min;

        rand_val_array = malloc( len * sizeof(int) );

        f = fopen("/dev/urandom", "r");

        for (i = 0; i < len; i++){
                fread(&rand_val, sizeof(rand_val), 1, f);
                rand_val_array[i] = (rand_val % range) + min;

                if (rand_val_array[i] < min){
                        printf("Error\n");
                }
        }

        fclose(f);

        return rand_val_array;
}

void print_arr(int *arr, int len)
{
        int i;

        for ( i = 0; i < len; i++)
                printf("%d ", *(arr + i) );

        printf("\n");
}

int  main(int argc, char *argv[])
{
        int n = atoi( argv[1] );
        int * array;

        array = rand_num_generator(n, 255, 128);

        print_arr(array, n);

        free(array);

        return 0;
}
