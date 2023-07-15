#include <stdio.h>

void base_to_big(const int baseVal, const int bigVal, int* base, int* big)
{
	if ((base + big - bigVal) <= bigVal && (base + big - bigVal) >= (0 - bigVal) && base != 0 && big != bigVal)// && tran.trans[inc - 1] != '1')
	{
		int tmp = (base + big) - bigVal;
		if (tmp > 0)
		{
			tran.trans[inc] = '1';
			base = tmp;
			big = bigVal;
		}
		else
		{
			tran.trans[inc] = '1';
			base = 0;
			big = big + base;
		}
	}
}

bool isStop(int base, int big, int small, int inc, const int disVal)
[
	if (base == disVal)
	{
		tran.val = base;
		tran.inc = inc;
		tran.tara = 0;
		if (inc == 5)
		{

			printRes();
			printf("\n%d\t%d\t%d|\t%d\t%d\t%d|\t%d\t|%d\t\n", baseVal, bigVal, smallVal, base, big, small, inc, disVal);
			return inc;
		}
	}
	else if (big == disVal)
	{
		tran.val = big;
		tran.inc = inc;
		tran.tara = 1;
		printRes();
		printf("\n%d\t%d\t%d|\t%d\t%d\t%d|\t%d\t|%d\t\n", baseVal, bigVal, smallVal, base, big, small, inc, disVal);
	}
	else if (small == disVal)
	{
		tran.val = small;
		tran.inc = inc;
		tran.tara = 2;
		printRes();
		printf("\n%d\t%d\t%d|\t%d\t%d\t%d|\t%d\t|%d\t\n", baseVal, bigVal, smallVal, base, big, small, inc, disVal);
	}
]

void trans(const int baseVal, const int bigVal, const int smallVal, int base, int big, int small, const int disVal)
{
	int inc = 0;
	base_to_big(baseVal, bigVal, base, big);
	inc++;
	while (!isStop)
	{
		if(small == smallVal)
	}
}
