#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Snippet 1: Properly allocate and copy string with null termination
    char *str = (char *)malloc(6 * sizeof(char)); // Allocate space for "Hello" + null terminator
    if (str != NULL) {
        strcpy(str, "Hello");
        printf("String: %s\n", str);
        free(str); // Free allocated memory
    }

    // Snippet 2: Allocate and use array before freeing
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr != NULL) {
        for (int i = 0; i < 5; i++) {
            arr[i] = i;
            printf("arr[%d] = %d\n", i, arr[i]);
        }
        free(arr); // Free allocated memory
    }

    // Snippet 3: Allocate, initialize, and use pointer
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr != NULL) {
        *ptr = 10;
        printf("ptr value: %d\n", *ptr);
        free(ptr); // Free allocated memory
    }

    // Snippet 4: Allocate, initialize, and use array
    int *numbers = (int *)malloc(10 * sizeof(int));
    if (numbers != NULL) {
        for (int i = 0; i < 10; i++) {
            numbers[i] = i * 2;
            printf("numbers[%d] = %d\n", i, numbers[i]);
        }
        free(numbers); // Free allocated memory
    }

    return 0;
}
