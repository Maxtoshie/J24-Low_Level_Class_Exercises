#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    int arr[n];

    // Populate array with user inputs
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Initialize min and max with first element
    int min = arr[0];
    int max = arr[0];
    int sum = 0;

    // Find min, max, and calculate sum
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
        sum += arr[i];
    }

    // Calculate average
    double avg = (double)sum / n;

    // Print results
    printf("\n--- Results ---\n");
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    printf("Average value: %.2f\n", avg);

    return 0;
}
