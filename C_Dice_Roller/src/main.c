#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

/**
 * Rolls a die with a specified number of sides a given number of times.
 *
 * @param sides The number of sides on the die (must be at least 1).
 * @param count How many times to roll the die (must be at least 1).
 * @param results Pointer to an array where results will be stored.
 * @return 0 on success, -1 on invalid arguments.
 */
int roll_dice(unsigned short sides, unsigned short count, unsigned short *results) {
    if (sides < 1 || count < 1 || results == NULL) {
        return -1;
    }

    for (unsigned short i = 0; i < count; i++) {
        results[i] = (unsigned short)((rand() % sides) + 1);
    }

    return 0;
}

/**
 * Helper to read an unsigned short from stdin with a default value.
 * 
 * @param prompt The prompt to display.
 * @param default_val The value to return if input is empty.
 * @param out_val Pointer to store the result.
 * @return 0 on success, -1 on invalid input or range error.
 */
int get_ushort_input(const char *prompt, unsigned short default_val, unsigned short *out_val) {
    char buffer[100];
    printf("%s", prompt);
    
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        *out_val = default_val;
        return 0;
    }

    // Remove newline
    buffer[strcspn(buffer, "\n")] = 0;

    if (strlen(buffer) == 0) {
        *out_val = default_val;
        return 0;
    }

    // Check for negative sign manually since strtoul allows it (and wraps)
    if (buffer[0] == '-') {
        return -1;
    }

    char *endptr;
    unsigned long val = strtoul(buffer, &endptr, 10);

    if (endptr == buffer || *endptr != '\0' || val > USHRT_MAX) {
        return -1; 
    }

    *out_val = (unsigned short)val;
    return 0;
}

int main() {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    printf("--- C Dice Roller ---\n");

    unsigned short sides, count;

    if (get_ushort_input("How many sides does the die have? (default 6): ", 6, &sides) != 0 || sides < 1) {
        fprintf(stderr, "Error: Invalid input. The die must have between 1 and %u sides.\n", USHRT_MAX);
        return EXIT_FAILURE;
    }

    if (get_ushort_input("How many times to roll? (default 1): ", 1, &count) != 0 || count < 1) {
        fprintf(stderr, "Error: Invalid input. You must roll between 1 and %u times.\n", USHRT_MAX);
        return EXIT_FAILURE;
    }

    unsigned short *results = malloc(sizeof(unsigned short) * count);
    if (results == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    if (roll_dice(sides, count, results) != 0) {
        fprintf(stderr, "Error: Failed to roll dice.\n");
        free(results);
        return EXIT_FAILURE;
    }

    printf("\nRolling %hud%hu...\n", count, sides);
    printf("Results: [");
    unsigned long long total = 0;
    for (unsigned short i = 0; i < count; i++) {
        printf("%hu%s", results[i], (i == count - 1) ? "" : ", ");
        total += results[i];
    }
    printf("]\n");
    printf("Total: %llu\n", total);

    free(results);
    return EXIT_SUCCESS;
}
