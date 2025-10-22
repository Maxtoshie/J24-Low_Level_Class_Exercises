#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

void updateGPA(struct Student *s) {
    printf("Before update: GPA = %.2f\n", s->gpa); // Print original gpa
    s->gpa = 3.5;                                 // Update gpa to a new value (e.g., 3.5)
    printf("After update: GPA = %.2f\n", s->gpa);  // Print updated gpa
}

int main() {
    struct Student student = {1, "Jotham", 2.5}; // Initial struct with gpa = 2.5
    printf("Student: %s, ID: %d, Initial GPA: %.2f\n", student.name, student.id, student.gpa);
    updateGPA(&student);                        // Pass address of student
    printf("Student: %s, ID: %d, Final GPA: %.2f\n", student.name, student.id, student.gpa);
    return 0;
}
