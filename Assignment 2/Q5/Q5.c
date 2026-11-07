/*=============================================================================
 * 
 * COURSE: Programming Fundamentals
 * SECTION: BDS-1A
 * Author: Rameez Ahmed , ROLL #: 26k-2527
 * 
 * FILE: Q5.c
 * DATE: 10/24/2026
 * DESCRIPTION:  
 *    A menu-driven University Library Management System. It uses arrays, 
 *    pointers, and user-defined functions to manage book inventories, handle
 *    member borrowing/returns (enforcing limits), and calculate late fines 
 *    with promotional waivers based on member type (Student vs Faculty).
 * 
 *=============================================================================*/

#include <stdio.h>
#include <string.h>

// Display Menu
void displayMenu() {
    printf("\n=== University Library Management System ===\n");
    printf("1. Member Registration\n");
    printf("2. Display Available Books\n");
    printf("3. Borrow a Book\n");
    printf("4. Return a Book\n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

//  Member Registration
void registerMember(char name[], int *studentID, int *memberType) {
    printf("Enter member name: ");
    
    scanf(" %[^\n]", name); 
    
    printf("Enter member ID: ");
    scanf("%d", studentID);
    
    do {
        printf("Enter member type (1 for Student, 2 for Faculty): ");
        scanf("%d", memberType);
        if (*memberType != 1 && *memberType != 2) {
            printf("Invalid type. Please enter 1 or 2.\n");
        }
    } while (*memberType != 1 && *memberType != 2);
    
    printf("Registration successful.\n");
}

//  Display Available Books
void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks) {
    int i; 
    printf("\n-------------------------------------------------\n");
    printf("| %-5s | %-25s | %-6s |\n", "ID", "Title", "Copies");
    printf("-------------------------------------------------\n");
    for (i = 0; i < totalBooks; i++) {
        printf("| %-5d | %-25s | %-6d |\n", bookIDs[i], bookTitles[i], availableCopies[i]);
    }
    printf("-------------------------------------------------\n");
}

//  Borrow a Book
void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks, 
                int borrowedBookIDs[], int *borrowedCount, int memberType) {
    
    int reqID, reqDays, index, i; // Variables declared at the top
    
    if (*borrowedCount >= 3) {
        printf("Error: Maximum borrowing limit (3 books) reached.\n");
        return;
    }

    printf("Enter book ID to borrow: ");
    scanf("%d", &reqID);
    
    // Ensure positive days
    do {
        printf("Enter intended number of days to keep: ");
        scanf("%d", &reqDays);
        if (reqDays <= 0) printf("Days must be positive.\n");
    } while (reqDays <= 0);

    // Search for book
    index = -1;
    for (i = 0; i < totalBooks; i++) {
        if (bookIDs[i] == reqID) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Invalid book ID.\n");
    } else if (availableCopies[index] == 0) {
        printf("Error: No copies of '%s' are currently available.\n", bookTitles[index]);
    } else {
        // Valid borrow
        availableCopies[index]--;
        borrowedBookIDs[*borrowedCount] = reqID;
        (*borrowedCount)++;
        printf("Successfully borrowed '%s'.\n", bookTitles[index]);
    }
}

