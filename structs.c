#include <stdio.h>
#include <string.h>

// Define the Book structure with typedef
typedef struct {
    char title[100];
    char author[100];
    int pages;
    float price;
} Book;

// Function to print Book information
void printBook(Book b) {
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Pages: %d\n", b.pages);
    printf("Price: $%.2f\n", b.price);
}

int main() {
    // Array to store 3 book records
    Book books[3];

    // Fill in data manually for 3 books
    strcpy(books[0].title, "The Great Gatsby");
    strcpy(books[0].author, "F. Scott Fitzgerald");
    books[0].pages = 180;
    books[0].price = 10.99;

    strcpy(books[1].title, "1984");
    strcpy(books[1].author, "George Orwell");
    books[1].pages = 328;
    books[1].price = 12.50;

    strcpy(books[2].title, "To Kill a Mockingbird");
    strcpy(books[2].author, "Harper Lee");
    books[2].pages = 281;
    books[2].price = 11.75;

    // Print all book information clearly
    for (int i = 0; i < 3; i++) {
        printf("\nBook %d:\n", i + 1);
        printBook(books[i]);
    }

    return 0;
}
