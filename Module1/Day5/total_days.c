#include <stdio.h>

int isLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    } else if (year % 100 == 0) {
        return 0;
    } else if (year % 4 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int day, month, year;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays = 0;
    
    printf("Enter the date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);
    
    // Check for valid date
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > daysInMonth[month-1]) {
        printf("Invalid date.\n");
        return 0;
    }
    
    // Count days in previous months of the given year
    for (int i = 0; i < month-1; i++) {
        totalDays += daysInMonth[i];
    }
    
    // Adjust for leap year if necessary
    if (isLeapYear(year) && month > 2) {
        totalDays += 1;
    }
    
    // Add days of the current month
    totalDays += day;
    
    printf("Total number of days up to %02d/%02d/%04d is %d.\n", day, month, year, totalDays);
    
    return 0;
}