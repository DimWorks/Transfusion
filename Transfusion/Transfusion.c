#include <stdio.h>
#include "transfusion.h"

//int max_of_tran;

#define MAX_NUM_OF_TRAN 20

transf tran;

int steps = 1;


//------------------------------------------������� ���������� ���������----------------------------------------------------------
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
		//tran.val = small;
		//tran.inc = inc;
		//tran.tara = 2;
		//printRes();
		//printf("\n%d\t%d\t%d|\t%d\t%d\t%d|\t%d\t|%d\t\n", baseVal, bigVal, smallVal, base, big, small, inc, disVal);
		return '0';
	}
	else if (inc == MAX_NUM_OF_TRAN)
	{
		return '0';
	}

	return '1';
}

//---------------------------------------����� ��������� ����������� �� �����-----------------------------------------------------

//void print_result(int inc)
//{
//	for (int i = 0; i < inc; i++)
//	{
//		printf("%d) ", i+1);
//		switch (tran.trans[i])
//		{
//		case '1':
//			printf("from BASE to BIG\n");
//			break;
//		case '2':
//			printf("from BASE to SMALL\n");
//			break;
//		case '3':
//			printf("from BIG to BASE\n");
//			break;
//		case '4':
//			printf("from BIG to SMALL\n");
//			break;
//		case '5':
//			printf("from SMALL to BASE\n");
//			break;
//		case '6':
//			printf("from SMALL to BIG\n");
//			break;
//		default:
//			//i++;
//			printf("ERROR: %d\n", tran.trans[i]);
//			break;
//		}
//	}
//}

//----------------------------------
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
	if ((*base + *big - bigVal) <= bigVal && (*base + *big - bigVal) >= (0 - bigVal) && *base != 0 && *big != bigVal)// && tran.trans[inc - 1] != '1')
	{
		int tmp = (*base + *big) - bigVal;
		if (tmp > 0)
		{
			tran.trans[inc] = '1';
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
	if (/*(*base + *small - smallVal) <= smallVal && */ (*base + *small - smallVal) >= (0 - smallVal) && *base != 0 && *small != smallVal)
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
			//transfusion(baseVal, bigVal, smallVal, tmp, big, smallVal, inc + 1, disVal);
		}
		else
		{
			tran.trans[inc] = '2';
			*small = *small + *base;
			*base = 0;
			//transfusion(baseVal, bigVal, smallVal, 0, big, small + base, inc + 1, disVal);
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
				//transfusion(baseVal, bigVal, smallVal, baseVal, tmp, small, inc + 1, disVal);
			}
			else
			{
				tran.trans[inc] = '3';
				*base = *base + *big;
				*big = 0;
				//transfusion(baseVal, bigVal, smallVal, base+big, 0, small, inc + 1, disVal);
			}

		}
}

//-----------------------------------------------FROM BIG TO SMALL(4)--------------------------------------------------------------
void big_to_small(const int bigVal, const int smallVal, int *big, int *small, const int disVal, int inc)
{
	if (/*(*big + *small - smallVal) <= smallVal &&*/ (*big + *small - smallVal) >= (0 - smallVal) && *big != 0)// && small != smallVal)
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
				//transfusion(baseVal, bigVal, smallVal, base, tmp, smallVal, inc + 1, disVal);				
			}
			else
			{
				tran.trans[inc] = '4';
				*small = *small + *big;
				*big = 0;
				//transfusion(baseVal, bigVal, smallVal, base, 0, small + big, inc + 1, disVal);				
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
			//transfusion(baseVal, bigVal, smallVal, baseVal, big, tmp, inc + 1, disVal);
		}
		else
		{
			tran.trans[inc] = '5';
			*base = *base + *small;
			*small = 0;
			//transfusion(baseVal, bigVal, smallVal, base + small, big, 0, inc + 1, disVal);
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
			//transfusion(baseVal, bigVal, smallVal, base, bigVal, tmp, inc + 1, disVal);
		}
		else
		{
			tran.trans[inc] = '6';
			*big = *big + *small;
			*small = 0;
			//transfusion(baseVal, bigVal, smallVal, base, big + small, 0, inc + 1, disVal);
		}
	}
}

//------------------------------------------������� ������ �������� (����� �������)------------------------------------------------

