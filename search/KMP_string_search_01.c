/* The implementation of Knuth-Morris-Pratt string search.
 *
 * Given text string and pattern string in text[] and word[] respectively, these two routines will find
 * if the word[] string is somewhere in the text[] by using the linear Knuth-Morris-Pratt algorithm.
 *
 * USAGE: gcc -Wall -g KMP.c && ./a.out
 */

#include <stdio.h>
#include <string.h>

#define MAX_SIZE  100


// Given the pattern word[], setup builds up the failure function table fail[].
void setup(char word[], int fail[])
{
	int i, j;
	int word_length = strlen(word);

	fail[0] = -1;

	for (i = 1; i < word_length; i++) {
		for ( j = fail[i-1]; j >= 0 && word[j+1] != word[i]; j = fail[j])
			;
		fail[i] = (j < 0 && word[j+1] != word[i]) ? -1 : j+1;
	}
}

// The KMP pattern search routine.
int KMP(char text[], char word[], int fail[])
{
	int t, w;
	int text_length = strlen(text);
	int word_length = strlen(word);

	/* build up the fail func.  */
	setup(word, fail);

	t = w = 0;
	while ( t < text_length && w < word_length ){

		/* if not match*/
		if (text[t] != word[w]){

			/* is it the 1st location? */
			if (w > 0){
				/* no, shift right */
				w = fail[w-1] + 1;
			}else{
				/* or match next in text[] */
				t++;
			}

		}else{
			/* matched, advance both */
			t++, w++;
		}
	}

	return (w >= word_length) ? t - word_length : -1;
}


int main()
{
	int i;
	int KMP_result;

	char * text = "ABC ABCDAB ABCDABCDABDE ABCDABDBB ABCDCCABCDDDAAA";
	char * word = "ABCDCCABCD";

	int word_length = strlen(word);
	int fail[word_length];

	printf("Knuth-Morris-Pratt String Search:\n");

	KMP_result = KMP(text, word, fail);

	for (i = 0; i < word_length; i++)
		printf("fail[%d]: %d\n", i, fail[i]);

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
