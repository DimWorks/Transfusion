#include <stdio.h>
#include <stdlib.h>
#include "transfusion.h"

#define MAX_NUM_OF_TRAN 20

int steps = 1;


//------------------------------------------������� ���������� ���������----------------------------------------------------------
char isStop(int base, int big, int small, const int disVal)
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
		printf("\n\t� ��������� � �� ���� ������ ���\n");
		exit(0);
	}

	return '1';
}

//---------------------------------------����� ��������� ����������� �� �����-----------------------------------------------------

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
void base_to_big(const int baseVal, const int bigVal, int* base, int* big)
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
			*big = *big + *base;
			*base = 0;
		}
	}
}

//----------------------------------------------FROM BASE TO SMALL(2)-------------------------------------------------------------
void base_to_small(const int baseVal, const int smallVal, int* base, int* small, const int disVal)
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
			*base = tmp;
			*small = smallVal;
		}
		else
		{
			*small = *small + *base;
			*base = 0;
		}
	}
}

//-----------------------------------------------FROM BIG TO BASE(3)---------------------------------------------------------------
void big_to_base(const int baseVal, const int bigVal, int* base, int* big)
{
	if ((*big + *base - baseVal) <= baseVal && (*big + *base - baseVal) >= (0 - baseVal) && *big != 0 && *base != baseVal)
	{
		int tmp = (*big + *base - baseVal);
		if (tmp > 0)
		{
			*base = baseVal;
			*big = tmp;
		}
		else
		{

			*base = *base + *big;
			*big = 0;
		}

	}
}

//-----------------------------------------------FROM BIG TO SMALL(4)--------------------------------------------------------------
void big_to_small(const int bigVal, const int smallVal, int* big, int* small, const int disVal)
{
	if ((*big + *small - smallVal) >= (0 - smallVal) && *big != 0)
	{
		int tmp = (*big + *small - smallVal);
		if (tmp > smallVal)
		{

			*big = tmp;
			*small = smallVal;

		}
		else if (tmp > 0)
		{
			*big = tmp;
			*small = smallVal;
		}
		else
		{

			*small = *small + *big;
			*big = 0;
		}

	}
}

//----------------------------------------------FROM SMALL TO BASE(5)--------------------------------------------------------------
void small_to_base(const int baseVal, const int smallVal, int* base, int* small, const int disVal)
{

	if ((*small + *base - baseVal) <= baseVal && (*small + *base - baseVal) >= (0 - baseVal) && *small != 0 && *base != baseVal)
	{
		int tmp = (*small + *base - baseVal);
		if (tmp > 0)
		{
			*base = baseVal;
			*small = tmp;
		}
		else
		{
			*base = *base + *small;
			*small = 0;
		}

	}
}

//-----------------------------------------------FROM SMALL TO BIG(6)---------------------------------------------------------------

void small_to_big(const int bigVal, const int smallVal, int* big, int* small, const int disVal)
{
	if ((*small + *big - bigVal) <= bigVal && (*small + *big - bigVal) >= (0 - bigVal) && *small != 0 && *big != bigVal)
	{
		int tmp = (*small + *big - bigVal);
		if (tmp > 0)
		{
			*big = bigVal;
			*small = tmp;
		}
		else
		{
			*big = *big + *small;
			*small = 0;
		}
	}
}

//------------------------------------------������� ������ �������� (����� �������)------------------------------------------------

void first_way(const int baseVal, const int bigVal, const int smallVal, const int disVal, int base, int big, int small)
{


	while (isStop(base, big, small, disVal) == '1')
	{

		if (small == smallVal)
		{
			print_result('5');
			small_to_base(baseVal, smallVal, &base, &small, disVal);
			printf("base: %d, big: %d, small: %d\n", base, big, small);
		}
		else
		{
			print_result('1');
			base_to_big(baseVal, bigVal, &base, &big);
			printf("base: %d, big: %d, small: %d\n", base, big, small);
		}
		if (isStop(base, big, small, disVal) == '1')
		{
			if (big == 0)
			{
				print_result('1');
				base_to_big(baseVal, bigVal, &base, &big);
				printf("base: %d, big: %d, small: %d\n", base, big, small);
			}
			else
			{
				print_result('4');
				big_to_small(bigVal, smallVal, &big, &small, disVal);
				printf("base: %d, big: %d, small: %d\n", base, big, small);
			}
		}
	}
}


//----------------------------------------������� ������� ��������(����� ���������)------------------------------------------------
void second_way(const int baseVal, const int bigVal, const int smallVal, const int disVal, int base, int big, int small)
{

	while (isStop(base, big, small, disVal) == '1')
	{
		if (small == 0)
		{
			print_result('2');
			base_to_small(baseVal, smallVal, &base, &small, disVal);
			printf("base: %d, big: %d, small: %d\n", base, big, small);
		}
		else if (big != bigVal)
		{
			print_result('6');
			small_to_big(bigVal, smallVal, &big, &small, disVal);
			printf("base: %d, big: %d, small: %d\n", base, big, small);
		}
		if (isStop(base, big, small, disVal) == '1')
		{
			if (big == bigVal)
			{
				print_result('3');
				big_to_base(baseVal, bigVal, &base, &big);
				printf("base: %d, big: %d, small: %d\n", base, big, small);
			}
			else if (small != 0)
			{
				print_result('6');
				small_to_big(bigVal, smallVal, &big, &small, disVal);
				printf("base: %d, big: %d, small: %d\n", base, big, small);
			}
		}
	}
}

void trans(const int baseVal, const int bigVal, const int smallVal, const int disVal)
{
	int who = 0;
	int base = baseVal, big = 0, small = 0;
	printf("\n������ ������:\n\n");
	first_way(baseVal, bigVal, smallVal, disVal, base, big, small);
	who = steps;
	steps = 1;
	printf("\n������ ������:\n\n");
	second_way(baseVal, bigVal, smallVal, disVal, base, big, small);
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