//void first_way(const int baseVal, const int bigVal, const int smallVal, const int disVal, int base, int big, int small, int *incr)
//{
//	int inc = *incr;
//	base_to_big(baseVal, bigVal, &base, &big, inc);
//
//	while (isStop(base, big, small, inc, disVal) == '1')
//	{
//		print_fuck(inc);
//		printf("base: %d, big: %d, small: %d\n", base, big, small);
//		if (small == smallVal)
//		{
//			small_to_base(baseVal, smallVal, &base, &small, disVal, inc++);
//		}
//		else
//		{
//			base_to_big(baseVal, bigVal, &base, &big, inc++);
//		}
//
//		if (big == 0)
//		{
//			base_to_big(baseVal, bigVal, &base, &big, inc++);
//		}
//		else
//		{
//			big_to_small(bigVal, smallVal, &big, &small, disVal, inc++);
//		}
//
//	}
//
//	printf("base: %d, big: %d, small: %d\n", base, big, small);
//	//print_result(inc);
//	*incr = inc;
//
//}

void first_way(const int baseVal, const int bigVal, const int smallVal, const int disVal, int base, int big, int small, int* incr)
{
	int inc = *incr;

	/*print_result('1');
	base_to_big(baseVal, bigVal, &base, &big, inc);
	printf("base: %d, big: %d, small: %d\n", base, big, small);*/

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


//----------------------------------------������� ������� ��������(����� ���������)------------------------------------------------

//void second_way(const int baseVal, const int bigVal, const int smallVal, const int disVal, int base, int big, int small, int* incr)
//{
//	int inc = *incr;
//	base_to_small(baseVal, smallVal, &base, &small, disVal, inc);
//	while (isStop(base, big, small, inc, disVal) == '1')
//	{
//		printf("base: %d, big: %d, small: %d\n", base, big, small);
//		if (big == bigVal)
//		{
//			big_to_base(baseVal, bigVal, &base, &big, inc++);
//		}
//		else
//		{
//			small_to_big(bigVal, smallVal, &big, &small, disVal, inc++);
//		}
//
//		if (small == 0)
//		{
//			base_to_small(baseVal, smallVal, &base, &small, disVal, inc++);
//		}
//		else
//		{
//			small_to_big(bigVal, smallVal, &big, &small, disVal, inc++);
//		}
//	}
//
//	printf("base: %d, big: %d, small: %d\n", base, big, small);
//	print_result(inc);
//	*incr = inc;
//
//}

void second_way(const int baseVal, const int bigVal, const int smallVal, const int disVal, int base, int big, int small, int* incr)
{
	int inc = *incr;
	while (isStop(base, big, small, inc, disVal) == '1')
	{		
		if (small == 0)
		{
			print_result('2');
			base_to_small(baseVal, smallVal, &base, &small, disVal, inc++);
			printf("base: %d, big: %d, small: %d\n", base, big, small);
		}
		else
		{
			print_result('6');
			small_to_big(bigVal, smallVal, &big, &small, disVal, inc++);
			printf("base: %d, big: %d, small: %d\n", base, big, small);
		}
		if (big == bigVal)
		{
			print_result('3');
			big_to_base(baseVal, bigVal, &base, &big, inc++);
			printf("base: %d, big: %d, small: %d\n", base, big, small);
		}
		else
		{
			print_result('6');
			small_to_big(bigVal, smallVal, &big, &small, disVal, inc++);
			printf("base: %d, big: %d, small: %d\n", base, big, small);
		}		
	}
}

void trans(const int baseVal, const int bigVal, const int smallVal, const int disVal)
{
	int who = 0;
	int base = baseVal, big = 0, small = 0;
	static int inc = 0;
	printf("\t\nFIRST WAY\n");
	first_way(baseVal, bigVal, smallVal, disVal, base, big, small, &inc);
	who = steps;
	steps = 1;
	printf("\t\nSECOND WAY\n");
	second_way(baseVal, bigVal, smallVal, disVal, base, big, small, &inc);
	printf("\n");
	if (who > steps)
	{
		printf("������ ������ ����� �����������\n");
	}
	else if (who < steps)
	{
		printf("������ ������ ����� �����������\n");
	}
	else
	{
		printf("��� ������� ����������\n");
	}
}
