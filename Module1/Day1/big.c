#include<stdio.h>

int findMax(int a, int b) {
    // Using if-else
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int max = findMax(num1, num2);
    printf("The biggest number is: %d\n", max);

    return 0;
}
