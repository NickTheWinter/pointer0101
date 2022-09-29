#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"


int main(void)
{
	setlocale(LC_ALL, "Rus");

	float number = 1;
	printf("Число = %.3f\nВведите число для изменения\n", number);
	float* number2 = &number;
	scanf_s("%f", &number);

	printf("Измененное число = %.3f", *number2);

	int n = 1000000;
	int* massiv = DynamicArray(n);
	PrintArray(massiv, n / 10000);
	free(massiv);

	n = 10;
	TriangleArray(n);
	
	system("pause");
}
void TriangleArray(int n)
{
	int** massiv = calloc(n,sizeof(int));
	int counter = 0;
	for (size_t i = 0; i < n; i++)
	{
		massiv[i] = calloc((i + 1), sizeof(int));

		for (size_t j = 0; j <= i; j++)
		{
			massiv[i][j] = counter;
			counter++;
		}
	}
	PrintTriangleArray(massiv, n);
	for (size_t i = 0; i < n; i++)
	{
		free(massiv[i]);
	}
	free(massiv);
}

int* DynamicArray(int n) 
{
	int* massiv = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		massiv[i] = i;
	}
	return massiv;
}
void PrintArray(int massiv[], int n)
{
	printf("\nМассив: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", massiv[i]);
	}
	printf("\n");
}
void PrintTriangleArray(int** massiv, int n)
{
	printf_s("\nТреугольная матрица:\n");
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j <= i; j++)
		{
			printf("%d ", massiv[i][j]);
		}
		printf("\n");
	}

}