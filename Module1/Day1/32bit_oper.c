#include <stdio.h>
int bit_operations(int num, int oper_type) {
    switch (oper_type) {
        case 1:
            // Set 1st bit
            num |= 1;
            break;
        case 2:
            // Clear 31st bit
            num &= ~(1 << 31);
            break;
        case 3:
            // Toggle 16th bit
            num ^= (1 << 16);
            break;
        default:
            printf("Invalid operation type\n");
            return -1;  // Return an error code
    }

    return num;
}

int main() {
    int number, operationType;
    int result;

    printf("Enter a 32-bit integer: ");
    scanf("%d", &number);

    printf("Enter the operation type (1, 2, or 3): ");
    scanf("%d", &operationType);

    result = bit_operations(number, operationType);

    if (result != -1) {
        printf("Result: %d\n", result);
    }

    return 0;
}