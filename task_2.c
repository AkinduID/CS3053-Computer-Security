// A code that does not perform range checking

#include <stdio.h>

void no_range_check() {
    int array[5];

    // Out-of-bounds access (no range checking)
    //  The loop accesses array outside its allocated range, potentially corrupting memory.
    for (int i = 0; i <= 10; i++) {
        array[i] = i*2;
    }
}

int main() {
    no_range_check() ;
    return 0;
}