// Return a Book
float returnBook(int bookIDs[], int availableCopies[], int totalBooks, 
                 int borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine) {
    
    int retID, borrowedIndex, i, actualDays, allowedDays, fineRate, lateDays;
    float currentFine, payableFine;
    char code[20];
    
    printf("Enter book ID to return: ");
    scanf("%d", &retID);

    // Verify member actually borrowed it
    borrowedIndex = -1;
    for (i = 0; i < *borrowedCount; i++) {
        if (borrowedBookIDs[i] == retID) {
            borrowedIndex = i;
            break;
        }
    }

    if (borrowedIndex == -1) {
        printf("Error: You have not borrowed this book.\n");
        return 0.0;
    }

    do {
        printf("Enter actual number of days kept: ");
        scanf("%d", &actualDays);
        if (actualDays <= 0) printf("Days must be positive.\n");
    } while (actualDays <= 0);

    // Calculate fine parameters
    allowedDays = (memberType == 1) ? 14 : 30;
    fineRate = (memberType == 1) ? 20 : 10;
    lateDays = actualDays - allowedDays;
    
    currentFine = 0.0;
    if (lateDays > 0) {
        currentFine = lateDays * fineRate;
    }

    *totalFine += currentFine; // Update cumulative gross fine

    // Code waiver
    payableFine = currentFine;
    if (currentFine > 0) {
        printf("Calculated Fine: Rs. %.2f. Enter membership code for waiver (or 'none'): ", currentFine);
        scanf("%s", code);
        if (strcmp(code, "LIB2026") == 0) {
            payableFine = currentFine * 0.50; // 50% waiver
            printf("Code accepted! 50%% waiver applied.\n");
        } else {
            printf("Invalid code. No waiver applied.\n");
        }
    }
    
    // Update Book Inventory
    for (i = 0; i < totalBooks; i++) {
        if (bookIDs[i] == retID) {
            availableCopies[i]++;
            printf("Successfully returned Book ID %d. Fine payable: Rs. %.2f\n", bookIDs[i], payableFine);
            break;
        }
    }

    // Remove from borrowed list by shifting elements left
    for (i = borrowedIndex; i < *borrowedCount - 1; i++) {
        borrowedBookIDs[i] = borrowedBookIDs[i + 1];
    }
    (*borrowedCount)--;

    return payableFine;
}

// Display Member Record
void displayMemberRecord(char name[], int studentID, int memberType, 
                         int borrowedBookIDs[], int borrowedCount, float totalFine, float fineAfterWaiver) {
    int i;
    
    printf("\n=== Member Record ===\n");
    printf("Name: %s\n", name);
    printf("ID: %d\n", studentID);
    printf("Type: %s\n", (memberType == 1) ? "Student" : "Faculty");
    
    printf("Currently Borrowed Book IDs: ");
    if (borrowedCount == 0) {
        printf("None");
    } else {
        for (i = 0; i < borrowedCount; i++) {
            printf("%d ", borrowedBookIDs[i]);
        }
    }
    printf("\n");
    printf("Total fine charged (before waiver): Rs. %.2f\n", totalFine);
    printf("Final fine payable (after waiver): Rs. %.2f\n", fineAfterWaiver);
}

// Main Function
int main() {
    // Initialize Book Inventory
    int bookIDs[] = {101, 102, 103, 104};
    char bookTitles[][50] = {"Programming in C", "Data Structures", "Database Systems", "Computer Networks"};
    int availableCopies[] = {5, 3, 0, 4};
    int totalBooks = 4;

    // Member Variables
    char name[100] = "Not Registered";
    int studentID = 0;
    int memberType = 0; // 1 = Student, 2 = Faculty
    
    // Borrowing state variables
    int borrowedBookIDs[3]; 
    int borrowedCount = 0;
    
    // Financial trackers
    float totalFine = 0.0;
    float fineAfterWaiver = 0.0;

    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);

        // Optional check to ensure user registered before doing other operations
        if (choice >= 3 && choice <= 5 && memberType == 0) {
            printf("\nPlease register a member first (Option 1)!\n");
            continue;
        }

        switch (choice) {
            case 1:
                registerMember(name, &studentID, &memberType);
                break;
            case 2:
                displayBooks(bookIDs, bookTitles, availableCopies, totalBooks);
                break;
            case 3:
                borrowBook(bookIDs, bookTitles, availableCopies, totalBooks, 
                           borrowedBookIDs, &borrowedCount, memberType);
                break;
            case 4:
                // Accumulate the specific payable fine from this transaction to the net payable total
                fineAfterWaiver += returnBook(bookIDs, availableCopies, totalBooks, 
                                              borrowedBookIDs, &borrowedCount, memberType, &totalFine);
                break;
            case 5:
                displayMemberRecord(name, studentID, memberType, 
                                    borrowedBookIDs, borrowedCount, totalFine, fineAfterWaiver);
                break;
            case 6:
                printf("\nExiting Library System. Goodbye!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
