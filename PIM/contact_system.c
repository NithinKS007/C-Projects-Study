#include <stdio.h>
#include <string.h>
#include "contact_system.h"

void add_contact(char file_name[], char name[], char phone[])
{
    FILE *file = fopen(file_name, "a"); // append mode
    if (file == NULL)
    {
        printf("Could not open file\n");
        return;
    }
    fprintf(file, "%s %s\n", name, phone);
    fclose(file);
}

void view_contacts(char file_name[])
{
    FILE *file = fopen(file_name, "r");
    char line[200];

    if (file == NULL)
    {
        printf("Could not open file\n");
        return;
    }

    printf("\n===== CONTACTS =====\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);
}

void search_contact(char file_name[], char name[])
{
    FILE *file = fopen(file_name, "r");
    char stored_name[20];
    char phone[20];
    int found = 0;

    if (file == NULL)
    {
        printf("Could not open file\n");
        return;
    }

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
