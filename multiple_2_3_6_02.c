#include <stdio.h>
#include <stdlib.h>


void foo(int x)
{
	int token = 0;
	if ( !(x%2) )
		token = 2;
	if ( !(x%3) )
		token = 3;
	if ( !(x%6) )
		token = 6;

	switch ( token ){
		case 2:
			printf("2\n");
			break;
		case 3:
			printf("3\n");
			break;
		case 6:
			printf("6\n");
			break;
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
