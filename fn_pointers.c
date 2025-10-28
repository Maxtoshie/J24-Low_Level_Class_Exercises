#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*fp)(int, int);
    fp = add;
    printf("Pointer call: (*fp)(10, 20) = %d\n", (*fp)(10, 20));
    printf("Direct call: add(10, 20) = %d\n", add(10, 20));
    return 0;
}
