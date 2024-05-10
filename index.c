#include <stdio.h>
#include <string.h>

// Define a structure for an item
struct Item {
    char name[50];
};

// Maximum number of items
const int MAX_ITEMS = 100;

// Array to store shopping list items
struct Item shoppingList[100];
int itemCount = 0; // Keep track of the number of items in the list

// Function to add an item to the list
void addItem() {
    if (itemCount == MAX_ITEMS) {
        printf("Shopping list is full. Cannot add more items.\n");
        return;
    }
    printf("Enter the name of the item to add: ");
    fgets(shoppingList[itemCount].name, sizeof(shoppingList[itemCount].name), stdin);
    // Remove the newline character from the input
    shoppingList[itemCount].name[strcspn(shoppingList[itemCount].name, "\n")] = '\0';
    itemCount++;
    printf("Item added to the list.\n");
}

// Function to view the current list of items
void viewList() {
    if (itemCount == 0) {
        printf("Shopping list is empty.\n");
        return;
    }
    printf("Current Shopping List:\n");
    for (int i = 0; i < itemCount; i++)
        printf("%d. %s\n", i + 1, shoppingList[i].name);
}

// Main function to drive the program
int main() {
    int choice;

    // Menu-driven loop
    do {
        printf("\nShopping List Management\n1. Add Item\n2. View List\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left in the input buffer
        switch(choice) {
            case 1: 
                addItem(); 
                break;
            case 2: 
                viewList(); 
                break;
            case 3: 
                printf("Exiting program. Goodbye!\n"); 
                break;
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3); // Loop until user chooses to exit
    return 0;
}