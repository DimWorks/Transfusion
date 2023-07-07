#include <stdio.h>
#include <locale.h>

#define MAX_NUM_OF_TRAN 10

struct tran
{
	int val;
	int inc;
	int tara;
	char trans[MAX_NUM_OF_TRAN];
} tran;

void printRes()
{
	if (tran.tara == 0)
	{
		printf("\n������� ��������(%d) ��������� � ������� ������, ����� %d �����������\n�������� �����������: ", tran.val, tran.inc);
		for (int i = 0; i < tran.inc; i++)
		{
			printf("%c ", tran.trans[i]);
		}
	}
	else if (tran.tara == 1)
	{
		printf("\n������� ��������(%d) ��������� � ������� ������, ����� %d �����������\n", tran.val, tran.inc);
		for (int i = 0; i < tran.inc; i++)
		{
			printf("%c ", tran.trans[i]);
		}
	}
	else if (tran.tara == 2)
	{
		printf("\n������� ��������(%d) ��������� � ��������� ������, ����� %d �����������\n", tran.val, tran.inc);
		for (int i = 0; i < tran.inc; i++)
		{
			printf("%c ", tran.trans[i]);
		}
		printf("\n");
	}
}

int transfusion(const int baseVal, const int bigVal, const int smallVal, const int base, const int big, const int small, int inc, const int disVal)
{
	if (base == disVal) 
	{ 
		tran.val = base; 
		tran.inc = inc;
		tran.tara = 0;
		if (inc == 5)
		{

			printRes();
			printf("\nAAA %d\t%d\t%d|\t%d\t%d\t%d|\t%d\t|%d\t\n", baseVal, bigVal, smallVal, base, big, small, inc, disVal);
			return inc;
		}
		
		//exit(0);
	}
	else if (big == disVal) 
	{  
		tran.val = big;
		tran.inc = inc;
		tran.tara = 1;
		printRes();
		printf("\nAAA %d\t%d\t%d|\t%d\t%d\t%d|\t%d\t|%d\t\n", baseVal, bigVal, smallVal, base, big, small, inc, disVal);
		//exit(0);
	}
	else if (small == disVal) 
	{ 
		tran.val = small;
		tran.inc = inc;
		tran.tara = 2;
		printRes();
		printf("\nAAA %d\t%d\t%d|\t%d\t%d\t%d|\t%d\t|%d\t\n", baseVal, bigVal, smallVal, base, big, small, inc, disVal);
		//exit(0);
	}
	else if (inc < MAX_NUM_OF_TRAN)
	{
//------------------------------------------------FROM BASE TO BIG(1)--------------------------------------------------------------
		if ((base + big - bigVal) <= bigVal && (base + big - bigVal) >= (0 - bigVal) && base != 0 && big != bigVal)// && tran.trans[inc - 1] != '1')
		{
			int tmp = (base + big) - bigVal;
			if (tmp > 0)
			{
				tran.trans[inc] = '1';
				transfusion(baseVal, bigVal, smallVal, tmp, bigVal, small, inc + 1, disVal);
			}
			else
			{
				tran.trans[inc] = '1';
				transfusion(baseVal, bigVal, smallVal, 0, big + base, small, inc + 1, disVal);
			}
			//printf("\nAAA %d\t%d\t%d|\t%d\t%d\t%d|\t%d\t|%d\t\n", baseVal, bigVal, smallVal, base, big, small, inc, disVal);
		}
//----------------------------------------------FROM BASE TO SMALL(2)-------------------------------------------------------------
		if ((base + small - smallVal) <= smallVal && (base + small - smallVal) >= (0 - smallVal) && base != 0 && small != smallVal)			
		{
			int tmp = (base + small) - smallVal;
			if (tmp > 0)
			{
				tran.trans[inc] = '2';
				transfusion(baseVal, bigVal, smallVal, tmp, big, smallVal, inc + 1, disVal);
			}
			else
			{
				tran.trans[inc] = '2';
				transfusion(baseVal, bigVal, smallVal, 0, big, small + base, inc + 1, disVal);
			}
		}
//-----------------------------------------------FROM BIG TO BASE(3)---------------------------------------------------------------
		if ((big + base - baseVal) <= baseVal && (big + base - baseVal) >= (0 - baseVal) && big != 0 && base != baseVal)
		{
			int tmp = (big + base - baseVal);
			if (tmp > 0)
			{
				tran.trans[inc] = '3';
				transfusion(baseVal, bigVal, smallVal, baseVal, tmp, small, inc + 1, disVal);
			}
			else
			{
				tran.trans[inc] = '3';
				transfusion(baseVal, bigVal, smallVal, base+big, 0, small, inc + 1, disVal);
			}

		}
//-----------------------------------------------FROM BIG TO SMALL(4)--------------------------------------------------------------
		if ((big + small - smallVal) <= smallVal && (big + small - smallVal) >= (0 - smallVal) && big != 0)// && small != smallVal)
		{
			int tmp = (big + small - smallVal);
			if (tmp > 0)
			{
				tran.trans[inc] = '4';
				transfusion(baseVal, bigVal, smallVal, base, tmp, smallVal, inc + 1, disVal);				
			}
			else
			{
				tran.trans[inc] = '4';
				transfusion(baseVal, bigVal, smallVal, base, 0, small + big, inc + 1, disVal);				
			}
			
		}
//----------------------------------------------FROM SMALL TO BASE(5)--------------------------------------------------------------
		if ((small + base - baseVal) <= baseVal && (small + base - baseVal) >= (0 - baseVal) && small != 0 && base != baseVal)
		{
			int tmp = (small + base - baseVal);
			if (tmp > 0)
			{
				tran.trans[inc] = '5';
				transfusion(baseVal, bigVal, smallVal, baseVal, big, tmp, inc + 1, disVal);
			}
			else
			{
				tran.trans[inc] = '5';
				transfusion(baseVal, bigVal, smallVal, base + small, big, 0, inc + 1, disVal);
			}

		}
//-----------------------------------------------FROM SMALL TO BIG(6)---------------------------------------------------------------
		if ((small + big - bigVal) <= bigVal && (small + big - bigVal) >= (0 - bigVal) && small != 0 && big != bigVal)
		{
			int tmp = (small + big - bigVal);
			if (tmp > 0)
			{
				tran.trans[inc] = '6';
				transfusion(baseVal, bigVal, smallVal, base, bigVal, tmp, inc + 1, disVal);
			}
			else
			{
				tran.trans[inc] = '6';
				transfusion(baseVal, bigVal, smallVal, base, big + small, 0, inc + 1, disVal);
			}
		}
	}
	else
	{
		//printf("\n������� ���\n");
	}

	//printf("AAA %d\t%d\t%d|\t%d\t%d\t%d|\t%d\t|%d\t\n", baseVal, bigVal, smallVal, base, big, small, inc, disVal);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	/*int first = 0, second = 0, third = 0;
	do {

		printf("������� ������� �� ������ ���� �������!\n\n������� ����� ������� ������: ");
		scanf_s("%d", &first);
		printf("������� ����� ������� ������: ");
		scanf_s("%d", &second);
		printf("������� ����� �������� ������: ");
		scanf_s("%d", &third);
	} while (first == second || second == third || first == third);*/


	int base = 0, big = 0, small = 0;

	int first = 8, second = 5, third = 3;
	//int first = 12, second = 8, third = 5;

	//������� �������, ������� � ��������� ������

	if (first > second)
	{
		if (first > third)
		{
			base = first;
			if (second > third)
			{
				big = second;
				small = third;
			}
			else
			{
				big = third;
				small = second;
			}
		}
		else
		{
			base = third;
			big = first;
			small = second;
		}

	}
	else
	{
		if (second > third)
		{
			base = second;
			if (first > third)
			{
				big = first;
				small = third;
			}
			else
			{
				big = third;
				small = first;
			}
		}
		else
		{
			base = third;
			big = second;
			small = third;
		}
	}

	int disVal = 0;
	do
	{
		printf("������� ���������� ������ �� ����� ���� ������ ������ �������� ������!\n����� �������� ������: %d\n", base);
		printf("������� ������� ���������� ������: ");
		scanf_s("%d", &disVal);
	} while (disVal > base);
	int inc = 0;
	if (base == disVal)
	{
		printf("\n������� ��������(%d) ��������� � ������� ������, ����� %d �����������\n", base, inc);
	}
	else
	{
		tran.trans[inc] = '1';
		transfusion(base, big, small, base - big, big, 0, inc + 1, disVal);
		tran.trans[inc] = '2';
		//transfusion(base, big, small, base - small, 0, small, inc+1, disVal);
		
	}
}