#include <stdio.h>


int gcd(int n1, int n2)
{
	n1 = ( n1 > 0) ? n1 : -n1;
	n2 = ( n2 > 0) ? n2 : -n2;

	while(n1 != n2)
	{
		if(n1 > n2)
			n1 -= n2;
		else
			n2 -= n1;
	}

	return n1;
}

int main()
{
	int n1, n2;

	printf("Enter two integers: ");
	scanf("%d %d", &n1, &n2);

	printf("GCD(%d, %d): %d\n", n1, n2, gcd(n1, n2));

	return 0;
}
