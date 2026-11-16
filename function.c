#include "addressbook.h"
#include<stdio.h>
#include<ctype.h>
#include<string.h>

/*Created individual functions for name and phone number and email*/
void name_validation(Addressbook [],int);
void phone_no_validation(Addressbook [],int);
void email_validation(Addressbook [],int);

void name_validation(Addressbook contact_details[],int index)
{
    index = contact_details->contact_count; // storing the current contact count in index.
    
    printf("Enter Contact Name : ");
    name_input:
    scanf(" %29[^\n]",contact_details->Contacts[index].name);
    int i=0,flag=1; // valid name 
    while(contact_details->Contacts[index].name[i] !='\0') 
    {
        if(!isalpha(contact_details->Contacts[index].name[i]) && contact_details->Contacts[index].name[i]!=' ')
        {
           flag=0;  // when it is contains not alphabet char like numbers and special characters--  invalid 
           break;
        }
        i++; 
    }
    if(flag==0)
    {
        printf("Enter valid Name ... Should Contain Alphabets Only\n");
        goto name_input; // invalid -- jumps into name_input
    }
    else
    {
        printf("%s",contact_details->Contacts[index].name);
    }
    printf("\n");

}
 /*when the number contains alphabets special charcters --> invalid then length 
 should be 10  and alsothe frst index digit should be  6,7,8,9 
 
 1.isdigit --> contains only digits ,checks character by character. if it contains non 
 digit char invalid 
 2.strlen --> calculates length  
 3.checking the first index 0th index ,it is for >6 or <9 */
void phone_no_validation(Addressbook contact_details[],int index)
{
    index = contact_details->contact_count;
    printf("Enter Phone Number : ");
    mobile_input:
    scanf("%10s",contact_details -> Contacts[index].phone_no);

    int phone=1,j=0;//valid  
    while(contact_details->Contacts[index].phone_no[j] !='\0')
    {
        if(!isdigit(contact_details->Contacts[index].phone_no[j]) || 
            strlen(contact_details->Contacts[index].phone_no)!=10 ||
             contact_details->Contacts[index].phone_no[0]<'6' || 
             contact_details->Contacts[index].phone_no[0]>'9')
        {
            phone=0; // if any one of these three of the cases true ,phone is updated into invalid
        }
        j++;
    }

    //strcmp --> compares two strings,compares char by char if it is true - > returns 0 
    int cmp_phone=1;// valid
    for(int i=0;i<contact_details->contact_count;i++)
    {
        if(strcmp(contact_details->Contacts[i].phone_no,contact_details->Contacts[index].phone_no)==0)
        {
            cmp_phone=0;// true means updating this to  invalid
            break;

        }
    }
    if(cmp_phone==0 || phone==0) // if either of this true invalid 
    {
        //printf("Mobile number should contain 10 digits and start with 6 to 9...Re-enter\n");
        printf("Invalid Number or existed number\n");
        goto mobile_input;
    }
    else
    {
        printf("%s\n",contact_details->Contacts[index].phone_no);
    }
    printf("\n");
}

void email_validation(Addressbook contact_details[],int index)
{
    index = contact_details->contact_count;

    printf("Enter Email ID: ");
    email_input:
    scanf("%29s", contact_details->Contacts[index].email);

    /*strchr -- finds the frst occurance of the charctaer, if not found returns null*/
    char *email = contact_details->Contacts[index].email;//stores the base address of the email string
    char *at = strchr(email, '@');//if it finds '@' returns address if this '@'
    char *dot = strrchr(email, '.');//checks . if finds stores . address

    int email_valid=1;//valid
    // at ,dot --> null when it is not present in the string then when address of email and at same eg @gmail.com
    //dot+2 --> checks whether at least one  character is presemt b/w @ and .com
    //strcmp --> checks whether the email ends with .com
    if (at == NULL || dot == NULL ||at == email || dot < at + 2  || strcmp(dot,".com")!=0 || strchr(at+1,'@')!=NULL)
    {
        email_valid=0;// if any one of these condition true , it will become invalid
    }
    //only letters are allowed between @ and .com
    if(email_valid==1)
    {
        for (char *p = at + 1; p < dot; p++)
        {
            if (!isalpha((unsigned char)*p))
            {
                email_valid=0;
                break;
            }
        }
    }
    for(int i=0;i<contact_details->contact_count;i++)
    {
        if(strcmp(contact_details->Contacts[i].email,contact_details->Contacts[index].email)==0)
        {
            email_valid=0; //here comparing with existed email id's yes return 0 then invalid
            break;
            
        }
    }
    if(!email_valid)
    {
        printf("Invalid email or existed email.Re-enter.\n");
        goto email_input;
    }
    else
    {
        printf("%s", contact_details->Contacts[index].email);
    }
}

