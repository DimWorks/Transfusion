#include <stdio.h>
#include <locale.h>

void transfusion(const int baseVal, const int bigVal, const int smallVal, const int base, const int big, const int small, int inc, const int disVal)
{
	if (base == disVal) { printf("\n������� ��������(%d) ��������� � ������� ������, ����� %d �����������\n", base, inc); exit(0); }
	else if (big == disVal) { printf("\n������� ��������(%d) ��������� � ������� ������, ����� %d �����������\n", big, inc); exit(0); }
	else if (small == disVal) { printf("\n������� ��������(%d) ��������� � ��������� ������, ����� %d �����������\n", small, inc); exit(0); }
	else if (inc < 10)
	{
		if(big >= small)	transfusion(baseVal, bigVal, smallVal, base, big-smallVal, smallVal, inc+1, disVal);
		/*if ((big + small) <= smallVal)
		{
			transfusion(baseVal, bigVal, smallVal, base, big - smallVal, smallVal, inc + 1, disVal);
		}
		else
		{
			transfusion(baseVal, bigVal, smallVal, base, big - smallVal, smallVal, inc + 1, disVal);
		}*/
		if ((base + small) <= baseVal)																				// ���� ������� ����� ����� �������� ���������� ���������� ������
		{
			transfusion(baseVal, bigVal, smallVal, base+small, big, 0, inc + 1, disVal);							// ���������� �Ѩ ���������� 
		}
		else																										// ���� ������� ����� �� �������� �������� ��������� ����������
		{
			transfusion(baseVal, bigVal, smallVal, baseVal, big, (base + small) - baseVal, inc + 1, disVal);		// � ��������� ������ ��������� "�������", � �������� �������� ��� ������ ��������
		}
	}

	printf("AAA %d\t%d\t%d\t|%d\t%d\t%d\t%d\t|%d\t\n", baseVal, bigVal, smallVal, base, big, small, inc, disVal);
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
		transfusion(base, big, small, base - big, big, 0, inc+1, disVal);
		transfusion(base, big, small, base - small, 0, small, inc+1, disVal);
	}

}