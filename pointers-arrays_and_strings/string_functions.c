#include <stdio.h>
#include <string.h>

int main() {
    char stored_username[50] = "admin";
    char stored_password[50] = "password123";

    char input_username[50];
    char input_password[50];

    printf("Enter username: ");
    fgets(input_username, 50, stdin);

    input_username[strcspn(input_username, "\n")] = 0;

    printf("Enter password: ");
    fgets(input_password, 50, stdin);

    input_password[strcspn(input_password, "\n")] = 0;

    if (strcmp(input_username, stored_username) == 0 &&
        strcmp(input_password, stored_password) == 0) {
        printf("Login successful! Welcome, %s!\n", input_username);
    } else {
        printf("Login failed! Invalid username or password.\n");
    }

    return 0;
}
