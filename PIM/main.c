#include <stdio.h>
#include <string.h>
#include "user_system.h"
#include "contact_system.h"

int main()
{
    // Menu variables store the user's current choice at each screen.
    int main_menu_choice;
    int user_menu_choice;
    int dashboard_choice;
    int contact_menu_choice;

    // Fixed-size buffers keep the code simple and avoid dynamic allocation.
    char name[20];
    char password[10];
    char data[100];

    // Small structure used to hold one contact record in memory.
    struct Contact
    {
        char name[20];
        char phone[20];
    };

    // Top-level loop keeps the program running until the user chooses Exit.
    while (1)
    {
        printf("\n===== PERSONAL INFORMATION MANAGER =====\n");
        printf("1. User System\n");
        printf("2. Contact Management\n");
        printf("3. Exit\n");
        printf("Enter Choice: ");

        scanf("%d", &main_menu_choice);

        switch (main_menu_choice)
        {
        case 1:

            // User menu for registration, login, and returning to the main menu.
            while (1)
            {
                printf("\n===== USER SYSTEM =====\n");
                printf("1. Register\n");
                printf("2. Login\n");
                printf("3. Back\n");
                printf("Enter Choice: ");

                scanf("%d", &user_menu_choice);

                if (user_menu_choice == 3)
                {
                    break;
                }

                switch (user_menu_choice)
                {
                case 1:

                    // Registration writes a new username/password pair to users.txt.
                    printf("\nRegistration\n");

                    printf("Enter Username: ");
                    scanf("%19s", name);

                    printf("Enter Password: ");
                    scanf("%9s", password);

                    if (find_data("users.txt", name))
                    {
                        // Stop if the username already exists in the file.
                        break;
                    }

                    // Combine the username and password into one text record.
                    sprintf(data, "%s %s", name, password);

                    if (save_to_file("users.txt", data))
                    {
                        printf("Registration Successful\n");
                    }

                    break;

                case 2:

                    // Login checks that both fields match a stored user record.
                    printf("\nLogin\n");

                    printf("Enter Username: ");
                    scanf("%19s", name);

                    printf("Enter Password: ");
                    scanf("%9s", password);

                    if (find_name_and_password(
                            "users.txt",
                            name,
                            password))
                    {
                        // Dashboard stays open after login until the user logs out.
                        while (1)
                        {
                            printf("\n===== DASHBOARD =====\n");
                            printf("Welcome %s\n", name);

                            printf("1. View Profile\n");
                            printf("2. Logout\n");
                            printf("Enter Choice: ");

                            scanf("%d", &dashboard_choice);

                            switch (dashboard_choice)
                            {
                            case 1:

                                // Show the profile tied to the logged-in username.
                                view_profile(
                                    "users.txt",
                                    name);

                                break;

                            case 2:

                                printf("Logout Successful\n");

                                // Leave the dashboard and return to the user menu.
                                goto dashboard_exit;

                            default:

                                printf("Invalid Choice\n");
                            }
                        }

                    dashboard_exit:;
                    }

                    break;

                default:

                    printf("Invalid Choice\n");
                }
            }

            break;

        case 2:
        {
            // One local contact object is reused for add/search/update/delete.
            struct Contact contact;

            // Contact menu loop keeps showing options until the user goes back.
            while (1)
            {
                printf("\n===== CONTACT MANAGER =====\n");
                printf("1. Add Contact\n2. View Contacts\n3. Search Contact\n4. Update Contact\n5. Delete Contact\n6. Back\n");
                scanf("%d", &contact_menu_choice);
                switch (contact_menu_choice)
                {
                case 1:
                    // Read a contact and store it in the contacts file.
                    printf("Enter Contact Name:");
                    scanf("%19s", contact.name);
                    printf("Enter Contact Number:");
                    scanf("%19s", contact.phone);
                    add_contact("contacts.txt", contact.name, contact.phone);
                    printf("Contact Added\n");
                    break;

                case 2:
                    // Display every saved contact.
                    view_contacts("contacts.txt");
                    break;

                case 3:
                    // Look up a contact by name.
                    printf("Enter Contact Name:");
                    scanf("%19s", contact.name);
                    search_contact("contacts.txt", contact.name);
                    break;
                case 4:
                    // Replace the stored phone number for a matching contact.
                    printf("Enter Contact Name:");
                    scanf("%19s", contact.name);
                    update_contact("contacts.txt", contact.name);
                    break;
                case 5:
                    // Remove the matching contact from the file.
                    printf("Enter Contact Name:");
                    scanf("%s", contact.name);
                    delete_contact("contacts.txt", contact.name);
                    break;
                case 6:
                    break;
                default:
                    printf("Invalid Choice\n");
                    break;
                }

                if (contact_menu_choice == 6)
                {
                    break;
                }
            }

            break;
        }
        case 3:

            // End the program.
            printf("Goodbye\n");
            return 0;

        default:

            printf("Invalid Choice\n");
        }
    }

    return 0;
}
