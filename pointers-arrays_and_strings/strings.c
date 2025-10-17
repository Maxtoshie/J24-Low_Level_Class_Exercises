#include <stdio.h>

int main() {
    char greeting[] = "Hello";
    char name[50];
    char location[50];
    char food[50];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Enter your location");
    gets(location);
    printf("Enter your favourite food");
    fgets(food, 50, stdin);
    printf("%s, %s you are from %s and your favourite food is %s\n", greeting, name, location, food);

    return 0;
}
