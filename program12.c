#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    char author[50];
    int available;
};

struct Book b[100];
int count = 0;

void addBook() {
    printf("\nEnter Book ID: ");
    scanf("%d", &b[count].id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", b[count].name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b[count].author);

    b[count].available = 1;
    count++;

    printf("\nBook Added Successfully!\n");
}

void displayBooks() {
    int i;

    printf("\n--- BOOK DETAILS ---\n");

    if (count == 0) {
        printf("No Books Available!\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\nBook ID: %d", b[i].id);
        printf("\nBook Name: %s", b[i].name);
        printf("\nAuthor: %s", b[i].author);
        printf("\nStatus: %s\n",
        b[i].available ? "Available" : "Issued");
    }
}

void searchBook() {
    int id, i, found = 0;

    printf("\nEnter Book ID to Search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (b[i].id == id) {
            printf("\nBook Found!");
            printf("\nBook Name: %s", b[i].name);
            printf("\nAuthor: %s\n", b[i].author);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nBook Not Found!\n");
}

void issueBook() {
    int id, i;

    printf("\nEnter Book ID to Issue: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (b[i].id == id) {
            if (b[i].available == 1) {
                b[i].available = 0;
                printf("\nBook Issued Successfully!\n");
            } else {
                printf("\nBook Already Issued!\n");
            }
            return;
        }
    }

    printf("\nBook Not Found!\n");
}

void returnBook() {
    int id, i;

    printf("\nEnter Book ID to Return: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (b[i].id == id) {
            if (b[i].available == 0) {
                b[i].available = 1;
                printf("\nBook Returned Successfully!\n");
            } else {
                printf("\nBook Was Not Issued!\n");
            }
            return;
        }
    }

    printf("\nBook Not Found!\n");
}

int main() {
    int choice;

    do {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====");
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Search Book");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Exit");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: printf("\nThank You!\n"); break;
            default: printf("\nInvalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}