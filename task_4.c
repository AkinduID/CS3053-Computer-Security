// A code that allows an attacker to execute a malicious code by exploiting a pointer variable

#include <stdio.h>
#include <string.h>

void pointer_variable_exploit(char *str) {
    char buffer[8];
    void (*fnptr)();  // Function pointer that can be overwritten
    gets(buffer);     // Vulnerable to overflow

    if (fnptr) {
        fnptr();  // Attackers could execute their code by overwriting fnptr
    }
}

int main() {
    pointer_variable_exploit("example");
    return 0;
}
