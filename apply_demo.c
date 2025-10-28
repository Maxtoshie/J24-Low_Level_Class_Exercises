#include <stdio.h>

// Arithmetic Operations
int add(int a, int b)      { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b)   { return b != 0 ? a / b : 0; }  // Safe division

// Generic apply function
int apply(int (*operation)(int, int), int x, int y) {
    return operation(x, y);
}

int main() {
    int a = 20, b = 5;

    printf("=== Testing apply() with Different Operations ===\n");
    printf("Add:      %d\n", apply(add, a, b));
    printf("Subtract: %d\n", apply(subtract, a, b));
    printf("Multiply: %d\n", apply(multiply, a, b));
    printf("Divide:   %d\n", apply(divide, a, b));

    // Edge Case: Division by zero
    printf("\nEdge Case: Division by zero\n");
    printf("20 / 0 = %d (safe: returns 0)\n", apply(divide, 20, 0));

    return 0;
}
