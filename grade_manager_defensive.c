#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "students.txt"
#define MAX_NAME 50
#define MAX_LINE 100

int main() {
    int n, grade;
    char name[MAX_NAME];
    FILE *fp = NULL;

    // Step 1: Get number of students
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: Invalid number of students.\n");
        return EXIT_FAILURE;
    }
    getchar();  // Clear newline

    // Step 2: Open file for writing (DEFENSIVE)
    fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");  // Best: system error message
                                                   // Alternative: fprintf(stderr, "Failed to open %s: permission denied or disk full\n", FILENAME);
        return EXIT_FAILURE;
    }

    printf("=== Entering %d students ===\n", n);

    // Step 3: Input loop
    for (int i = 0; i < n; i++) {
        printf("Student %d Name: ", i + 1);
        if (fgets(name, MAX_NAME, stdin) == NULL) {
            fprintf(stderr, "Error: Failed to read name.\n");
            fclose(fp);
            return EXIT_FAILURE;
        }
        name[strcspn(name, "\n")] = '\0';  // Remove \n

        printf("Student %d Grade: ", i + 1);
        if (scanf("%d", &grade) != 1) {
            fprintf(stderr, "Error: Invalid grade input.\n");
            getchar();  // Clear bad input
            fclose(fp);
            return EXIT_FAILURE;
        }
        getchar();  // Clear newline

        // Safe write
        if (fprintf(fp, "%s,%d\n", name, grade) < 0) {
            perror("Error writing to file");
            fclose(fp);
            return EXIT_FAILURE;
        }
    }

    // Step 4: Close file safely
    if (fclose(fp) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }
    printf("--- Data Saved to %s ---\n", FILENAME);

    // Step 5: Re-open for reading (DEFENSIVE)
    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return EXIT_FAILURE;
    }

    printf("--- Reading Data from File ---\n");

    char line[MAX_LINE];
    char saved_name[MAX_NAME];
    int saved_grade;

    while (fgets(line, MAX_LINE, fp) != NULL) {
        if (sscanf(line, "%49[^,],%d", saved_name, &saved_grade) != 2) {
            fprintf(stderr, "Warning: Corrupted line skipped: %s", line);
            continue;  // Skip bad line
        }
        printf("Student: %s, Grade: %d\n", saved_name, saved_grade);
    }

    // Final close
    if (fclose(fp) != 0) {
        perror("Error closing file after reading");
        return EXIT_FAILURE;
    }

    printf("=== Program completed successfully ===\n");
    return EXIT_SUCCESS;
}
