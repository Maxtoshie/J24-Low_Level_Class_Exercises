#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    printf("Enter number of names: ");
    scanf("%d", &n);

    char **names = malloc(n * sizeof(char *));
    if (!names) return 1;

    for (int i = 0; i < n; i++) {
        char temp[100];
        printf("Enter name %d: ", i + 1);
        scanf("%s", temp);

        names[i] = malloc(strlen(temp) + 1);
        strcpy(names[i], temp);
    }

    printf("\nNames entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
        free(names[i]);
    }

    free(names);
    return 0;
}
