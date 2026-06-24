#ifndef CONTACT_SYSTEM_H
#define CONTACT_SYSTEM_H

// Add a new contact record to the given text file.
void add_contact(char file_name[],char name[],char phone[]);
// Print every contact record stored in the given text file.
void view_contacts(char file_name[]);
// Search for one contact by name in the given text file.
void search_contact(char file_name[],char name[]);
// Update the phone number for one matching contact.
void update_contact(char file_name[], char name[]);
// Delete one matching contact from the file.
void delete_contact(char file_name[], char name[]);

#endif
