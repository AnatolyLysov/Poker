#include <stdio.h>
int main() {
    int n, sum = 0;
    // Prompt the user to enter a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    // Use a for loop to add each number from 1 to n
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    // Display the result
    printf("The sum of numbers from 1 to %d is %d\n", n, sum);
    return 0;
}