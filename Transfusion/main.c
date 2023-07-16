#include <stdio.h>
#include <locale.h>
#include "transfusion.h"

//----------------------------------------������������ ��ڨ�� �������-----------------------------------------
void arrangement(const int first, const int second, const int third, int* base, int* big, int* small)
{
	if (first > second)
	{
		if (first > third)
		{
			*base = first;
			if (second > third)
			{
				*big = second;
				*small = third;
			}
			else
			{
				*big = third;
				*small = second;
			}
		}
		else
		{
			*base = third;
			*big = first;
			*small = second;
		}

	}
	else
	{
		if (second > third)
		{
			*base = second;
			if (first > third)
			{
				*big = first;
				*small = third;
			}
			else
			{
				*big = third;
				*small = first;
			}
		}
		else
		{
			*base = third;
			*big = second;
			*small = first;
		}
	}
}

//----------------------------------------------------------������ ��ڨ�� �������----------------------------------------------------

void get_vessel_volumes(int *first, int *second, int *third)
{
	do {
		printf("������� ������� �� ������ ���� �������!\n\n������� ����� ������� ������: ");
		scanf_s("%d", first);
		printf("������� ����� ������� ������: ");
		scanf_s("%d", second);
		printf("������� ����� �������� ������: ");
		scanf_s("%d", third);
	} while (first == second || second == third || first == third);
}

//-----------------------------------------------------������ ������� ���������� ������----------------------------------------------

void get_liters(const int *base, int* disVal)
{
	do
	{
		printf("������� ���������� ������ �� ����� ���� ������ ������ �������� ������!\n����� �������� ������: %d\n", *base);
		printf("������� ������� ���������� ������: ");
		scanf_s("%d", disVal);
	} while (*disVal > *base);
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int first = 0, second = 0, third = 0;

	get_vessel_volumes(&first, &second, &third);

	int base = 0, big = 0, small = 0;

	arrangement(first, second, third, &base, &big, &small);

	printf("base: %d, big: %d, small: %d\n", base, big, small);

	int disVal = 0;

	get_liters(&base, &disVal);

	if (base == disVal)
	{
		printf("\n������� ��������(%d) ��������� � ������� ������, ����� 0 �����������\n", base);
	}
	else
	{
		trans(base, big, small, disVal);	
	}
}