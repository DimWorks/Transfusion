#include <stdio.h>
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "Rus");
	int first = 0, second = 0, third = 0;
	printf("Введите объём первого сосуда: ");
	scanf("%d", first);
	printf("Введите объём второго сосуда: ");
	scanf("%d", second);
	printf("Введите объём третьего сосуда: ");
	scanf("%d", third);


}