#include<stdio.h>
#include <stdio_ext.h>
#include "addressbook.h"

int main()
{
    
    int choice;
    //char choice; //1 -- 48  false
    Addressbook contact_details; //Contact details is a variable for udt contains all members of the structure
    //dummy_contact(&contact_details);
    load_contact(&contact_details);
    user_choice:
    printf("-------------------------------------------\n");
    printf("\t\tAddress Book\n");
    printf("-------------------------------------------\n");
    printf("\n");
    printf("1.Create Contact\n2.List Contact\n3.Search  Contact\n4.Edit Contact\n5.Delete Contact\n");
    printf("6.Exiting\n");
    printf("\n");

    printf("Enter choice : ");
    if(scanf("%d",&choice)!=1)
    {
        printf("Invalid input\n");
        __fpurge(stdin);//clears buffer from stdin
        goto user_choice;
    }
    __fpurge(stdin);
    switch(choice)
    {
            case 1:
            printf("Create Contact\n");
            create_contact(&contact_details);
            goto user_choice;
            case 2:
            printf("List contacts\n");
            list_contact(&contact_details);
            goto user_choice;
            case 3:
            printf("Search contact\n");
            search_contact(&contact_details);
            goto user_choice;
            case 4:
            printf("Edit contact\n");
            edit_contact(&contact_details);
            goto user_choice;
            case 5:
            printf("Delete Contact\n");
            delete_contact(&contact_details);
            goto user_choice;
            case 6:
            printf("Contact saved\n");
            save_contact(&contact_details);
            printf("Exiting...\n");
            break;
            default:
            printf("You Entered a Invalid Choice... Valid choice  is [1 to 6]\n");
            goto user_choice;
    }

    return 0;
}
