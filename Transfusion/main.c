#include <stdio.h>
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "Rus");
	int first = 0, second = 0, third = 0;
	printf("������� ����� ������� ������: ");
	scanf("%d", first);
	printf("������� ����� ������� ������: ");
	scanf("%d", second);
	printf("������� ����� �������� ������: ");
	scanf("%d", third);


}