// A code that rectifies the above issues by implementing the following:
// * Canary
// * Bounds checking
// * Tagging

#include <stdio.h>
#include <string.h>

//Canary - Protects against buffer overflows by placing a "canary" value before the return address.

// Known values placed between a buffer and control data on the stack  
// When the buffer overflows, the first data to be corrupted will be the canary 
// Failed verification of the canary data causes overflow alert

void safe_func(char *str) {
    int canary = 0xDEADBEEF;
    char buffer[50];
    strcpy(buffer, str);
    if (canary != 0xDEADBEEF) {
        printf("Buffer overflow detected!\n");
        return;
    }
}

// Bounds Checking - Ensures data does not exceed allocated memory.

void bounds_check(char *str) {
    char buffer[50];
    strncpy(buffer, str, sizeof(buffer) - 1);  // Bounds checked copy
    buffer[sizeof(buffer) - 1] = '\0';
}

void tag_data(char *str) {
    char buffer[50];
    int tag = 0xABCDEF;  // Defining a tag for data integrity
    if (strlen(str) < sizeof(buffer) - sizeof(tag)) {  // Ensuring space for tag
        strncpy(buffer, str, sizeof(buffer) - sizeof(tag) - 1);  // Copying data with bounds
        buffer[sizeof(buffer) - sizeof(tag) - 1] = '\0';         // Null-terminating
        memcpy(buffer + sizeof(buffer) - sizeof(tag), &tag, sizeof(tag));  // Adding tag at end
        printf("Data tagged successfully.\n");
    } else {
        printf("String too long for tagging.\n");
    }
}

// Main function to test the above functions

int main() {
    char test_str[100] = "Hello, this is a test string.";
    
    // Testing Canary
    printf("Testing safe_func with canary protection:\n");
    safe_func(test_str);

    // Testing Bounds Checking
    printf("Testing bounds_check with safe copy:\n");
    bounds_check(test_str);

    // Testing Tagging
    printf("Testing tag_data with tagging for integrity:\n");
    tag_data(test_str);

    return 0;
}