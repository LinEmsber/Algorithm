/* The failure function of KMP algorithm. */

#include <stdio.h>
#include <string.h>

#define MAX_SIZE  100

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

		while (k > -1 && word[k+1] != word[i])
			k = pi[k];

		if (word[i] == word[k+1])
			k++;

		pi[i] = k;
	}

	return pi;
}

int main()
{
	int i;
	char * word = "ABACABABC";

	int word_length = strlen(word);
	int fail[word_length];

	failure(word, fail);
	printf("word: %s\n", word);

	for (i = 0; i < word_length; i++)
		printf("fail[%d]: %d\n", i, fail[i]);

	return 0;
}

