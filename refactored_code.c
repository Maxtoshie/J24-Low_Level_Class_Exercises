#include <stdio.h>
#include <stdlib.h>

void populateArray(int *arr, int size) {
    printf("Enter elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int *arr, int size) {
    printf("You entered:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, *arr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    populateArray(arr, n);
    displayArray(arr, n);

    free(arr);
    return 0;
}
