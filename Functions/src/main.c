#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* numbers;
    size_t count = 5;
    numbers = (int*)malloc(count * sizeof(int));
    for (size_t i = 0; i < count; i++) {
        numbers[i] = (int)((i + 1) * 10);
    }
    for (size_t j = 0; j < count; j++) {
        printf("%d ", numbers[j]);
    }
    printf("\n");
    free(numbers);
    return 0;
}
