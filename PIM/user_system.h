#ifndef USER_SYSTEM_H
#define USER_SYSTEM_H

// Save a prepared user record into the file.
int save_to_file(char file_name[], char data[]);

// Check whether a username already exists in the file.
int find_data(char file_name[], char data[]);

// Check whether both username and password match a stored record.
int find_name_and_password(
    char file_name[],
    char name[],
    char password[]);

// Print the profile for the matching username.
void view_profile(
    char file_name[],
    char name[]);

#endif
