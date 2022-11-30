#include "array.h"
#include<stdio.h>

int main()
{
	int *mas,size=0;
	printf("Input size of masive[1-100]:");
	inputChekerSize(&size);
	mas=memory(size);
	printf("All elements should be in range[-1000;1000].\n");
	inputMas(mas, size);
	printf("Masive:");
	showMas(mas, size);
	printf("\n");
	deleteEleven(&mas, &size);
	printf("Result:");
	showMas(mas, size);
	return 0;
}