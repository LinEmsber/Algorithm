
#include <stdio.h>

int gcd ( int a, int b )
{
	int tmp;
	while ( a != 0 ) {
		tmp = a;
		a = b % a;
		b = tmp;
	}

	return b;
}

int main()
{
	int n1, n2;

	printf("Enter two integers: ");
	scanf("%d %d", &n1, &n2);

	printf("GCD(%d, %d): %d\n", n1, n2, gcd(n1, n2));

	return 0;
}
