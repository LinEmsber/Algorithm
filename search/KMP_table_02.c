/* The failure function to build the KMP talbe for KMP algorithm.
 *
 * GDB: gcc -Wall -g KMP_table_02.c && gdbtui ./a.out
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * failure_function_1(char * word, int word_size)
{
	int i = 1;
	int k = -1;

	int * pi = malloc( sizeof(int) * word_size );
	if (!pi)
		return NULL;

	pi[0] = k;

	for (i = 1; i < word_size; i++) {

		/* If the k is not -1, but the word[i] is not equal the next char (word[k+1]).
		 * Thus, we reset the k as pi[k].
		 */
		while ( k > -1 && word[i] != word[k+1] )
			k = pi[k];

		if ( word[i] == word[k+1] )
			k++;

		pi[i] = k;
	}

	return pi;
}

int * failure_function_2(char * word, int word_size)
{
	int i;
	int k = 0;
	int * pi = malloc( sizeof(int) * word_size );
	if (!pi)
		return NULL;

	pi[0] = -1;
	for (i = 1; i < word_size; i++){

		while( k > 0 && word[i] != word[k] )
			k = pi[k-1];

		if (word[i] == word[k])
			k++;

		pi[i] = k;
	}

	return pi;
}

int main()
{
	int i;
	int * fail_1, * fail_2;
	char * word = "ABCABCABOOBCDCC";

	int word_length = strlen(word);

	printf("word: %s\n", word);

	/* method 1 */
	fail_1 = failure_function_1(word, word_length);
	printf("fail_1:");
	for (i = 0; i < word_length; i++)
		printf(" %d,", fail_1[i]);
	printf("\n");

	/* method 2 */
	fail_2 = failure_function_1(word, word_length);
	printf("fail_2:");
	for (i = 0; i < word_length; i++)
		printf(" %d,", fail_2[i]);
	printf("\n");


	return 0;
}
