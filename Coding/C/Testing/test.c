#include <stdio.h>
#include "test.h"

// Run through each text colour
void testColours() {
    // ANSI escape codes for text colour
    int colour;
    for (colour = 30; colour <= 37; colour++) {
        printf("\033[1;%dm", colour);
        printf("This is colour code %d.\n", colour - 30);
    }

    // Reset text colour to default
    printf("\033[0m");
    printf("Default Colour\n");
    return;
}

// Returns 1 if equal, 0 if not
int assertEquals(int x, int y) {
    int result = x == y;
    if (result) {
        printf("\033[1;32m");
        printf("Assertion Pass!\n");
    } else {
        printf("\033[1;33m");
        printf("Assertion Failed: %d != %d\n", x, y);
    }

    // Reset printf colour before returning
    printf("\033[1;0m");
    return result;
}

void printTestName(char* name) {
    printf("\033[1;30m");
    printf("Testing %s\n", name);
    printf("\033[1;0m");
}
