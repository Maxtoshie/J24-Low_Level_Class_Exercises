#include <stdio.h>

int main() {
    // Snippet 1
    int arr[] = {3, 6, 9};
    printf("%d\n", arr[1]);      // Should print 6
    printf("%d\n", *(arr + 1));  // Should print 6

    // Snippet 2
    int arr2[] = {2, 4, 6, 8};   // Renamed to avoid redefinition
    int *ptr = arr2;
    printf("%d\n", *(ptr + 2));  // Should print 6
    printf("%d\n", ptr[2]);      // Should print 6

    return 0;
}
