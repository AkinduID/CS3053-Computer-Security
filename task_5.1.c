//Canary - Protects against buffer overflows by placing a "canary" value before the return address.

// Known values placed between a buffer and control data on the stack  
// When the buffer overflows, the first data to be corrupted will be the canary 
// Failed verification of the canary data causes overflow alert

#include <stdio.h>
#include <string.h>

void safe_func(char *str) {
    int canary = 0xDEADBEEF;
    char buffer[50];
    strcpy(buffer, str);
    if (canary != 0xDEADBEEF) {
        printf("Buffer overflow detected!\n");
        return;
    }
}
