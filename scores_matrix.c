#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matrix, rows, cols;
    printf("Enter rows and cols: ");
    scanf("%d %d", &rows, &cols);

    matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    printf("Enter scores:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    printf("\nScore Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%4d ", matrix[i][j]);
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
