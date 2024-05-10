#include <stdio.h>
#include <string.h>

// Define a structure for an item
struct Item {
    char name[50];
};

// Maximum number of items
const int MAX_ITEMS = 100;

// Array to store shopping list items
struct Item shoppingList[MAX_ITEMS];
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

// Function to remove an item from the list
void removeItem() {
    if (itemCount == 0) {
        printf("Shopping list is empty. Nothing to remove.\n");
        return;
    }
    printf("Enter the index of the item to remove (1-%d): ", itemCount);
    int index;
    scanf("%d", &index);
    getchar(); // Consume the newline character left in the input buffer
    if (index < 1 || index > itemCount) {
        printf("Invalid index. Please enter a number between 1 and %d.\n", itemCount);
        return;
    }
    printf("Removing item '%s' from the list.\n", shoppingList[index - 1].name);
    // Shift items to fill the gap left by the removed item
    for (int i = index - 1; i < itemCount - 1; i++)
        strcpy(shoppingList[i].name, shoppingList[i + 1].name);
    itemCount--;
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
        printf("\nShopping List Management\n1. Add Item\n2. Remove Item\n3. View List\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left in the input buffer
        switch(choice) {
            case 1: 
                addItem(); 
                break;
            case 2: 
                removeItem(); 
                break;
            case 3: 
                viewList(); 
                break;
            case 4: 
                printf("Exiting program. Goodbye!\n"); 
                break;
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4); // Loop until user chooses to exit
    return 0;
}
