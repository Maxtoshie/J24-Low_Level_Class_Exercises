#include <stdio.h>

int main() {
    // Declare and initialize an array
    int numbers[6] = {10, 20, 30, 40, 50, 60};

    // Print the value of the second element (index 1)
    printf("Value of second element: %d\n", numbers[1]); // Output: 20

    // Print the address of the first and second elements
    printf("Address of first element:  %p\n", numbers); // Output: e.g., 0x7ffee...
    printf("Address of second element: %p\n", (numbers+1)); // Output: e.g., 0x7ffee... (next address)
   printf("Value of sixth element: %d\n", numbers[5]);
   printf("Address of sixth element: %p\n", (numbers+5));
    return 0;
}
