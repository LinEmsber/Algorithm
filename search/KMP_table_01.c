/* The failure function to build the KMP talbe for KMP algorithm.
 *
 * GDB: gcc -Wall -g KMP_table_01.c && gdbtui ./a.out
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

int main()
{
	int i;
	int * fail;
	char * word = "ABCABCABOOBCDCC";

	int word_length = strlen(word);

	fail = failure(word, word_length);
	printf("word: %s\n", word);

	printf("fail:");
	for (i = 0; i < word_length; i++)
		printf(" %d,", fail[i]);
	printf("\n");

	return 0;
}
