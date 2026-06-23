#ifndef CONTACT_SYSTEM_H
#define CONTACT_SYSTEM_H

void add_contact(char file_name[],char name[],char phone[]);
void view_contacts(char file_name[]);
void search_contact(char file_name[],char name[]);
void update_contact(char file_name[], char name[]);
void delete_contact(char file_name[], char name[]);

#endif