void create_contact(Addressbook contact_details[])
{ 
    int index = contact_details->contact_count;
    //char new_name[30];
    if(contact_details->contact_count>=100)
    {
        printf("Addressbook is full.\n");
        return;
    }

    name_validation(contact_details,index);
    phone_no_validation(contact_details,index);
    email_validation(contact_details,index);

    printf("\nContact created Successfully\n");
    contact_details->contact_count++;
    
}

void list_contact(Addressbook contact_details[])
{
   printf("--------------------------------------------------------------\n"); 
   printf("S.No\tName\t\tContact NO\t\tEmail\n");
   printf("--------------------------------------------------------------\n");

   for(int i=0;i<contact_details->contact_count && i<100;i++) // runs contact_count times and checks whether the contact count is less than 100
   {
    printf("%d\t%s\t\t%s\t\t%s\n",i+1,contact_details->Contacts[i].name,
        contact_details->Contacts[i].phone_no,contact_details->Contacts[i].email);
   }
   printf("\n");
}

void search_contact(Addressbook contact_details[])
{
    char searchname[30]; //it is  for storing the search name ,in array
    char search_no[11]; // stores phone number
    char search_email[30];//stores email

    printf("1.By name\n2.By Phone number\n3.By E-Mail\n\n");

    int choice,found=0;
    search_choice:
    printf("Enter choice to Search a contact : ");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
        printf("\nSearch by name\n");
        printf("Enter name : ");
        scanf(" %29[^\n]",searchname);

        /*strstr --  it searches the substring in a string ,returns the address of the substring else
        returns null when the substring is not found.checks character by character.
        here , it checks the searchname with existed contcats are present in the structure.*/
        for(int i=0;i<contact_details->contact_count;i++)
        {
            if(strstr(contact_details->Contacts[i].name,searchname)!=NULL)
            {
                printf("S.NO\tName\t\tPhone Number\t\tE-mail\n");
                printf("%d\t%s\t",i+1,contact_details->Contacts[i].name);
                printf(" %s\t",contact_details->Contacts[i].phone_no);
                printf("%s\t\n",contact_details->Contacts[i].email);
                found=1;
            }
        }
    
        if(found==0)
            printf("Contact Not Found\n");
        break;

        case 2:
        printf("\nSearch by Number\n");
        printf("Enter Phone Number : ");
        scanf("%10s",search_no);

        for(int i=0;i<contact_details->contact_count;i++)
        {
            if(strcmp(contact_details->Contacts[i].phone_no,search_no)==0)
            {
                printf("S.NO\tName\t\tPhone Number\t\tE-mail\n");
                printf("%d\t%s\t",i+1,contact_details->Contacts[i].name);
                printf("%s\t",contact_details->Contacts[i].phone_no);
                printf("%s\t\n",contact_details->Contacts[i].email);
                found=1;
            }
        }
        if(found==0)
             printf("Contact Not Found\n");
        break;

        case 3:
        printf("\nSearch by E-mail\n");
        printf("Enter E-mail : ");
        scanf("%29s",search_email);
      
        for(int i=0;i<contact_details->contact_count;i++)
        {
            if(strcmp(contact_details->Contacts[i].email,search_email)==0)
            {
                printf("S.NO\tName\t\tPhone Number\t\tE-mail\n");
                printf("%d\t%s\t",i+1,contact_details->Contacts[i].name);
                printf("%s\t",contact_details->Contacts[i].phone_no);
                printf("%s\t\n",contact_details->Contacts[i].email);
                found=1;
            }
        }
        if(found==0)
            printf("Contact Not Found\n");
        break;

        default:
        printf("Invalid choice\n");
    }  
}

