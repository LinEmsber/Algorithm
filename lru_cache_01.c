/* The simple implementation of Least Recently Used (LRU) cache.
 *
 * http://meansofmine.blogspot.tw/2011/04/c-program-to-implement-lru-page.html
 */

#include<stdio.h>

int main()
{
	int pages_cache[20], pages_input[50];
	int num_pages_fault = 0, page_cache_index = 0;
	int page_cache_search_index, cache_block_size, i, j, num_pages_input, r, t;
	int b[20], c2[20];


	printf("Enter number of pages:");
	scanf("%d", &num_pages_input);

	printf("Enter the integer array as sequence pages input:");
	for(i = 0; i < num_pages_input; i++)
		scanf("%d", &pages_input[i]);

	printf("Enter number of cache block:");
	scanf("%d", &cache_block_size);

	pages_cache[page_cache_index] = pages_input[page_cache_index];
	printf("\n\t%d\n", pages_cache[page_cache_index]);
	num_pages_fault++;
	page_cache_index++;

	for(i = 1; i < num_pages_input; i++) {
		page_cache_search_index = 0;

		/* Search the pages from the cache. */
		for(j = 0; j < cache_block_size; j++) {
			if(pages_input[i] != pages_cache[j]){
				page_cache_search_index++;
			}
		}

		/* If we cannot find the target page on the cache. */
		if(page_cache_search_index == cache_block_size) {
			num_pages_fault++;

			/* If the cache is not full, we store this page into the cache. */
			if(page_cache_index < cache_block_size) {
				pages_cache[page_cache_index] = pages_input[i];
				page_cache_index++;
				for(j = 0; j < page_cache_index; j++)
					printf("\t%d", pages_cache[j]);
				printf("\n");
			}

			/* If the cache is full. */
			else {
				/* Search the target page from the cache. */
				for(r = 0; r < cache_block_size; r++) {
					c2[r] = 0;

					for(j = i-1; j < num_pages_input; j--) {
						if(pages_cache[r] != pages_input[j])
							c2[r]++;
						else
							break;
					}
				}

				/* Copy the cache to tmp array. */
				for(r = 0; r < cache_block_size; r++){
					b[r] = c2[r];
				}

				/* Find the victim to remove it from the cache. */
				for(r = 0; r < cache_block_size; r++) {
					for(j = r; j < cache_block_size; j++) 	{
						if(b[r] < b[j]) {
							t = b[r];
							b[r] = b[j];
							b[j] = t;
						}
					}
				}

				for(r = 0; r < cache_block_size;r++)  {
					if(c2[r] == b[0]){
						pages_cache[r] = pages_input[i];
					}

					printf("\t%d", pages_cache[r]);
				}
				printf("\n");
			}
		}

		/* Page hit. */
		else{
			printf("Page hit.\n");
		}
	}

	printf("\nThe number of page faults is %d\num_pages_input", num_pages_fault);

	return 0;
}
