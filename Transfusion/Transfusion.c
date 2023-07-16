#include <stdio.h>
#include <stdlib.h>
#include "transfusion.h"

#define MAX_NUM_OF_TRAN 20

transf tran;

int steps = 1;


//------------------------------------------ÓÑËÎÂÈß ÇÀÂÅĞØÅÍÈß ÏĞÎÃĞÀÌÌÛ----------------------------------------------------------
char isStop(int base, int big, int small, int inc, const int disVal)
{
	if (base == disVal)
	{
		return '0';
	}
	else if (big == disVal)
	{
		return '0';
	}
	else if (small == disVal)
	{
		return '0';
	}
	else if (steps == MAX_NUM_OF_TRAN)
	{
		printf("\n\tÊ ñîæàëåíèş ÿ íå ìîãó ğåøèòü ıòî\n");
		exit(0);
	}

	return '1';
}

//---------------------------------------ÂÛÂÎÄ ÀËÃÎĞÈÒÌÀ ÏÅĞÅÄÈÂÀÍÈÉ ÍÀ İÊĞÀÍ-----------------------------------------------------

void print_result(char oper)
{
	printf("%d) ", steps++);
	switch (oper)
	{
	case '1':
		printf("from BASE to BIG\t");
		break;
	case '2':
		printf("from BASE to SMALL\t");
		break;
	case '3':
		printf("from BIG to BASE\t");
		break;
	case '4':
		printf("from BIG to SMALL\t");
		break;
	case '5':
		printf("from SMALL to BASE\t");
		break;
	case '6':
		printf("from SMALL to BIG\t");
		break;
	default:
		printf("ERROR: %d\t", oper);
		break;		
	}
}

//------------------------------------------------FROM BASE TO BIG(1)-------------------------------------------------------------
void base_to_big(const int baseVal, const int bigVal, int *base, int* big, int inc)
{
	if ((*base + *big - bigVal) <= bigVal && (*base + *big - bigVal) >= (0 - bigVal) && *base != 0 && *big != bigVal)
	{
		int tmp = (*base + *big) - bigVal;
		if (tmp > 0)
		{
			*base = tmp;
			*big = bigVal;
		}
		else
		{
			tran.trans[inc] = '1';
			*big = *big + *base;
			*base = 0;
		}
	}
}

//----------------------------------------------FROM BASE TO SMALL(2)-------------------------------------------------------------
void base_to_small(const int baseVal, const int smallVal, int *base, int *small, const int disVal, int inc)
{
	if ((*base + *small - smallVal) >= (0 - smallVal) && *base != 0 && *small != smallVal)
	{
		int tmp = (*base + *small) - smallVal;
		if (tmp > smallVal)
		{
			*base = tmp;
			*small = smallVal;
		}
		else if (tmp > 0)
		{
			tran.trans[inc] = '2';
			*base = tmp;
			*small = smallVal;
		}
		else
		{
			tran.trans[inc] = '2';
			*small = *small + *base;
			*base = 0;
		}
	}
}

//-----------------------------------------------FROM BIG TO BASE(3)---------------------------------------------------------------
void big_to_base(const int baseVal, const int bigVal, int *base, int *big, int inc)
{
		if ((*big + *base - baseVal) <= baseVal && (*big + *base - baseVal) >= (0 - baseVal) && *big != 0 && *base != baseVal)
		{
			int tmp = (*big + *base - baseVal);
			if (tmp > 0)
			{
				tran.trans[inc] = '3';
				*base = baseVal;
				*big = tmp;
			}
			else
			{
				tran.trans[inc] = '3';
				*base = *base + *big;
				*big = 0;
			}

		}
}

//-----------------------------------------------FROM BIG TO SMALL(4)--------------------------------------------------------------
void big_to_small(const int bigVal, const int smallVal, int *big, int *small, const int disVal, int inc)
{
	if ((*big + *small - smallVal) >= (0 - smallVal) && *big != 0)
	{
			int tmp = (*big + *small - smallVal);
			if (tmp > smallVal)
			{
				tran.trans[inc] = '4';
				*big = tmp;
				*small = smallVal;

			}
			else if (tmp > 0)
			{
				tran.trans[inc] = '4';
				*big = tmp;
				*small = smallVal;		
			}
			else
			{
				tran.trans[inc] = '4';
				*small = *small + *big;
				*big = 0;			
			}
			
	}
}

//----------------------------------------------FROM SMALL TO BASE(5)--------------------------------------------------------------
void small_to_base(const int baseVal, const int smallVal, int *base, int *small, const int disVal, int inc)
{

	if ((*small + *base - baseVal) <= baseVal && (*small + *base - baseVal) >= (0 - baseVal) && *small != 0 && *base != baseVal)
	{
		int tmp = (*small + *base - baseVal);
		if (tmp > 0)
		{
			tran.trans[inc] = '5';
			*base = baseVal;
			*small = tmp;
		}
		else
		{
			tran.trans[inc] = '5';
			*base = *base + *small;
			*small = 0;
		}

	}
}

