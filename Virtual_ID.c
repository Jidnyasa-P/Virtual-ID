#include <stdio.h>
#include <string.h>

#define MAX_PHONE_LENGTH 11 
#define MAX_EMAIL_LENGTH 100

// Function to compare two email addresses
int compareEmails(const char *email1, const char *email2) {
    return strcmp(email1, email2) == 0;
}

// Function to check if the phone number is 10 digits
int isValidPhoneNumber(const char phone[]) {
    if (strlen(phone) != 10) {
        return 0; 
    }
    for (int i = 0; i < 10; i++) {
        if (phone[i] < '0' || phone[i] > '9') {
            return 0;
        }
    }
    return 1; 
}

// Function to concatenate first and last name
void concatenateStrings(const char fname[], const char lname[], char fullname[]) {
    strcpy(fullname, fname);
    strcat(fullname, " "); 
    strcat(fullname, lname);
    printf("Full name: %s\n", fullname);
}

int main() {
    char fullname[200];
    char phone[MAX_PHONE_LENGTH];
    char email1[MAX_EMAIL_LENGTH];
    char email2[MAX_EMAIL_LENGTH];
    char fname[100], lname[100];
    int day, month, year;
    
    // Input first name
    printf("Enter the first name: ");
    fgets(fname, sizeof(fname), stdin);
    fname[strcspn(fname, "\n")] = 0;
    printf("Enter the last name: ");
    fgets(lname, sizeof(lname), stdin);
    lname[strcspn(lname, "\n")] = 0;
    // Concatenate strings  
    concatenateStrings(fname, lname, fullname);
    
    // Prompt user for their birthdate
    printf("Enter your birthdate:\n");
    printf("Day (1-31): ");
    scanf("%d", &day);
    printf("Month (1-12): ");
    scanf("%d", &month);
    printf("Year (e.g., 1990): ");
    scanf("%d", &year);
    printf("Your birthdate is: %d/%d/%d\n", day, month, year);
    
    // Loop until a valid phone number is entered
    do {
        printf("Enter a 10-digit phone number: ");
        scanf("%s", phone);
        if (!isValidPhoneNumber(phone)) {
            printf("Invalid phone number. Please try again.\n");
        }
    } while (!isValidPhoneNumber(phone));
    printf("Valid phone number entered: %s\n", phone);

    // Loop until the emails match
    do {
        printf("Enter your email: ");
        scanf("%s", email1);
        printf("Re-enter your email: ");
        scanf("%s", email2);
        if (!compareEmails(email1, email2)) {
            printf("Emails do not match. Please try again.\n");
        }
    } while (!compareEmails(email1, email2));
    printf("Email confirmed: %s\n", email1);
    
    // Display formatted output
    printf("\n--- VIRTUAL ID ---\n");
    printf("Full Name: %s\n", fullname);
    printf("Birthdate: %02d/%02d/%d\n", day, month, year); 
    printf("Phone Number: %s\n", phone);
    printf("Email: %s\n", email1);

    return 0;
}