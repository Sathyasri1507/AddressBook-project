/*NAME : M.SATHYASRI
  BATCH:26022A
*/
#include<stdio.h>
typedef struct {
    char name[30];
    char phone_no[11];
    char email[30];
}contact; // data type of the structure

typedef struct 
{
    contact Contacts[100]; //Contacts contain name,phone no,email and datatype of the Contacts is contact
    int contact_count;
}Addressbook; // --> user  defined data type

void create_contact(Addressbook []);
void list_contact(Addressbook []);
void search_contact(Addressbook []);
void edit_contact(Addressbook []);
void delete_contact(Addressbook []);
//void dummy_contact(Addressbook []);
void load_contact(Addressbook []);
void save_contact(Addressbook[]);


