/* The implementation of Knuth-Morris-Pratt string search.
 *
 * Given text string and pattern string in text[] and word[] respectively, these two routines will find
 * if the word[] string is somewhere in the text[] by using the linear Knuth-Morris-Pratt algorithm.
 *
 * USAGE: gcc -Wall -g KMP_string_search_01.c && ./a.out
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int kmp(char * text, int text_size, char * word, int word_size)
{
	int i;
	int k = -1;

	int * pi = failure(word, word_size);
	if (!pi)
		return -1;

	for (i = 0; i < word_size; i++)
		printf("pi[%d]: %d\n", i, pi[i]);

	for (i = 0; i < text_size; i++) {

		/* If the mismatch of character comparison happen, we check the k for ensuring whether we use the
		 * prefix array.
		 */
		while ( k > -1 && word[k+1] != text[i] )
			k = pi[k];

		/* Find the matched char, continue to the next one. */
		if (text[i] == word[k+1])
			k++;

		if (k == word_size - 1) {
			free(pi);
			return i-k;
		}
	}

	free(pi);
	return -1;
}

int main(int argc, const char *argv[])
{
	int i;
	int KMP_result;

	char text[] = "ABC ABCDAB ABCDABCDABDE ABCDABDBB ABCDABCDCCDDAAA";
	char word[] = "ABCDABCDCC";

	KMP_result = kmp(text, strlen(text), word, strlen(word));

	if ( KMP_result >= 0 ) {

		printf("\n ");
		for (i = 1; i <= 6; i++)
			printf("         %1d", i);

		printf("\n");
		for (i = 1; i <= 6; i++)
			printf("0....5....");

		printf("0");
		printf("\n%s\n", text);

		for (i = 0; i < KMP_result; i++)
			printf(" ");

		printf("%s", word);
		printf("\n\nPattern Found at location %d\n", KMP_result);

	}else{
		printf("\nPattern NOT found\n");
	}

	return 0;
}
