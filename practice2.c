#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define MAX_BOOKS 1000

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int year;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    Book new_book;

    printf("Enter title: ");
    getchar(); // clear buffer
    fgets(new_book.title, MAX_TITLE_LEN, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = '\0';

    printf("Enter author: ");
    fgets(new_book.author, MAX_AUTHOR_LEN, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = '\0';

    printf("Enter year: ");
    scanf("%d", &new_book.year);

    library[book_count++] = new_book;
    printf("Book added successfully.\n");
}

void display_books() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }

    for (int i = 0; i < book_count; i++) {
        printf("Book %d:\n", i + 1);
        printf(" Title: %s\n", library[i].title);
        printf(" Author: %s\n", library[i].author);
        printf(" Year: %d\n\n", library[i].year);
    }
}

void search_book() {
    char query[MAX_TITLE_LEN];
    printf("Enter title to search: ");
    getchar(); // clear buffer
    fgets(query, MAX_TITLE_LEN, stdin);
    query[strcspn(query, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(library[i].title, query) == 0) {
            printf("Book found:\n");
            printf(" Title: %s\n", library[i].title);
            printf(" Author: %s\n", library[i].author);
            printf(" Year: %d\n", library[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void remove_book() {
    char title[MAX_TITLE_LEN];
    printf("Enter title to remove: ");
    getchar(); // clear buffer
    fgets(title, MAX_TITLE_LEN, stdin);
    title[strcspn(title, "\n")] = '\0';

    int index = -1;
    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(library[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    for (int i = index; i < book_count - 1; i++) {
        library[i] = library[i + 1];
    }

    book_count--;
    printf("Book removed successfully.\n");
}

void menu() {
    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search Book\n");
    printf("4. Remove Book\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_book();
            break;
        case 2:
            display_books();
            break;
        case 3:
            search_book();
            break;
        case 4:
            remove_book();
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}
