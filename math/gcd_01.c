
#include <stdio.h>

int main()
{
	int n1, n2, n1_, n2_;

	printf("Enter two integers: ");
	scanf("%d %d",&n1,&n2);

	n1_ = ( n1 > 0) ? n1 : -n1;
	n2_ = ( n2 > 0) ? n2 : -n2;

	while(n1_ != n2_)
	{
		if(n1_ > n2_)
			n1_ -= n2_;
		else
			n2_ -= n1_;
	}

	printf("GCD(%d, %d): %d\n", n1, n2, n1_);

	return 0;
}
