/* Random Number Generator, RNG.
 * Using rand() to generate a random integer number array
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/* A safe free function.  */
void _safe_free(void **pp)
{
        if (pp != NULL && *pp != NULL){
                free(*pp);
                *pp = NULL;
        }
}
#define safe_free(p) _safe_free( (void**) &p )


/* A random number generator with integer data tyep and in a specific range.
 *
 * @len: The length of array.
 * @max: The max value of array.
 * @min: The min value of array.
 */
int * rand_num_generator_int( int len , int max, int min)
{
        int i;
        int * ret_arr = NULL;
        int range = max - min;

        // memroy allocation
        ret_arr = (int *) malloc( len * sizeof(int) );
        memset(ret_arr, 0, len + 1);

        // rand seed use time
        srand( (unsigned) time(NULL) );

        // generate arr
        for ( i = 0; i < len; i++ )
                *(ret_arr + i) = (rand() % range) + min;

        return ret_arr;
}


/* print the array with specific lenght
 *
 * @arr: the target array
 * @len: the length of array
 */
void print_arr(int *arr, int len)
{
        int i;

        for ( i = 0; i < len; i++)
                printf("%d ", *(arr + i) );

        printf("\n");
}

int main( int argc, char *argv[] )
{
        int n =  atoi(argv[1]);

        int * arr = rand_num_generator_int( n, 128, 255 );

        print_arr( arr, n );

        safe_free(arr);

        return 0;
}
