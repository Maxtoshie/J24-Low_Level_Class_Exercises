#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int main() {
    int (*operations[4])(int, int) = {add, subtract, multiply, divide};
    int a, b, choice;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    printf("Choose operation (0=add, 1=sub, 2=mul, 3=div): ");
    scanf("%d", &choice);

    if (choice >= 0 && choice <= 3) {
        int result = operations[choice](a, b);
        printf("Result: %d\n", result);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
