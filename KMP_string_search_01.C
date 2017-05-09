/* The implementation of Knuth-Morris-Pratt string search.
 *
 * Given text string and pattern string in text[] and word[] respectively, these two routines will find
 * if the word[] string is somewhere in the text[] by using the linear Knuth-Morris-Pratt algorithm.
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX_SIZE  100


// Given the pattern word[], setup builds up the failure function table fail[].
void setup(char word[], int fail[])
{
	int  length = strlen(word);
	int  i, j;

	fail[0] = -1;
	for (i = 1; i < length; i++) {
		for (j=fail[i-1]; j>=0 && word[j+1]!=word[i]; j=fail[j])
			;
		fail[i] = (j < 0 && word[j+1] != word[i]) ? -1 : j+1;
	}
}

// The KMP pattern search routine.
int KMP(char text[], char word[], int fail[])
{
	int t, p;
	int text_length = strlen(text);
	int word_length = strlen(word);

	/* build up the fail func.  */
	setup(word, fail);

	for (t = p = 0; t < text_length && p < word_length; ){

		/* if not match ...      */
		if (text[t] != word[p]){

			/* is it the 1st location?  */
			if (p > 0){
				/* no, shift right */
				p = fail[p-1] + 1;
			}else{
				/* or match next in text[]  */
				t++;
			}

		}else{
			/* matched, advance both    */
			t++, p++;
		}
	}

	return (p >= word_length) ? t - word_length : -1;
}


int main()
{
	int i;
	int answer;
	char text[MAX_SIZE];
	char word[MAX_SIZE];
	int fail[MAX_SIZE];

	strcpy(text, "ABC ABCDAB ABCDABCDABDE");
	strcpy(word, "ABCDABD");

	printf("\nKnuth-Morris-Pratt String Search:");

	//printf("\n\nText String ------> ");
	//fgets(text, sizeof(text), stdin);
	//gets(text);

	//printf("\nPattern String ---> ");
	//fgets(word, sizeof(word), stdin);
	//gets(word);

	answer = KMP(text, word, fail);
	if ( answer >= 0 ) {

		printf("\n ");
		for (i = 1; i <= 6; i++)
			printf("         %1d", i);

		printf("\n");
		for (i = 1; i <= 6; i++)
			printf("0....5....");

		printf("0");
		printf("\n%s\n", text);

		for (i = 0; i < answer; i++)
			printf(" ");

		printf("%s", word);
		printf("\n\nPattern Found at location %d\n", answer);

	}else{
		printf("\nPattern NOT found\n");
	}

	return 0;
}
