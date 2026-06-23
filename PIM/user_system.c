#include <stdio.h>
#include <string.h>
#include "user_system.h"

int save_to_file(char file_name[], char data[])
{
    FILE *file = fopen(file_name, "a");

    if (file == NULL)
    {
        printf("Could not open file\n");
        return 0;
    }

    fprintf(file, "%s\n", data);

    fclose(file);

    return 1;
}

int find_data(char file_name[], char data[])
{
    FILE *file = fopen(file_name, "r");

    char name[20];
    char password[20];

    if (file == NULL)
    {
        return 0;
    }

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
    FILE *file = fopen(file_name, "r");

    char name[20];
    char password[20];

    if (file == NULL)
    {
        return 0;
    }

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
    FILE *file = fopen(file_name, "r");

    char name[20];
    char password[20];

    if (file == NULL)
    {
        printf("Could not open file\n");
        return;
    }

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
