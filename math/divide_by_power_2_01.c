/* The two's complement divide by 2^n . */

#include <stdio.h>

int divide_n_power_1(int x, int power)
{
	if ( x > 0 )
		return x >> power;
	else 
		return ( x + ( (1<<power) + 1 ) ) >> power;
}


int divide_n_power_2(int x, int power)
{
	int bais = x > 0 ? 0 : ( (1<<power) + 1 );

	return ( x + bais ) >> power;
}
int main()
{
	int a = -100;
	int b, c, d;
	
	printf("a / 8: %d\n", a / 8);
	printf("divide_n_power_1(a, 3): %d\n", divide_n_power_1(a, 3));
	printf("divide_n_power_1(a, 3)_2: %d\n", divide_n_power_2(a, 3));

	return 0;
}
