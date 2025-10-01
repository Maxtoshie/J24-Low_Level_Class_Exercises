#include <stdio.h>
#include <string.h>


int main() {
    char names[6][50];
    float grades[6][2];
    int num_students;

    do {
        printf("Enter number of students (3-6): ");
        scanf("%d", &num_students);
    } while (num_students < 3 || num_students > 6);

    getchar(); // Clear newline

    printf("\nEnter student details:\n");
    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Name: ");
        fgets(names[i], 50, stdin);
        names[i][strcspn(names[i], "\n")] = 0; // Remove newline

        printf("Grade for Course 1: ");
        scanf("%f", &grades[i][0]);

        printf("Grade for Course 2: ");
        scanf("%f", &grades[i][1]);

        getchar(); // Clear newline
    }

    printf("\n=== GRADEBOOK ===\n");
    printf("No.  %-20s %-12s %-12s\n", "Name", "Course 1", "Course 2");
    printf("------------------------------------------------\n");

    for (int i = 0; i < num_students; i++) {
        printf("%-4d%-20s%-12.2f%-12.2f\n",
               i + 1, names[i], grades[i][0], grades[i][1]);
    }

    return 0;
}
