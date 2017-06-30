/* Random Matrix Generator, RMG.
 * Using rand() to generate a random integer number matrix.
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


/* A random number matrix generator with integer data type and in a specific range.
 *
 * @row: The row of matrix.
 * @col: The column of matrix.
 * @max: The max value of matrix.
 * @min: The min value of matrix.
 */
int ** rand_matrix_generator_int( int row, int col, int max, int min)
{
        int i, j;
        int range = max - min;

        int ** matrix = matrix = (int **) malloc( row * sizeof(int*) );

        srand( (unsigned) time(NULL) );

        /* Generate the matrix. */
        for ( i = 0; i < row; i++ ){

                matrix[i] = (int *) malloc( col * sizeof(int) );

                for ( j = 0; j < col; j++ ){
                        matrix[i][j] = (rand() % range) + min;
                }
        }

        return matrix;
}


/* print the matrix with specific lenght
 *
 * @arr: the target matrix
 * @row: The row of matrix.
 * @col: The column of matrix.
 */
void print_matrix(int ** matrix, int row, int col)
{
        int i, j;

        for ( i = 0; i < row; i++){

                for ( j = 0; j < col; j++ ){
                        printf("%d ", matrix[i][j] );
                }
                printf("\n");
        }
        printf("\n");
}

void free_matrix( int ** matrix, int row)
{
        int i;
        for (i = 0; i < row; i++)
                safe_free(matrix[i]);

        safe_free(matrix);
}

int main( int argc, char *argv[] )
{
        int matrix_row =  atoi(argv[1]);
        int matrix_col =  atoi(argv[2]);
        int matrix_max_value =  atoi(argv[3]);
        int matrix_min_value =  atoi(argv[4]);

        int ** matrix = rand_matrix_generator_int( matrix_row, matrix_col, matrix_max_value, matrix_min_value );

        print_matrix( matrix, matrix_row, matrix_col );

        free_matrix( matrix, matrix_row );

        return 0;
}
