#include <stdio.h>

int is_digit(char *s)
{
        if ( *s <= '9' && *s >= '0' )
                return 1;
        else
                return 0;
}

int char_to_integer(char s[])
{
	int i, n, sign = 0;

	/* Check the char is white space or not from left to right.
	 * If the character is a white space skip to the next char until
	 * the character is not a white space.
         */
	for (i = 0; 32 == s[i]; i++){
		;
	}

        /* Check the sign of nuumber of string. */
        if ( '-' == s[i] ){
                sign = 1;
                i++;
        }
        else if ( '+' == s[i] ){
                i++;
        }

        /* Convert. */
	for (n = 0; is_digit(&s[i]); i++){
		n = n * 10 + (s[i]-'0');
	}

        /* Sign. */
        if (sign == 1)
                n = ~n + 1;

	return n;
}

int main()
{
        char pi_1[] = "-100";
        char pi_2[] = "1234";
        char pi_3[] = "+888";
        char pi_4[] = "  -100";
        char pi_5[] = "  1234";
        char pi_6[] = "  +888";
        char pi_7[] = " 8813asd";

        printf("char_to_integer(-100): %d\n", char_to_integer(pi_1));
        printf("char_to_integer(123): %d\n", char_to_integer(pi_2));
        printf("char_to_integer(+888): %d\n", char_to_integer(pi_3));
        printf("char_to_integer(   -100): %d\n", char_to_integer(pi_4));
        printf("char_to_integer(   1234): %d\n", char_to_integer(pi_5));
        printf("char_to_integer(   +888): %d\n", char_to_integer(pi_6));
        printf("char_to_integer( 8813asd): %d\n", char_to_integer(pi_7));

        return 0;
}
