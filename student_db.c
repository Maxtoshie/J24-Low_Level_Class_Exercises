#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

void addStudent(struct Student **students, int *count, int id, const char *name, float gpa) {
    // Grow the array by 1
    *count += 1;
    struct Student *temp = realloc(*students, *count * sizeof(struct Student));
    if (temp == NULL) {
        printf("Oops! Memory ran dry!\n");
        *count -= 1;
        return;
    }
    *students = temp;

    // Add new student
    (*students)[*count - 1].id = id;
    strcpy((*students)[*count - 1].name, name);
    (*students)[*count - 1].gpa = gpa;
}

void updateStudent(struct Student *students, int count, int id, float newGpa) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            students[i].gpa = newGpa;
            printf("Updated GPA for ID %d to %.2f\n", id, newGpa);
            return;
        }
    }
    printf("ID %d not found, buddy!\n", id);
}

void printStudents(struct Student *students, int count) {
    if (count == 0) {
        printf("No students yet, looks lonely!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

int main() {
    struct Student *students = NULL;
    int studentCount = 0;

    // Add a couple of students
    addStudent(&students, &studentCount, 1, "Alice", 3.2);
    addStudent(&students, &studentCount, 2, "Bob", 3.7);

    // Show the initial list
    printf("\nInitial Student List:\n");
    printStudents(students, studentCount);

    // Update a student's GPA
    updateStudent(students, studentCount, 1, 3.5);

    // Show the updated list
    printf("\nUpdated Student List:\n");
    printStudents(students, studentCount);

    // Clean up memory
    free(students);

    return 0;
}
