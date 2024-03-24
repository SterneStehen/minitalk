#include <stdio.h>
#include <stdlib.h>

void cleanup() {
    printf("Cleaning up!\n");
}

int main() {
    if (atexit(cleanup)) {
        fprintf(stderr, "atexit failed to register cleanup function\n");
        return 1;
    }

    printf("Exiting program...\n");
    return 0;
}