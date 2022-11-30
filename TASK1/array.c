#include "array.h"

#include<stdio.h>
#include<stdlib.h>

#define MaxElement 1000
#define MinElement -1000
#define MaxSize 100
#define MinSize 1

void inputChekerElement(int* n, int size)
{
	printf("Input element[%d]:", size);
	while (scanf_s("%d", &*n) != 1 || *n > MaxElement || *n < MinElement || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		printf("Input element[%d]:", size);
	}
}

void inputChekerSize(int* n)
{
	while (scanf_s("%d", n) != 1 || *n > MaxSize || *n < MinSize || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		printf("Input the size of masive[1-100]:");
	}
}



int* memory(int n)
{
	int* mas;
	mas = (int*)calloc(n, sizeof(int));
	return mas;
}

void inputMas(int* mas, int n)
{
	for (int i = 0; i < n; i++)
		inputChekerElement(&(*(mas + i)), (i + 1));
}

void showMas(int* mas, int n)
{
	int cheker = 0;
	for (int i = 0; i < n; i++)
	{
		printf("%4d", mas[i]);
	}
	printf("\n");
}

void deleteEleven(int** mas, int* n)
{
	int cheker = 0;
	for (int i = 0; i <= *n; i++)
	{
		if (cheker == 2)
		{
			i = 0;
			cheker = 0;
		}
		if (cheker == 1)
		{
			i--;
			cheker = 0;
		}
		if ((*mas)[i] % 11 == 0)
		{
			if (i == 0)
				cheker++;
			cheker++;
			for (int k = i; k < (*n - 1); k++)
			{
				(*mas)[k] = (*mas)[k + 1];
			}
			(*n)--;
			*mas = realloc(*mas, *n * sizeof(int));
		}
	}
}