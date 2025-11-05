#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

int main() {
    FILE *fp;
    Student s;
    int record_num;

    // Open binary file for reading
    fp = fopen("students.bin", "rb");
    if (fp == NULL) {
        printf("Error: Cannot open students.bin\n");
        return 1;
    }

    // Ask user for record number (1-based for user-friendliness)
    printf("Enter record number (1 for first student, etc.): ");
    scanf("%d", &record_num);

    // Validate record number
    if (record_num <= 0) {
        printf("Invalid record number!\n");
        fclose(fp);
        return 1;
    }

    // Move file pointer to the start of the desired record
    // record_num=1 → offset 0
    // record_num=2 → offset sizeof(Student)
    int offset = (record_num - 1) * sizeof(Student);

    if (fseek(fp, offset, SEEK_SET) != 0) {
        printf("Error: Failed to seek to record %d\n", record_num);
        fclose(fp);
        return 1;
    }

    // Read one student record
    if (fread(&s, sizeof(Student), 1, fp) == 1) {
        printf("\n--- Student Record %d ---\n", record_num);
        printf("ID  : %d\n", s.id);
        printf("Name: %s\n", s.name);
        printf("GPA : %.2f\n", s.gpa);
    } else {
        printf("Error: Record %d not found or file ended early.\n", record_num);
    }

    fclose(fp);
    return 0;
}
