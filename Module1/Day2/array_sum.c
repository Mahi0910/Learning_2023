#include <stdio.h>

// Function to sum every alternate element starting from index 0
int sumAlternateElements(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i += 2) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = sumAlternateElements(arr, size);

    printf("The sum of every alternate element starting from index 0 is: %d\n", result);

    return 0;
}