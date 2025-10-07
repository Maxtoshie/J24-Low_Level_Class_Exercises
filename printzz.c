#include <stdio.h>

int main()
{
	int myVariable = 10;
	int *myPointer = &myVariable;

	printf("Initial Value: %d\n", myVariable);
	*myPointer = 20;
	printf("Modified value: %d\n", myVariable);

	return 0;
}
