#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void AccessOutOfBounds(void) {
    int arrayLength = 10;
    int* intArray = malloc(sizeof(int) * 10);
    for (int i = 0; i < arrayLength; i++) {
        intArray[i] = 5;
    }
    free(intArray);
}

int main(void) {
    AccessOutOfBounds();

    return 0;
}