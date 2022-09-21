#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
int main(void)
{
	setlocale(LC_ALL, "Rus");

	int number = 1;
	printf("Число = %d\nВведите число для изменения", number);
	int* number2;
	scanf_s("&d",&number2);

	int n = 1000000;
	int* massiv = DynamicArray(n);
	PrintArray(massiv, n / 10000);
	free(massiv);
	system("pause");
}

int* DynamicArray(int n) 
{
	int* massiv = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		massiv[i] = i;
	}
	return massiv;
}
void PrintArray(int massiv[], int n)
{
	printf("Массив: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", massiv[i]);
	}
}
