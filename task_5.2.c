// Bounds Checking - Ensures data does not exceed allocated memory.

#include <stdio.h>
#include <string.h>

void bounds_check(char *str) {
    char buffer[50];
    strncpy(buffer, str, sizeof(buffer) - 1);  // Bounds checked copy
    buffer[sizeof(buffer) - 1] = '\0';
}
