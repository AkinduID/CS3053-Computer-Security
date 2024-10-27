// A code that allows an attacker to cause stack smashing

#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[10];
    strcpy(buffer, input);
}
// The buffer array in vulnerable_function is defined to hold only 10 bytes. 
// However, strcpy(buffer, input); will copy the entire input string to buffer, regardless of its length.

// If argv[1] is longer than 10 characters, it will overflow buffer and overwrite other stack memory, 
// potentially overwriting the return address, leading to undefined behavior 
// or allowing an attacker to control the program flow.


int main(int argc, char **argv) {
    vulnerable_function(argv[1]);
    return 0;
}