//-----------------------------------------------FROM SMALL TO BIG(6)---------------------------------------------------------------

void small_to_big(const int bigVal, const int smallVal, int* big, int* small, const int disVal, int inc)
{
	if ((*small + *big - bigVal) <= bigVal && (*small + *big - bigVal) >= (0 - bigVal) && *small != 0 && *big != bigVal)
	{
		int tmp = (*small + *big - bigVal);
		if (tmp > 0)
		{
			tran.trans[inc] = '6';
			*big = bigVal;
			*small = tmp;
		}
		else
		{
			tran.trans[inc] = '6';
			*big = *big + *small;
			*small = 0;
		}
	}
}

//------------------------------------------ĞÅØÅÍÈÅ ÏÅĞÂÛÌ ÑÏÎÑÎÁÎÌ (×ÅĞÅÇ ÁÎËÜØÎÉ)------------------------------------------------

void first_way(const int baseVal, const int bigVal, const int smallVal, const int disVal, int base, int big, int small, int* incr)
{
	int inc = *incr;

	while (isStop(base, big, small, inc, disVal) == '1')
	{
		
		if (small == smallVal)
		{
			print_result('5');
			small_to_base(baseVal, smallVal, &base, &small, disVal, inc);
			printf("base: %d, big: %d, small: %d\n", base, big, small);
		}
		else
		{
			print_result('1');
			base_to_big(baseVal, bigVal, &base, &big, inc);
			printf("base: %d, big: %d, small: %d\n", base, big, small);
		}
		if (isStop(base, big, small, inc, disVal) == '1')
		{
			if (big == 0)
			{
				print_result('1');
				base_to_big(baseVal, bigVal, &base, &big, inc);
				printf("base: %d, big: %d, small: %d\n", base, big, small);
			}
			else
			{
				print_result('4');
				big_to_small(bigVal, smallVal, &big, &small, disVal, inc);
				printf("base: %d, big: %d, small: %d\n", base, big, small);
			}
		}
	}
}


//----------------------------------------ĞÅØÅÍÈÅ ÂÒÎĞÎÛÌ ÑÏÎÑÎÁÎÌ(×ÅĞÅÇ ÌÀËÅÍÜÊÈÉ)------------------------------------------------
void second_way(const int baseVal, const int bigVal, const int smallVal, const int disVal, int base, int big, int small, int* incr)
{
	int inc = *incr;
	while (isStop(base, big, small, inc, disVal) == '1')
	{		
		if (small == 0 )
		{
			print_result('2');
			base_to_small(baseVal, smallVal, &base, &small, disVal, inc++);
			printf("base: %d, big: %d, small: %d\n", base, big, small);
		}
		else if (big != bigVal)
		{
			print_result('6');
			small_to_big(bigVal, smallVal, &big, &small, disVal, inc++);
			printf("base: %d, big: %d, small: %d\n", base, big, small);
		}
		if (isStop(base, big, small, inc, disVal) == '1')
		{
			if (big == bigVal)
			{
				print_result('3');
				big_to_base(baseVal, bigVal, &base, &big, inc++);
				printf("base: %d, big: %d, small: %d\n", base, big, small);
			}
			else if (small != 0)
			{
				print_result('6');
				small_to_big(bigVal, smallVal, &big, &small, disVal, inc++);
				printf("base: %d, big: %d, small: %d\n", base, big, small);
			}
		}		
	}
}

void trans(const int baseVal, const int bigVal, const int smallVal, const int disVal)
{
	int who = 0;
	int base = baseVal, big = 0, small = 0;
	static int inc = 0;
	printf("\nÏÅĞÂÛÉ ÑÏÎÑÎÁ:\n\n");
	first_way(baseVal, bigVal, smallVal, disVal, base, big, small, &inc);
	who = steps;
	steps = 1;
	printf("\nÂÒÎĞÎÉ ÑÏÎÑÎÁ:\n\n");
	second_way(baseVal, bigVal, smallVal, disVal, base, big, small, &inc);
	printf("\n");
	if (who > steps)
	{
		printf("Âòîğîé ñïîñîá áîëåå îïòèìàëüíûé\n");
	}
	else if (who < steps)
	{
		printf("Ïåğâûé ñïîñîá áîëåå îïòèìàëüíûé\n");
	}
	else
	{
		printf("Îáà ñïîñîáà îïòèìàëüíû\n");
	}
}
