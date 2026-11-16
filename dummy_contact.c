#include "addressbook.h"

// contact dummyContacts[] = {
// 	{"Prafulla", "1234567890", "john@example.com"},
// 	{"Alice Smith", "0987654321", "alice@example.com"},
// 	{"Bob Johnson", "1112223333", "bob@company.com"},
// 	{"Carol White", "4445556666", "carol@company.com"},
// 	{"David Brown", "7778889999", "david@example.com"},
// 	{"Eve Davis", "6665554444", "eve@example.com"},
// 	{"Frank Miller", "3334445555", "frank@example.com"},
// 	{"Grace Wilson", "2223334444", "grace@example.com"},
// 	{"Hannah Clark", "5556667777", "hannah@example.com"},
// 	{"Ian Lewis", "8889990000", "ian@example.com"},
// };

// void dummy_contact(Addressbook contact_details[])
// {
//     contact_details->contact_count = 0;

// 	int numDummyContacts=sizeof(dummyContacts)/sizeof(dummyContacts[0]);

// 	for (int i=0;i<numDummyContacts&& contact_details->contact_count<100;i++)
//     {
// 		contact_details->Contacts[contact_details->contact_count++]=dummyContacts[i];// copying the dummy contacts into contacts
// 	}
// }

void load_contact(Addressbook contact_details[])
{
	contact_details->contact_count = 0;// initially set the contact count to 0

	// int numDummyContacts=sizeof(dummyContacts)/sizeof(dummyContacts[0]);

	// for (int i=0;i<numDummyContacts&& contact_details->contact_count<100;i++)
    // {
	// 	contact_details->Contacts[contact_details->contact_count++]=dummyContacts[i];
	// }

    FILE *load_f;
    load_f=fopen("Contacts.csv","r");
    if(load_f==NULL)
    {
        printf("File opening is failed\n");
        return;
    }
    fscanf(load_f,"%d",&contact_details->contact_count); //reads  the contact count from the file displays in the frst line of the csv file
    //reads the saved contact from the file
    for(int i=0;i<contact_details->contact_count;i++)
    {
        fscanf(load_f," %[^,],%[^,],%s",contact_details->Contacts[i].name,
                                  contact_details->Contacts[i].phone_no,
                                  contact_details->Contacts[i].email);
    }
    fclose(load_f);
}