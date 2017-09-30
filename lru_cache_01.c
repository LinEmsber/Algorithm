/* The simple implementation of Least Recently Used (LRU) cache.
 *
 * http://meansofmine.blogspot.tw/2011/04/c-program-to-implement-lru-page.html
 */

#include <stdio.h>
#include <stdlib.h>

#define PAGE_CACHE_MAX_SIZE 5
#define PAGE_INPUT_MAX_SIZE 20

int main()
{
	int pages_cache[PAGE_CACHE_MAX_SIZE] = {0}, pages_cache_backup[PAGE_CACHE_MAX_SIZE] = {0}, pages_cache_2[PAGE_CACHE_MAX_SIZE] = {0};
	int pages_input_array[PAGE_INPUT_MAX_SIZE] = {0};

	int page_fault_times = 0, page_cache_index = 0;
	int page_cache_search_index, cache_size, num_pages_size;
	int i, j, r, t;

	printf("Enter number of pages (max: %d):", PAGE_INPUT_MAX_SIZE);
	scanf("%d", &num_pages_size);
	if (num_pages_size > PAGE_INPUT_MAX_SIZE)
		return EXIT_FAILURE;

	printf("Enter the integer array as sequence pages input:");
	for(i = 0; i < num_pages_size; i++)
		scanf("%d", &pages_input_array[i]);

	printf("Enter number of cache block (max: %d):", PAGE_CACHE_MAX_SIZE);
	scanf("%d", &cache_size);
	if (cache_size > PAGE_CACHE_MAX_SIZE)
		return EXIT_FAILURE;

	/* Print the first page in the cache. */
	pages_cache[0] = pages_input_array[0];
	/* Print the elements of cache. */
	for(j = 0; j < cache_size; j++)
		printf("\t%d", pages_cache[j]);
	printf("\n");
	page_fault_times++;
	page_cache_index++;

	/* Start the LRU cache algorithm. */
	for(i = 1; i < num_pages_size; i++) {
		page_cache_search_index = 0;

		/* Search the pages from the cache. */
		for(j = 0; j < cache_size; j++) {
			if(pages_input_array[i] != pages_cache[j]){
				page_cache_search_index++;
			}
		}

		/* If we cannot find the target page on the cache. */
		if(page_cache_search_index == cache_size) {
			page_fault_times++;

			/* If the cache is not full, we store this page into the cache. */
			if(page_cache_index < cache_size) {
				pages_cache[page_cache_index] = pages_input_array[i];
				page_cache_index++;

			}

			/* If the cache is full, we need to find a victim. */
			else {

				for(j = cache_size - 1; j > 0 ; j--){
					pages_cache[j] = pages_cache[j-1];
				}
				pages_cache[0] = pages_input_array[i];

			}

			/* Print the elements of cache. */
			for(j = 0; j < cache_size; j++)
				printf("\t%d", pages_cache[j]);
			printf("\n");
		}

		/* Page hit. */
		else{
			printf("Page hit.\n");
		}
	}

	printf("\nThe number of page faults is %d\n", page_fault_times);

	return 0;
}