void edit_contact(Addressbook contact_details[])
{
    int count = contact_details->contact_count; 
    list_contact(contact_details);

    int sno; //serial num
    printf("Enter contact S.No to edit: ");

    if (scanf("%d", &sno) != 1) // if not succesully reads it becomes true 
    {
        printf("Invalid input.\n");
        return;
    }

    if (sno < 1 || sno > count)
    {
        printf("Invalid contact number.\n");
        return;
    }

    int edit_index = sno - 1;// getting the index 
    int choice;

    printf("\n1. Edit Name\n");
    printf("2. Edit Phone Number\n");
    printf("3. Edit Email\n");
    printf("Enter choice: ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    // validaing name ,phone ,email --> valid print else re-enter
    switch (choice)
    {
        case 1:
        {
            char new_name[30];// has gv 
            // int valid = 1;

            printf("Enter new name: ");
            edit_input:
            int valid=1;
            if (scanf(" %29[^\n]",new_name) != 1)
                return;
            //validating the name --> if valid name updated
            for (int i =0; new_name[i] != '\0'; i++)
            {
                if (!isalpha((unsigned char)new_name[i]) && new_name[i] != ' ')
                {
                    valid = 0;
                    break;
                }
            }

            if (valid)
            {
                strcpy(contact_details->Contacts[edit_index].name,new_name);
                printf("Name updated successfully.\n");
            }
            else
            {
                printf("Should contain alphabets...\n");
                goto edit_input;
            }
            // name_validation(contact_details,edit_index,new_name);
            // strcpy(contact_details->Contacts[edit_index].name,new_name);
            break;
        }

        case 2:
        {
            char new_num[11];
            //int valid=1;

            phone_input:
            int valid=1;
            printf("Enter new phone number: ");
            scanf("%10s",new_num);

            if (strlen(new_num) != 10)
            {
                valid=0;
            }
            if(new_num[0]<'6' || new_num[0]>'9')
            {
                valid=0;
            }

            for (int i = 0;new_num[i] !='\0'; i++)
            {
                if (!isdigit((unsigned char)new_num[i]))
                {
                    valid=0;
                    break;
                }
            }
            //it compares from the 1st index of the contact --> i != edit_index
            for(int i=0;i<contact_details->contact_count;i++)
            {
                if(i != edit_index && strcmp(contact_details->Contacts[i].phone_no,new_num)==0)
                {
                    valid=0;// true means updating this to  invalid
                    break;

                }
            }
            
            if (valid==1)
            {
                strcpy(contact_details->Contacts[edit_index].phone_no,new_num);
                printf("Phone number updated successfully.\n");
            }
            else
            {
                //printf("Phone number must contain exactly 10 digits and start with 6 to 9.\n");
                printf("Invalid phone number\n");
                goto phone_input;
            }
            break;
        }

        case 3:
        {
            char new_email[30];

            input:
            printf("Enter new email: ");
            if (scanf("%29s", new_email) != 1)
                return;

            char *at = strchr(new_email, '@');
            char *dot = strrchr(new_email, '.');

            int email_valid=1;
            if (at == NULL || dot == NULL ||at == new_email || dot < at + 2  || strcmp(dot,".com")!=0 || strchr(at+1,'@')!=NULL)
            {
                email_valid=0;// if any one of these condition true , it will become invalid
            
            }
             //only letters are allowed between @ and .com
            if(email_valid==1)
            {
                for (char *p = at + 1; p < dot; p++)
                {
                    if (!isalpha((unsigned char)*p))
                    {
                        email_valid=0;
                        break;
                    }
                }
            }
            for(int i=0;i<contact_details->contact_count;i++)
            {
                //compares from the begining
                if(i != edit_index && strcmp(contact_details->Contacts[i].email,new_email)==0)
                {
                    email_valid=0; //here comparing with existed email id's yes return 0 then invalid
                    break;
                    
                }
            }
            if(email_valid==1)
            {
                strcpy(contact_details->Contacts[edit_index].email,new_email);
                printf("Email updated successfully.\n");
            }
            else
            {
                printf("Invalid email...\n");
                goto input;
            }
            //email_validation(contact_details);
            break;
        }
        default:
            printf("Invalid choice.\n");
    }
}

/*reads the index by sno-1 and deletes that contact*/
void delete_contact(Addressbook contact_details[])
{
    int count = contact_details->contact_count;

    list_contact(contact_details);

    int sno;
    printf("Enter contact S.No to delete: ");
    scanf("%d", &sno);

    if (sno < 1 || sno > count)
    {
        printf("Invalid contact number.\n");
        return;
    }

    int index = sno - 1;//gets index
    for (int i = index; i < count - 1; i++)// runs contact_count times
    {
        contact_details->Contacts[i] = contact_details->Contacts[i + 1]; // here it moves i+1 contact to i means 10 th index to 9th
    }
    
    contact_details->contact_count--;// here decrementing the contact count after delete
    printf("Contact deleted successfully.\n");
}

void save_contact(Addressbook contact_details[])
{
    FILE *save_f;
    save_f=fopen("Contacts.csv","w");
    if(save_f==NULL) 
    {
        printf("File opening is failed\n");
        return;
    }
    fprintf(save_f,"%d\n",contact_details->contact_count);
    //prints the contacts from the file
    for(int i=0;i<contact_details->contact_count;i++)
    {
        fprintf(save_f,"%s,%s,%s\n",contact_details->Contacts[i].name,
                                  contact_details->Contacts[i].phone_no,
                                  contact_details->Contacts[i].email);
    }
    fclose(save_f);
}

