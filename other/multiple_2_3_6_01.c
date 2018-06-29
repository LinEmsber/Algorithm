#include <stdio.h>
#include <stdlib.h>


void foo(int x)
{
	int is_2 = (x%2) ? 0 : 1;
	int is_3 = (x%3) ? 0 : 1;
	int is_6 = is_2 & is_3;

	if ( is_6 ){
		printf("6x\n");
		return ;
	}

	if ( is_2 ){
		printf("2x\n");
	}
	else if ( is_3 ){

		printf("3x\n");
	}
}

int main()
{
	foo(2);
	foo(3);
	foo(4);
	foo(6);
	foo(8);
	foo(12);

	return 0;
}
