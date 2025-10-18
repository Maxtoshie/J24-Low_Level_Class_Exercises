#include <stdio.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Pointer to the first element

    for (int i = 0; i < 5; i++)
    {
        printf("Address using arr[%d]: %p\n", i, &arr[i]);
        printf("Address using ptr + %d: %p\n", i, ptr + i);
    }

    return 0;
}
