#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILENAME "contacts.txt"

// Contact structure
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    int call_count; // Track the number of calls made to this contact
} Contact;

// Global array to store contacts and the number of contacts
Contact contacts[MAX_CONTACTS];
int contact_count = 0;

// Function to load contacts from the file
void load_contacts() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No saved contacts found. Starting with an empty list.\n");
        return;
    }

    while (fscanf(file, "%49[^\n]\n%14[^\n]\n", contacts[contact_count].name, contacts[contact_count].phone) == 2) {
        contacts[contact_count].call_count = 0;  // Initialize call history count
        contact_count++;
    }

    fclose(file);
}

// Function to save contacts to the file
void save_contacts() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error opening file to save contacts.\n");
        return;
    }

    for (int i = 0; i < contact_count; i++) {
        fprintf(file, "%s\n%s\n", contacts[i].name, contacts[i].phone);
    }

    fclose(file);
}

// Add new contact
void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }

    Contact new_contact;
    printf("Enter contact name: ");
    getchar();  // to consume the newline left by the previous input
    fgets(new_contact.name, NAME_LENGTH, stdin);
    new_contact.name[strcspn(new_contact.name, "\n")] = 0;  // Remove newline

    printf("Enter contact phone number: ");
    fgets(new_contact.phone, PHONE_LENGTH, stdin);
    new_contact.phone[strcspn(new_contact.phone, "\n")] = 0;

    new_contact.call_count = 0; // Initialize call history count to 0

    contacts[contact_count++] = new_contact;
    save_contacts();  // Save to file after adding
    printf("Contact added successfully!\n");
}

// Delete a contact by name
void delete_contact() {
    char name_to_delete[NAME_LENGTH];
    printf("Enter name of contact to delete: ");
    getchar();  // to consume the newline
    fgets(name_to_delete, NAME_LENGTH, stdin);
    name_to_delete[strcspn(name_to_delete, "\n")] = 0;

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, name_to_delete) == 0) {
            // Shift all contacts to delete the target contact
            for (int j = i; j < contact_count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contact_count--;
            save_contacts();  // Save to file after deletion
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

// Update contact information
void update_contact() {
    char name_to_update[NAME_LENGTH];
    printf("Enter name of contact to update: ");
    getchar();  // to consume the newline
    fgets(name_to_update, NAME_LENGTH, stdin);
    name_to_update[strcspn(name_to_update, "\n")] = 0;

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, name_to_update) == 0) {
            printf("Enter new phone number: ");
            fgets(contacts[i].phone, PHONE_LENGTH, stdin);
            contacts[i].phone[strcspn(contacts[i].phone, "\n")] = 0;
            save_contacts();  // Save to file after update
            printf("Contact updated successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

// Search contact by name
void search_contact() {
    char name_to_search[NAME_LENGTH];
    printf("Enter name to search: ");
    getchar();  // to consume the newline
    fgets(name_to_search, NAME_LENGTH, stdin);
    name_to_search[strcspn(name_to_search, "\n")] = 0;

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, name_to_search) == 0) {
            printf("Contact found successfully!\n");
            printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

// Sort contacts by name or phone number
void sort_contacts() {
    int choice;
    printf("Sort by: 1. Name 2. Phone Number: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Sort by name
        for (int i = 0; i < contact_count - 1; i++) {
            for (int j = i + 1; j < contact_count; j++) {
                if (strcmp(contacts[i].name, contacts[j].name) > 0) {
                    Contact temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
            }
        }
    } else if (choice == 2) {
        // Sort by phone number
        for (int i = 0; i < contact_count - 1; i++) {
            for (int j = i + 1; j < contact_count; j++) {
                if (strcmp(contacts[i].phone, contacts[j].phone) > 0) {
                    Contact temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
            }
        }
    }
    save_contacts();  // Save to file after sorting
    printf("Contacts sorted successfully!\n");
}

// Show all contacts
void show_contacts() {
    if (contact_count == 0) {
        printf("No contacts available!\n");
        return;
    }
    printf("Contacts List:\n");
    for (int i = 0; i < contact_count; i++) {
        printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
    }
}

// Show call history (displaying the number of calls made to each contact)
void show_call_history() {
    int any_calls = 0;  // Flag to track if any calls were made

    printf("Recent Call History:\n");
    for (int i = 0; i < contact_count; i++) {
        if (contacts[i].call_count > 0) {
            printf("%s: Called %d time(s)\n", contacts[i].name, contacts[i].call_count);
            any_calls = 1;
        }
    }

    if (!any_calls) {
        printf("No Recent Calls found.\n");
    }
}

// Quick dial (simulate a quick dial functionality)
void quick_dial() {
    char name_to_dial[NAME_LENGTH];
    printf("Enter name to quick dial: ");
    getchar();  // to consume the newline
    fgets(name_to_dial, NAME_LENGTH, stdin);
    name_to_dial[strcspn(name_to_dial, "\n")] = 0;

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, name_to_dial) == 0) {
            printf("Dialing %s... %s\n", contacts[i].name, contacts[i].phone);
            contacts[i].call_count++;  // Increment the call count for this contact
            return;
        }
    }
    printf("Contact not found!\n");
}

// Display recent call list
void recent_call_list() {
    int any_calls = 0;
    printf("Recent Calls:\n");
    for (int i = 0; i < contact_count; i++) {
        if (contacts[i].call_count > 0) {
            printf("Dialed %s %d time(s)\n", contacts[i].name, contacts[i].call_count);
            any_calls = 1;
        }
    }

    if (!any_calls) {
        printf("No Recent Calls found.\n");
    }
}

// Function to print the menu
void print_menu() {
    printf("\n");
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("x                               PHONEBOOK MANAGEMENT                        x\n");
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("x                               1. Add Contact                              x\n");
    printf("x                               2. Delete Contact                           x\n");
    printf("x                               3. Update Contact                           x\n");
    printf("x                               4. Search Contact                           x\n");
    printf("x                               5. Sort Contacts                            x\n");
    printf("x                               6. Show Contacts                            x\n");
    printf("x                               7. Show Call History                        x\n");
    printf("x                               8. Quick Dial                               x\n");
    printf("x                               9. Recent Call List                         x\n");
    printf("x                              10. Exit                                     x\n");
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
}

int main() {
    int choice;
    load_contacts(); // Load contacts at the start

    print_menu();  // Print the menu only once at the top

    do {
        printf("\nEnter your choice (0 to show menu, 10 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            print_menu();  // Show the menu again
            continue;
        }

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                delete_contact();
                break;
            case 3:
                update_contact();
                break;
            case 4:
                search_contact();
                break;
            case 5:
                sort_contacts();
                break;
            case 6:
                show_contacts();
                break;
            case 7:
                show_call_history();
                break;
            case 8:
                quick_dial();
                break;
            case 9:
                recent_call_list();
                break;
            case 10:
                save_contacts();  // Save all contacts before exiting
                printf("Exiting program... Thank you for Using This Program!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 10);

    return 0;
}
