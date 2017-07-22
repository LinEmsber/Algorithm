/* The algorithm of conversion binary numbers into binary-coded decimal (BCD).
 *
 * References:
 * https://stackoverflow.com/questions/13247647/convert-integer-from-pure-binary-to-bcd
 */:

#include <stdio.h>

int main(void)
{
	int input = 123;
	int bcd_result = 0;
	int shift = 0;

	printf("Input: %d (hex: 0x%x)\n", input , input );

	while (input > 0) {
		bcd_result |= (input % 10) << (shift << 2);
                shift++;
		input /= 10;
	}
	printf("Input: %d (hex: 0x%x)\n", bcd_result , bcd_result );

	return 0;
}
