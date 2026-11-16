# AddressBook-project
AddressBook management system using C

A menu-driven command-line address book written in C. It lets you create, list, search, edit and delete
contacts, and saves them to a CSV file so they persist between runs.
Author: M. Sathyasri
Batch: 26022A
Features
• Create a contact with validated name, phone number and email
• List all contacts in a formatted table
• Search by name (partial match), phone number or email
• Edit the name, phone number or email of any contact chosen by serial number
• Delete a contact chosen by serial number
• Choosing 6. Exiting saves all contacts to Contacts.csv
• Contacts are loaded automatically from Contacts.csv at start-up
• Duplicate phone numbers and emails are rejected on create and edit
Project Structure
File
Purpose
main.c
addressbook.h
Program entry point and the main menu loop
contact and Addressbook structures and all function declarations
functions.c
Core logic: validation, create, list, search, edit, delete, save
dummycontacts.c
load_contact(): reads Contacts.csv at start-up (dummy-contact loader is
commented out)
Contacts.csv
Build and Run
Saved contact data (created/overwritten on Exiting)
Requires a C compiler such as gcc. The program uses __fpurge() from stdio_ext.h, so it builds on
Linux (glibc) but not on Windows/MSVC without changes.
gcc main.c functions.c dummycontacts.c -o addressbook
./addressbook
Run the program from the folder that contains Contacts.csv, since the file is read and written using a
relative path.
First run: if Contacts.csv does not exist, the program prints File opening is failed and will then crash. Before
the first run, create the file with a single line containing 0:
echo 0 > Contacts.csv
Usage
The menu offers: 1 Create, 2 List, 3 Search, 4 Edit, 5 Delete, 6 Exiting. Search by name, phone number or
email. Edit and Delete first list all contacts; enter the S.No of the contact to act on.
Important: Changes are only written to disk when you choose 6. Exiting. Closing the program any other way
will lose unsaved changes.
Address Book (C) - README | Page 1
Input Validation Rules
Field
Rules
Name
Phone
Letters and spaces only; up to 29 characters
Exactly one @ with text before it; only letters between @ and .com; must end with .com;
unique across contacts (create and edit); up to 29 characters
Exactly 10 digits; first digit 6, 7, 8 or 9; unique across contacts (create and edit)
Email
If an input is invalid, you are prompted to enter it again until it is valid.
Data Storage Format
Contacts are stored in Contacts.csv: first line is the contact count, then one name,phone,email line per
contact.

Alice Smith,9876543210,alice@example.com
Bob Johnson,8123456789,bob@company.com
Limits
• Maximum of 100 contacts
• Name: letters and spaces, up to 29 characters
• Phone: 10 digits starting with 6-9; unique
• Email: one @, only letters between @ and .com, ends with .com, up to 29 characters; unique
• Search is case-sensitive; data is saved only on 6. Exiting
Possible Improvements
• Handle a missing Contacts.csv and clear leftover input
• Case-insensitive search and other email domains (.in, .org)
Address Book (C) - README | Page 
