#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

int main() {
    // Open binary file for reading
    FILE *fp = fopen("students.bin", "rb");
    if (fp == NULL) {
        printf("ERROR: Cannot open 'students.bin' for reading.\n");
        printf("       Make sure the file exists and was created with 'wb' or 'ab'.\n");
        return 1;  // Exit if file not found
    }

    Student s;           // Buffer to hold one student record
    int count = 0;       // Count of students read
    int result;          // Store fread return value

    printf("=== Student Records ===\n");

    // Read records in a loop until end of file
    while ((result = fread(&s, sizeof(Student), 1, fp)) == 1) {
        count++;
        printf("Student %d:\n", count);
        printf("  ID  : %d\n", s.id);
        printf("  Name: %s\n", s.name);
        printf("  GPA : %.2f\n\n", s.gpa);
    }

    // Defensive check: did fread fail for a reason other than EOF?
    if (result != 0) {
        printf("ERROR: Failed to read record (corrupted data or I/O error).\n");
        fclose(fp);
        return 1;
    }

    // Check if any records were read
    if (count == 0) {
        printf("WARNING: No student records found in 'students.bin'.\n");
    } else {
        printf("Successfully read %d student record(s).\n", count);
    }

    // Always close the file
    if (fclose(fp) != 0) {
        printf("ERROR: Failed to close the file properly.\n");
        return 1;
    }

    return 0;
}
