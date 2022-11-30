#include"array.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MaxElement 1000
#define MinElement -1000
#define MaxSize 100
#define MinSize 1

int random(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void choiseFunction(int* choise)
{
	while (scanf_s("%d", choise) != 1 || *choise < 0 || *choise>1 || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		printf("If you want random input 1. If you want input masive by hands input 0.\n");
	}

}

void inputChekerElement(int* n, int row, int col)
{
	printf("Input element[%d][%d]:", row, col);
	while (scanf_s("%d", &*n) != 1 || *n > MaxElement || *n < MinElement || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		printf("Input element[%d][%d]:", row, col);
	}

}

void inputChekerRow(int* n)
{
	while (scanf_s("%d", &*n) != 1 || *n > MaxSize || *n < MinSize || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		printf("Input how much rows in masive[1-100]:");
	}
}

void inputChekerColumn(int* n)
{
	while (scanf_s("%d", n) != 1 || *n > MaxSize || *n < MinSize || getchar() != '\n')
	{
		rewind(stdin);
		printf("Error\n");
		printf("Input how much columns in masive[1-100]:");
	}
}

int** memory(int n, int m)
{
	int** mas;
	mas = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		*(mas + i) = (int*)calloc(m , sizeof(int));
	}
	return mas;
}

void inputMasByHand(int** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{

			inputChekerElement(&(*(*(mas + i) + j)), (i + 1), (j + 1));
		}
}

void inputMasRandom(int** mas, int n, int m)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			(*(*(mas + i) + j)) = random(0, 2);
		}
}

void showMas(int** mas, int n, int m)
{
	int cheker = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%4d", *(*(mas + i) + j));
		printf("\n");
		printf("       ");
	}
	printf("\n");
}

int findRow(int* mas, int m)
{
	int cheker = 0;
	for (int j = 0; j < m - 1; j++)
	{
		if (*(mas + j) == 0 && *(mas + (j + 1)) == 0)
		{
			cheker++;
			break;
		}
	}
	return cheker;
}

void delateRow(int*** mas, int* n, int m)
{
	int cheker=0;
	for (int i = (*n)-1; i >=0; i--)
	{
		cheker = findRow(*(*mas+i), m);
		if (cheker == 1)
		{ 
		   int **del = ( * (*mas + i));
			for (int j = i; j < (*n) - 1; j++)
			{
				(* (*mas + j)) = ( * (*mas + (j + 1)));
			}
			free(del);
			(*n)--;
			*mas = (int**)realloc(*mas, (*n) * sizeof(int*));
			cheker = 0;
		}
		
	}



}
