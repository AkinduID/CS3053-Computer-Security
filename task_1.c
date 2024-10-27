// A code that allows an attacker to cause stack smashing

#include <stdio.h>
#include <string.h>

void stack_smash_vuln(char *input) {
    char buffer[50];
    strcpy(buffer, input);
}
// The buffer array in vulnerable_function is defined to hold only 50 bytes. 
// However, strcpy(buffer, input); will copy the entire input string to buffer, regardless of its length.

// If str is longer than 50 characters, it will overflow buffer and overwrite adjacent stack memory, leading to stack smashing. 
// It can cause overwriting the return address which can lead to undefined behavior 
// It can cause overwriting the return address to the begining of a malicious code which can lead to security breaches


int main() {
    char input[100];
    printf("Enter a string: ");
    gets(input);
    stack_smash_vuln(input);
    return 0;
}