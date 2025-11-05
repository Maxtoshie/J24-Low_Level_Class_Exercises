#include <stdio.h>
#include <string.h>

int main() {
    int n, grade;
    char name[50];
    FILE *fp;

    // Step 1: Get number of students
    printf("Enter number of students: ");
    scanf("%d", &n);
    getchar();  // Clear newline from buffer

    // Step 2: Open file for writing
    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error: Cannot create file!\n");
        return 1;
    }

    // Step 3: Input loop — collect and save
    for (int i = 0; i < n; i++) {
        printf("Student %d Name: ", i + 1);
        fgets(name, 50, stdin);
        name[strcspn(name, "\n")] = 0;  // Remove newline

        printf("Student %d Grade: ", i + 1);
        scanf("%d", &grade);
        getchar();  // Clear newline

        // Save to file
        fprintf(fp, "%s,%d\n", name, grade);
    }

    fclose(fp);
    printf("--- Data Saved to students.txt ---\n");

    // Step 4: Read back and display
    printf("--- Reading Data from File ---\n");

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot read file!\n");
        return 1;
    }

    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        // Parse: name,grade
        char saved_name[50];
        int saved_grade;
        sscanf(line, "%[^,],%d", saved_name, &saved_grade);
        printf("Student: %s, Grade: %d\n", saved_name, saved_grade);
    }

    fclose(fp);
    return 0;
}
