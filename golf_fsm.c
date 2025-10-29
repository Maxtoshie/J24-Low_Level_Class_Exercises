#include <stdio.h>
#include <unistd.h>

typedef void(*S)();
S cur;

void body(), paint(), assem(), test();  // Forward declarations

void body()  { printf("[Body] Welding...\n"); sleep(1); cur = paint; }
void paint() { printf("[Paint] Coating...\n"); sleep(1); cur = assem; }
void assem(){ printf("[Assembly] Engine+Interior...\n"); sleep(1); cur = test; }
void test()  { printf("[Test] QC Done!\n"); sleep(1); cur = body; }

int main() {
    printf("=== VW Golf MK8 FSM ===\n\n");
    cur = body;
    for(int c = 1; c <= 2; c++) {
        printf("--- Car %d ---\n", c);
        do cur(); while (cur != body);
    }
    printf("\n2 cars built!\n");
    return 0;  // Explicit return
}
