// A code that allows an attacker to cause variables to overflow and exploit adjacent variables

#include <stdio.h>
#include <string.h>

void overflow_attack() {
    char buffer[8];
    int is_authenticated = 0;
    gets(buffer);  // Overflows buffer, allowing attacker to set `is_authenticated`
    // An input larger than 8 characters can overwrite is_authenticated, enabling unauthorized access.

    if (is_authenticated) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }
}

int main() {
    overflow_attack();
    return 0;
}

