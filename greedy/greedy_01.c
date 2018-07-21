/* The greedy algorithm practice.
 * Counts the minimum number of coins needed for change.
 */

#include <stdio.h>
#include <math.h>

int main(void)
{

	float change_float = 10.73;	// The total amount of change.
	int dollar = 100, quarter = 25, dime = 10, nickel = 5, penny = 1;
	int change, coins = 0;

	/* Convert change_float to integer. */
	change = (int)(change_float * 100);

        while (change >= dollar) {
                coins = (coins + 1);
                change = (change - dollar);
        }
        printf("Number of coins used after using dollar: %d\n", coins);
	printf("Amount of change left after using dollar: %f\n\n", (float)change/100);

	while (change >= quarter) {
		coins = (coins + 1);
		change = (change - quarter);
	}
	printf("Number of coins used after using quarters: %d\n", coins);
	printf("Amount of change left after using quarters: %f\n\n", (float)change/100);

	while (change >= dime) {
		coins = (coins + 1);
		change = (change - dime);
	}
	printf("Number of coins used after using dimes: %d\n", coins);
	printf("Amount of change left after using dimes: %f\n\n", (float)change/100);

	while (change >= nickel) {
		coins = (coins + 1);
		change = (change - nickel);
	}
	printf("Number of coins used after using nickels: %d\n", coins);
	printf("Amount of change left after using nickels: %f\n\n", (float)change/100);

	while (change >= penny) {
		coins = (coins + 1);
		change = (change - penny);
	}

	// min number of coins used
	printf("The total number of coins: %d\n", coins);

	return 0;
}
