#include <stdio.h>
#include <string.h>
#include "contact_system.h"

void add_contact(char file_name[], char name[], char phone[])
{
    // FILE *file is the handle returned by fopen; it lets us write to the file.
    // "a" means append mode, so new contacts are added to the end.
    FILE *file = fopen(file_name, "a");
    if (file == NULL)
    {
        printf("Could not open file\n");
        return;
    }
    // Save one contact as a single line: name followed by phone number.
    fprintf(file, "%s %s\n", name, phone);
    fclose(file);
}

void view_contacts(char file_name[])
{
    // Open the file in read mode so every stored contact can be printed.
    FILE *file = fopen(file_name, "r");
    char line[200];

    if (file == NULL)
    {
        printf("Could not open file\n");
        return;
    }

    printf("\n===== CONTACTS =====\n");

    // fgets reads one full line at a time until the end of the file.
    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);
}

void search_contact(char file_name[], char name[])
{
    // Read each stored contact and compare the name field with the input.
    FILE *file = fopen(file_name, "r");
    char stored_name[20];
    char phone[20];
    int found = 0;

    if (file == NULL)
    {
        printf("Could not open file\n");
        return;
    }

    // fscanf stores the file text into the two local buffers here.
    while (fscanf(file, "%19s %19s", stored_name, phone) == 2)
    {
        if (strcmp(stored_name, name) == 0)
        {
            printf("Name found: %s\n", stored_name);
            printf("Phone: %s\n", phone);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Contact not found\n");
    }

    fclose(file);
}

void update_contact(char file_name[], char name[])
{
    // The temp file is used so the original file can be rewritten safely.
    FILE *file = fopen(file_name, "r");
    FILE *temp_file = fopen("contacts_temp.txt", "w");
    char stored_name[20];
    char phone[20];
    char new_phone[20];
    int found = 0;

    if (file == NULL || temp_file == NULL)
    {
        printf("Could not open file\n");

        if (file != NULL)
        {
            fclose(file);
        }

        if (temp_file != NULL)
        {
            fclose(temp_file);
        }

        return;
    }

    printf("Enter New Contact Number: ");
    scanf("%19s", new_phone);

    // Copy every record into the temp file, changing only the matching contact.
    while (fscanf(file, "%19s %19s", stored_name, phone) == 2)
    {
        if (strcmp(stored_name, name) == 0)
        {
            fprintf(temp_file, "%s %s\n", stored_name, new_phone);
            found = 1;
        }
        else
        {
            fprintf(temp_file, "%s %s\n", stored_name, phone);
        }
    }

    fclose(file);
    fclose(temp_file);

    // Replace the old file with the updated version.
    remove(file_name);
    rename("contacts_temp.txt", file_name);

    if (found)
    {
        printf("Contact Updated\n");
    }
    else
    {
        printf("Contact Not Found\n");
    }
}

void delete_contact(char file_name[], char name[])
{
    // Use the same temp-file pattern as update_contact, but skip the match.
    FILE *file = fopen(file_name, "r");
    FILE *temp_file = fopen("contacts_temp.txt", "w");
    char stored_name[20];
    char phone[20];
    int found = 0;

    if (file == NULL || temp_file == NULL)
    {
        printf("Could not open file\n");

        if (file != NULL)
        {
            fclose(file);
        }

        if (temp_file != NULL)
        {
            fclose(temp_file);
        }

        return;
    }

    // Copy all contacts except the one that should be removed.
    while (fscanf(file, "%19s %19s", stored_name, phone) == 2)
    {
        if (strcmp(stored_name, name) == 0)
        {
            found = 1;
            continue;
        }

        fprintf(temp_file, "%s %s\n", stored_name, phone);
    }

    fclose(file);
    fclose(temp_file);

    // Swap the temporary file into place after rewriting is finished.
    remove(file_name);
    rename("contacts_temp.txt", file_name);

    if (found)
    {
        printf("Contact Deleted\n");
    }
    else
    {
        printf("Contact Not Found\n");
    }
}
