#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseAndInitialize(struct Student* students, int numStudents) {
    char inputString[100];
    
    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        
        // Read the input string
        printf("Input String: ");
        fgets(inputString, sizeof(inputString), stdin);
        
        // Remove the newline character from the input string
        inputString[strcspn(inputString, "\n")] = '\0';
        
        // Tokenize the input string
        char* token = strtok(inputString, " ");
        
        // Parse and store the rollno
        students[i].rollno = atoi(token);
        
        // Get the next token (name)
        token = strtok(NULL, " ");
        
        // Parse and store the name
        strncpy(students[i].name, token, sizeof(students[i].name) - 1);
        students[i].name[sizeof(students[i].name) - 1] = '\0';
        
        // Get the next token (marks)
        token = strtok(NULL, " ");
        
        // Parse and store the marks
        students[i].marks = atof(token);
        
        printf("\n");
    }
}

void printStudentData(struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar(); // Clear the newline character from the input buffer
    
    // Allocate memory for the array of structures
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));
    
    // Read and initialize the data for each student
    parseAndInitialize(students, numStudents);
    
    // Print the data for each student
    printStudentData(students, numStudents);
    
    // Free the allocated memory
    free(students);
    
    return 0;
}