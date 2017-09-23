#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SQUARE_N 3


/* Sum of absolute differences. */
int sad(int ** matrix_1, int ** matrix_2, int n)
{
        int i, j;
        int sum = 0;
        for (i = 0; i < n; i++){
                for (j = 0; j < n; j++){
                        sum += abs( matrix_1[i][j] - matrix_2[i][j] );
                }
        }
        return sum;
}


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

int main()
{
        int sad_ret = 0;
        int ** m_1 = rand_matrix_generator_int(SQUARE_N, SQUARE_N, 10, 0);
        sleep(1);
        int ** m_2 = rand_matrix_generator_int(SQUARE_N, SQUARE_N, 10, 0);

        print_matrix( m_1, SQUARE_N, SQUARE_N );
        print_matrix( m_2, SQUARE_N, SQUARE_N );

        sad_ret = sad( m_1, m_2, SQUARE_N);

        printf("sad_ret: %d\n", sad_ret);

        return 0;
}
