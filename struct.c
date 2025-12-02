#include <stdio.h>
#include <string.h>

// Define a structure
struct Student
{
    int id;
    char name[50];
    float marks;
};

int main()
{
    // Declare a structure variable
    struct Student s1;

    // Assign values
    s1.id = 101;
    strcpy(s1.name, "Bibek");
    s1.marks = 87.5;

    // Print values
    printf("Student ID: %d\n", s1.id);
    printf("Student Name: %s\n", s1.name);
    printf("Student Marks: %.2f\n", s1.marks);

    return 0;
}