#include <stdio.h>

int main() {
    int rollNo;
    char name[50];
    float phyMarks, mathMarks, chemMarks;
    float totalMarks, percentage;
    
    printf("Enter Roll No: ");
    scanf("%d", &rollNo);

    printf("Enter Name: ");
    scanf(" %s", name);

    printf("Enter Phy Marks: ");
    scanf("%f", &phyMarks);

    printf("Enter Math Marks: ");
    scanf("%f", &mathMarks);

    printf("Enter Chem Marks: ");
    scanf("%f", &chemMarks);
    
totalMarks = phyMarks + mathMarks + chemMarks;
    percentage = (totalMarks / 300.0) * 100.0;

    // Print the summary
    printf("\n-------- Student Summary --------\n");
    printf("Roll No: %d\n", rollNo);
    printf("Name: %s\n", name);
    printf("Phy Marks: %.2f\n", phyMarks);
    printf("Math Marks: %.2f\n", mathMarks);
    printf("Chem Marks: %.2f\n", chemMarks);
    printf("Total Marks: %.2f\n", totalMarks);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}