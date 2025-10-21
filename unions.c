#include <stdio.h>

union SensorData {
    int temperature;
    float humidity;
};

int main() {
    union SensorData data;

    // Prompt user input
    printf("Enter value for temperature: ");
    scanf("%d", &data.temperature);
    printf("Enter value for humidity: ");
    scanf("%f", &data.humidity);

    // Print stored values appropriately
    printf("\nStored values:\n");
    printf("Temperature: %d\n", data.temperature);
    printf("Humidity: %.2f\n", data.humidity);

    // Test and observe
    printf("\nTesting behavior:\n");
    printf("Last valid value (humidity): %.2f\n", data.humidity); // Humidity overwrites temperature due to union

    // Compare size with struct
    printf("\nSize of union SensorData: %zu bytes\n", sizeof(union SensorData));

    // Define equivalent struct for comparison
    struct SensorDataStruct {
        int temperature;
        float humidity;
    };
    printf("Size of struct SensorDataStruct: %zu bytes\n", sizeof(struct SensorDataStruct));

    return 0;
}
