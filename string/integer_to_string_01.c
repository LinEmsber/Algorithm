#include <stdio.h>
#include <stdlib.h>

#define XORSWAP(a, b)   ((&(a) == &(b)) ? (a) : ((a)^=(b),(b)^=(a),(a)^=(b)))

char * integer_to_string( int n )
{
	if ( 0 == n){
		char * str = (char *)malloc(sizeof(char) * 2);
		*(str) = '0';
		*(str + 1) = '\0';
		return str;
	}

	int i = 0, sign = 0;
        char * str = (char *)malloc(sizeof(char));
        char * start = str;
        char * end = str;

	/* Check the sign. */
	if ( n < 0 ){
		sign = 1;
		n = -n;
	}

	/* Convert the number into the string. */
	while (n){
		*(str + i) = n % 10 + '0';
		n = n / 10;
		i++;
		str = (char*) realloc(str, sizeof(char) * (i + 1));
	}

	// the sign of character str
	if (sign == 1){
		*(str + i) = '-';
		str = (char*) realloc(str, sizeof(char) * (i + 1));
		i++;
	}

	/* Find the last char for reversing string. */
        end = end + i - 1;

        /* Reverse string. */
        while (start < end){
                XORSWAP(*start, *end);
                start++;
                end--;
        }

	/* Add null byte. */
	*(end + i) = '\0';

	return str;
}

int main()
{
        int i_1 = -54321;
        int i_2 = 54321;
        int i_3 = 0;
        int i_4 = 8;
        int i_5 = -8;

        char * p_i_1 = integer_to_string(i_1);
        char * p_i_2 = integer_to_string(i_2);
        char * p_i_3 = integer_to_string(i_3);
        char * p_i_4 = integer_to_string(i_4);
        char * p_i_5 = integer_to_string(i_5);

        printf("integer_to_string(i_1): %s\n", p_i_1);
        printf("integer_to_string(i_2): %s\n", p_i_2);
        printf("integer_to_string(i_3): %s\n", p_i_3);
        printf("integer_to_string(i_4): %s\n", p_i_4);
        printf("integer_to_string(i_5): %s\n", p_i_5);

	free(p_i_1);
	free(p_i_2);
	free(p_i_3);
	free(p_i_4);
	free(p_i_5);

        return 0;
}
