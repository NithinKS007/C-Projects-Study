#include <stdio.h>
#include <string.h>
#include "user_system.h"

int save_to_file(char file_name[], char data[])
{
    // Open the file in append mode so a new record is added at the end.
    FILE *file = fopen(file_name, "a");

    if (file == NULL)
    {
        printf("Could not open file\n");
        return 0;
    }

    // Save the prepared "name password" text as one line in the file.
    fprintf(file, "%s\n", data);

    fclose(file);

    return 1;
}

int find_data(char file_name[], char data[])
{
    // Open the user file for reading so we can check whether the name exists.
    FILE *file = fopen(file_name, "r");

    char name[20];
    char password[20];

    if (file == NULL)
    {
        return 0;
    }

    // Each loop reads one stored username/password pair from the file.
    while (fscanf(file,
                  "%19s %19s",
                  name,
                  password) == 2)
    {
        if (strcmp(name, data) == 0)
        {
            printf("Name already exists\n");

            fclose(file);

            return 1;
        }
    }

    fclose(file);

    return 0;
}

int find_name_and_password(
    char file_name[],
    char entered_name[],
    char entered_password[]
)
{
    // Open the file and compare every stored credential pair with the input.
    FILE *file = fopen(file_name, "r");

    char name[20];
    char password[20];

    if (file == NULL)
    {
        return 0;
    }

    // strcmp returns 0 when two strings match exactly.
    while (fscanf(file,
                  "%19s %19s",
                  name,
                  password) == 2)
    {
        if (
            strcmp(name, entered_name) == 0 &&
            strcmp(password, entered_password) == 0
        )
        {
            fclose(file);

            printf("Login Successful\n");

            return 1;
        }
    }

    fclose(file);

    printf("Invalid Username or Password\n");

    return 0;
}

void view_profile(
    char file_name[],
    char entered_name[]
)
{
    // Open the user file so we can find the logged-in username.
    FILE *file = fopen(file_name, "r");

    char name[20];
    char password[20];

    if (file == NULL)
    {
        printf("Could not open file\n");
        return;
    }

    // Search for the matching record and print the username when found.
    while (fscanf(file,
                  "%19s %19s",
                  name,
                  password) == 2)
    {
        if (strcmp(name, entered_name) == 0)
        {
            printf("\n===== PROFILE =====\n");
            printf("Username : %s\n", name);

            fclose(file);

            return;
        }
    }

    fclose(file);

    printf("Profile not found\n");
}
