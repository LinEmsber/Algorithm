/* The failure function of KMP algorithm.
 *
 * GDB: gcc -Wall -g KMP_failure_01.c && gdbtui ./a.out
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* make Partial match table, also known as failure function */
int * failure(char * word, int word_size)
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

int * prefix_fun(char * word, int word_size)
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

	return word;
}

int main()
{
	int i;
	char * word = "ABCABCABOOBCDCC";

	int * fail_1, * fail_2;
	int word_length = strlen(word);

	fail_1 = failure(word, word_length);
	printf("word: %s\n", word);

	for (i = 0; i < word_length; i++)
		printf("fail_1[%d]: %d\n", i, fail_1[i]);


	fail_2 = failure(word, word_length);
	printf("word: %s\n", word);

	for (i = 0; i < word_length; i++)
		printf("fail_2[%d]: %d\n", i, fail_2[i]);


	return 0;
}

