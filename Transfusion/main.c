#include <stdio.h>
#include <locale.h>

void transfusion(const int base, const int big, const int small, int inc, const int disVal)
{
	if (base == disVal) { printf("\nИскомое значение(%d) оказалось в базавом сосуде, через %d переливаний\n", base, inc); }
	else if (big == disVal) { printf("\nИскомое значение(%d) оказалось в большом сосуде, через %d переливаний\n", base, inc); }
	else if (small == disVal) { printf("\nИскомое значение(%d) оказалось в маленьком сосуде, через %d переливаний\n", base, inc); }
	else if (inc < 10)
	{
		transfusion(base - big)
	}

}

int main()
{
	setlocale(LC_ALL, "Rus");
	int first = 0, second = 0, third = 0;
	do {

		printf("Размеры сосудов не должны быть равными!\n\nВведите объём первого сосуда: ");
		scanf_s("%d", &first);
		printf("Введите объём второго сосуда: ");
		scanf_s("%d", &second);
		printf("Введите объём третьего сосуда: ");
		scanf_s("%d", &third);
	} while (first == second || second == third || first == third);


	int base = 0, big = 0, small = 0;

	//Выделим базовый, большой и маленький сосуды

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
		printf("Искомое количество литров не может быть больше объёма базового сосуда!\nОбъём базового сосуда: %d\n", base);
		printf("Введите искомое количество литров: ");
		scanf_s("%d", &disVal);
	} while (disVal > base);
	int inc = 0;
	if (base == disVal)
	{
		printf("\nИскомое значение(%d) оказалось в базавом сосуде, через %d переливаний\n", base, inc);
	}
	else
	{
		transfusion(base - big, big, 0, inc, disVal);
		transfusion(base - small, 0, small, inc, disVal);
	}

}