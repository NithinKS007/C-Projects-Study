#ifndef USER_SYSTEM_H
#define USER_SYSTEM_H

int save_to_file(char file_name[], char data[]);

int find_data(char file_name[], char data[]);

int find_name_and_password(
    char file_name[],
    char name[],
    char password[]);

void view_profile(
    char file_name[],
    char name[]);

#endif
