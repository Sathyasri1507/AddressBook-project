# Address Book Management System using C

A menu-driven command-line Address Book application developed using **C programming**. It allows users to create, list, search, edit and delete contacts. Contact details are stored in a CSV file to maintain data between program executions.

**Author:** M. Sathyasri  
**Batch:** 26022A

## Features

- Create a contact with validated name, phone number and email.
- List all contacts in a formatted table.
- Search contacts by name , phone number or email.
- Edit the name, phone number or email of an existing contact using its serial number.
- Delete a contact using its serial number.
- Automatically load contacts from `Contacts.csv` at startup.
- Save all contacts to `Contacts.csv` when choosing option 6 (Exit).
- Prevent duplicate phone numbers and email addresses during contact creation and editing.

## Project Structure

| File | Description |
|---|---|
| `main.c` | Program entry point and main menu loop |
| `addressbook.h` | Contact and AddressBook structures and function declarations |
| `functions.c` | Core logic: validation, create, list, search, edit, delete and save operations |
| `dummycontacts.c` | Contains `load_contact()` to load contacts from `Contacts.csv` at startup |
| `Contacts.csv` | Stores contact details and contact count |

## Build and Run

**Requirements:**
- GCC compiler
- Linux environment (glibc)

The program uses `__fpurge()` from `stdio_ext.h`, so it is designed to build on Linux with glibc. It will not compile on Windows/MSVC without modifications.

**Step 1: Compile the program**

```bash
gcc main.c functions.c dummycontacts.c -o addressbook
```

**Step 2: Initialize the CSV file before the first run**

If `Contacts.csv` does not exist, create it with a single line containing `0`:

```bash
echo 0 > Contacts.csv
```

**Step 3: Run the program**

```bash
./addressbook
```

**Important:** Run the program from the directory containing `Contacts.csv`, because the program uses a relative file path.

## Usage

The program displays a menu with the following options:

| Option | Operation |
|---|---|
| 1 | Create Contact |
| 2 | List Contacts |
| 3 | Search Contact |
| 4 | Edit Contact |
| 5 | Delete Contact |
| 6 | Exit |

- **Create:** Enter the contact's name, phone number and email.
- **List:** Displays all saved contacts.
- **Search:** Search using a name, phone number or email.
- **Edit:** Displays the contact list and allows editing using the serial number.
- **Delete:** Displays the contact list and allows deleting using the serial number.
- **Exit:** Saves all contact details to `Contacts.csv` before exiting.

**Note:** Changes are saved to the CSV file only when option 6 (Exit) is selected. Closing the program forcefully or terminating it through another method may result in losing unsaved changes.

## Input Validation Rules

| Field | Validation |
|---|---|
| Name | Only letters and spaces; maximum 29 characters |
| Phone Number | Exactly 10 digits; must start with 6, 7, 8 or 9 |
| Email | Exactly one `@`, text before `@`, letters between `@` and `.com`, and must end with `.com` |
| Duplicate Check | Phone numbers and email addresses must be unique |

- Invalid inputs are rejected, and the user is prompted to enter them again.
- Duplicate phone numbers and email addresses are not allowed during creation or editing.

## Data Storage Format

Contact details are stored in `Contacts.csv`.

The first line contains the total number of contacts, followed by one contact per line in this format:

```csv
2
Alice Smith,9876543210,alice@example.com
Bob Johnson,8123456789,bob@company.com
```

## Limitations

- Maximum of 100 contacts.
- Maximum name length: 29 characters.
- Maximum phone number length: 10 digits.
- Maximum email length: 29 characters.
- Search is case-sensitive.
- Only `.com` email addresses are accepted.
- A `Contacts.csv` file must be initialized before the first execution.
- Changes are saved only when the user selects Exit.

## Possible Improvements

- Handle missing CSV files automatically.
- Implement case-insensitive search.
- Support additional email domains such as `.in` and `.org`.
- Improve input buffer handling.
- Add automatic saving after every modification.

---

**Developed as a C programming project to practice structures, functions, file handling, string manipulation, input validation and modular programming.**
